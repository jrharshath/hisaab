#ifndef ENTRY_H
#define ENTRY_H

#include "hastags.h"
#include <QDateTime>

class Entry : public HasTags {
public:
	float getAmount();
	void setAmount(float amount);

	QString getMessage();
	void setMessage(QString message);

	QDateTime getDateTime();
	void setDateTime(QDateTime dt);

	virtual QString toString()=0;
protected:
	float amount;
	QString message;
	QDateTime dt;
};

#endif
