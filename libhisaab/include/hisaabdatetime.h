#ifndef HISAABDATETIME_H
#define HISAABDATETIME_H

#include <QDateTime>

class HisaabDateTime {
public:
	HisaabDateTime();
	HisaabDateTime(QDateTime dt);
	bool fromString(QString strNotation);
	QDateTime toDateTime();
	QString toString();
protected:
	QDateTime dt;
};

#endif // HISAABFORMATTEDDATE_H
