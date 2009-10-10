#include "tranlogentry.h"
#include "utils.h"

#include <QDateTime>

TranlogEntry::TranlogEntry(float amount, QString message, QDateTime dt) {
	setAmount(amount);
	setMessage(message);
	setDateTime(dt);
}
TranlogEntry::TranlogEntry(QString fileNotation) {
	QStringList parts = fileNotation.split("\t");

	QString dtstring = parts.at(0);
	QString amountstring = parts.at(1);
	QString messagestring = parts.at(2);
	QString tagslist = parts.at(3);

	int d,m,y,H,M;
	QStringList dtparts = dtstring.split(QRegExp("[\\-:]"),QString::SkipEmptyParts);
	d = stringToInt(dtparts.at(0));
	m = stringToInt(dtparts.at(1));
	y = stringToInt(dtparts.at(2));
	H = stringToInt(dtparts.at(3));
	M = stringToInt(dtparts.at(4));
	QDateTime localdt( QDate(y,m,d), QTime(H,M,0,0) );
	setDateTime(localdt);

	setAmount( stringToFloat(amountstring) );

	setMessage(messagestring);

	QStringList tags = tagslist.split(" ");
	foreach(QString tag, tags) {
		addTag(tag);
	}
}

QString TranlogEntry::toString() {
	QString datetime = getDateTime().toString("dd-MM-yyyy-hh:mm");
	QString final = datetime+'\t'+QString::number(getAmount())+'\t'+getMessage()+'\t'+getJoinedTags(" ")+'\n';
	return final;
}
