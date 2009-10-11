#include "accountsentry.h"

#include "hisaabdatetime.h"
#include "utils.h"

#include <QDateTime>
AccountsEntry::AccountsEntry() {
	setAmount(0);
	setName("");
	setMessage("");
}
AccountsEntry::AccountsEntry(float amount, QString name, QString message, QDateTime dt) {
	setAmount(amount);
	setName(name);
	setMessage(message);
	setDateTime(dt);
}
bool AccountsEntry::fromString(QString strNotation) {
	QStringList parts = strNotation.split("\t");
	Q_ASSERT_X(parts.size()==5, "AccountsEntry::fromString(Qstring)", "Invalid file format!");

	QString dtstring = parts.at(0);
	QString amountstring = parts.at(1);
	QString name = parts.at(2);
	QString messagestring = parts.at(3);
	QString tagslist = parts.at(4);

	HisaabDateTime date;
	bool ok = date.fromString(dtstring);
	if( !ok ) return false;
	setDateTime(date);

	if( !isFloat(amountstring) ) return false;
	setAmount( amountstring.toFloat() );
	setName(name);
	setMessage(messagestring);

	QStringList tags = tagslist.split(" ");
	foreach(QString tag, tags) {
		addTag(tag);
	}
	return true;
}
QString AccountsEntry::toString() {
	QString datetime = getDateTime().toString();
	QString final = datetime+'\t'+QString::number(getAmount())+'\t'+getName()+'\t'+getMessage()+'\t'+getJoinedTags(" ")+'\n';
	return final;
}
void AccountsEntry::setName(const QString &name) { this->name = name; }
QString AccountsEntry::getName() { return name; }
