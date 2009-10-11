#include "tranlogentry.h"
#include "utils.h"
#include "hisaabdatetime.h"

#include <QDateTime>

TranlogEntry::TranlogEntry(float amount, QString message, QDateTime dt) {
	setAmount(amount);
	setMessage(message);
	setDateTime(HisaabDateTime(dt));
}
bool TranlogEntry::fromString(QString strNotation) {
	QStringList parts = strNotation.split("\t");
	Q_ASSERT_X(parts.size()==4, "TranlogEntry::fromString(Qstring)", "Invalid file format!");


	QString dtstring = parts.at(0);
	QString amountstring = parts.at(1);
	QString messagestring = parts.at(2);
	QString tagslist = parts.at(3);

	HisaabDateTime date;
	bool ok = date.fromString(dtstring);
	if( !ok ) return false;
	setDateTime(date);

	if( !isFloat(amountstring) ) return false;
	setAmount( amountstring.toFloat() );

	setMessage(messagestring);

	QStringList tags = tagslist.split(" ");
	foreach(QString tag, tags) {
		addTag(tag);
	}
	return true;
}

QString TranlogEntry::toString() {
	QString datetime = getDateTime().toString();
	QString final = datetime+'\t'+QString::number(getAmount())+'\t'+getMessage()+'\t'+getJoinedTags(" ")+'\n';
	return final;
}
