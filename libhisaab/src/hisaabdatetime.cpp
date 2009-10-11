#include "include/hisaabdatetime.h"

#include <QStringList>
#include <QString>

HisaabDateTime::HisaabDateTime() {
	dt = QDateTime::currentDateTime();
}
HisaabDateTime::HisaabDateTime(QDateTime dt)
	: dt(dt)
{}
bool HisaabDateTime::fromString(QString strNotation) {
	int d,m,y,H,M;
	QStringList dtparts = strNotation.split(QRegExp("[\\-:]"),QString::SkipEmptyParts);
	bool ok=true;
	d = dtparts.at(0).toInt(&ok);
	m = dtparts.at(1).toInt(&ok);
	y = dtparts.at(2).toInt(&ok);
	H = dtparts.at(3).toInt(&ok);
	M = dtparts.at(4).toInt(&ok);
	if( !ok ) return false;
	else dt = QDateTime( QDate(y,m,d), QTime(H,M,0,0) );
	return true;
}
QDateTime HisaabDateTime::toDateTime() {
	return dt;
}
QString HisaabDateTime::toString() {
	return dt.toString("dd-MM-yyyy-hh:mm");
}
