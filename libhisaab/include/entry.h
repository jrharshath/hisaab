#ifndef ENTRY_H
#define ENTRY_H

#include "hastags.h"
#include "hisaabdatetime.h"
#include <QDateTime>

class Entry : public HasTags {
public:
	float getAmount();
	void setAmount(float amount);

	QString getMessage();
	void setMessage(QString message);

	HisaabDateTime getDateTime();
	void setDateTime(HisaabDateTime dt);

	virtual QString toString()=0;
protected:
	float amount;
	QString message;
	HisaabDateTime dt;
};

#endif
