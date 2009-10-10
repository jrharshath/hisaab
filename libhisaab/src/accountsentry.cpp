#include "accountsentry.h"
#include "utils.h"

#include <QDateTime>

AccountsEntry::AccountsEntry(float amount, QString name, QString message, QDateTime dt) {
	setAmount(amount);
	setName(name);
	setMessage(message);
	setDateTime(dt);
}
AccountsEntry::AccountsEntry(QString fileNotation) {
	QStringList parts = fileNotation.split("\t");
	Q_ASSERT_X(parts.size()==5, "AccountsEntry::AccountsEntry(Qstring)", "Invalid file format!");

	QString dtstring = parts.at(0);
	QString amountstring = parts.at(1);
	QString name = parts.at(2);
	QString messagestring = parts.at(3);
	QString tagslist = parts.at(4);

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
	setName(name);
	setMessage(messagestring);

	QStringList tags = tagslist.split(" ");
	foreach(QString tag, tags) {
		addTag(tag);
	}
}
QString AccountsEntry::toString() {
	QString datetime = getDateTime().toString("dd-MM-yyyy-hh:mm");
	QString final = datetime+'\t'+QString::number(getAmount())+'\t'+getName()+'\t'+getMessage()+'\t'+getJoinedTags(" ")+'\n';
	return final;
}
void AccountsEntry::setName(const QString &name) { this->name = name; }
QString AccountsEntry::getName() { return name; }
