#include "utils.h"
#include "accountsentry.h"

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

	amountString = QString(argv[1]);
	if( !isNumeric(amountString) ) {
		out << progname << ": amount must be number!\n";
		return -1;
	}
	amount = stringToFloat(amountString);

	personName = QString(argv[2]);

	int i=3;
	message = readMessage(argc, argv, i, HasTags::TAG_STARTER.toAscii());

	// read tags
	for( ; i<argc; i++ ) {
		tags << argv[i];
	}

	QFile* accFile = getConfigFile("accounts");
	if( accFile==0 ) {
		out << progname << ": could not read accounts log \"~/.hisaab/accounts\"! Aborting..\n";
		return -1;
	}

	AccountsEntry e(amount, personName, message);
	accFile->write(e.toString().toAscii());
	accFile->close();
	delete accFile;
	return 0;
}
