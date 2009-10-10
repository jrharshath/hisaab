#include "utils.h"
#include "tranlogentry.h"

#include <QTextStream>
#include <QStringList>
#include <QFile>

QTextStream out(stdout);

int main(int argc, char* argv[]) {
	QString progname = argv[0];
	if(argc < 3) {
		out << "usage: " << progname << " <amount> <message with spaces> [#tag1 [#tag2 [..]]]\n";
		return -1;
	}

	float amount;
	QString amountstring, message;
	QStringList tags;

	amountstring = QString(argv[1]);
	if( !isNumeric(amountstring) ) {
		out << progname << ": amount must be number!\n";
		return -1;
	}
	amount = stringToFloat(amountstring);

	int i=2; // now read in "message"
	message = readMessage(argc, argv, i, HasTags::TAG_STARTER.toAscii());

	// read tags
	for( ; i<argc; i++ ) {
		tags << argv[i];
	}

	QFile* tranlog = getConfigFile("tranlog");
	if( tranlog==0 ) {
		out << progname << ": could not read transaction log \"~/.hisaab/tranlog\"! Aborting..\n";
		return -1;
	}

	TranlogEntry e(amount, message);
	e.addTags(tags);
	tranlog->write(e.toString().toAscii());
	tranlog->close();
	delete tranlog;
	return 0;
}
