#ifndef HISAABRATIO_H
#define HISAABRATIO_H

#include <QString>
#include <QList>

class HisaabRatio
{
public:
    HisaabRatio();
	bool fromString(QString strNotation);
	float total() const;
	float at(int i) const;
	int numAmounts() const;
protected:
	QList<float> ratioAmounts;
	float totalAmounts;
};

#endif // HISAABRATIO_H
