#ifndef TRANLOGENTRY_H
#define TRANLOGENTRY_H

#include "entry.h"

class TranlogEntry : public Entry {
public:
	TranlogEntry(float amount, QString message, QDateTime dt=QDateTime::currentDateTime() );
	bool fromString(QString strNotation);
	QString toString();
};

#endif
