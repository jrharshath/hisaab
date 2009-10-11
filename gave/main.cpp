#include "utils.h"

#include "accountsentry.h"
#include "hisaabratio.h"

#include <QTextStream>
#include <QFile>

QTextStream out(stdout);

int main(int argc, char* argv[]) {
	QString progname = argv[0];
	if(argc < 3) {
		out << "usage: " << progname << " <amount> <person-name-without-spaces> <message with spaces>\n";
		return -1;
	}

	QString amountString, personName, message;
	QStringList tags;
	float amount;
	int argIndex=1;

	amountString = QString(argv[argIndex++]);
	bool ok=true;
	amount = amountString.toFloat(&ok);
	if( !ok ) {
		out << progname << ": amount must be number! Aborting.\n";
		return -1;
	}



	personName = QString(argv[argIndex++]);
	QStringList persons;
	QList<float> amounts;
	bool multiperson=false;
	if( personName.contains(":") ) {
		multiperson=true;
		persons = personName.split(":", QString::SkipEmptyParts);
		int numPersons = persons.size();

		QString ratioString = argv[argIndex++];
		if( ratioString.contains(":") ) {
			HisaabRatio ratio;
			ok = ratio.fromString(ratioString);
			if( !ok || ratio.numAmounts()!=numPersons ) {
				out << progname << ": ratio is invalid! Aborting.\n";
				return -1;
			}

			float total = ratio.total();
			int numRatioAmounts = ratio.numAmounts();
			for( int i=0; i<numRatioAmounts; i++ )
				amounts << (amount * ratio.at(i) / total);
		} else {
			argIndex--;
			for( int i=0; i<numPersons; i++ )
				amounts << amount/numPersons;
		}
	}

	message = readMessage(argc, argv, argIndex, HasTags::TAG_STARTER.toAscii());

	// read tags
	for( ; argIndex<argc; argIndex++ ) {
		tags << argv[argIndex];
	}

	QFile* accFile = getConfigFile("accounts");
	if( accFile==0 ) {
		out << progname << ": could not read accounts log \"~/.hisaab/accounts\"! Aborting.\n";
		return -1;
	}

	if( multiperson ) {
		int numPersons = persons.size();
		int i;
		for( i=0; i<numPersons; i++ ) {
			AccountsEntry e(amounts.at(i), persons.at(i), message);
			e.addTags(tags);
			accFile->write(e.toString().toAscii());
		}
	} else {
		AccountsEntry e(amount, personName, message);
		e.addTags(tags);
		accFile->write(e.toString().toAscii());
		accFile->close();
	}
	delete accFile;
	return 0;
}
