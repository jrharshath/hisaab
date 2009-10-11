#ifndef ACCOUNTSENTRY_H
#define ACCOUNTSENTRY_H

#include "entry.h"

class AccountsEntry : public Entry {
public:
	AccountsEntry();
	AccountsEntry(float amount, QString name, QString message, QDateTime dt=QDateTime::currentDateTime() );
	bool fromString(QString strNotation);

	QString getName();
	void setName(const QString& name);

	QString toString();
protected:
	QString name;
};

#endif
