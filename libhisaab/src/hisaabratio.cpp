#include "include/hisaabratio.h"
#include <QStringList>
HisaabRatio::HisaabRatio() {}

bool HisaabRatio::fromString(QString strNotation) {
	QStringList ratioAmountsString = strNotation.split(":", QString::SkipEmptyParts);
	int numRatioAmounts = ratioAmountsString.size();
	int i;
	ratioAmounts.clear();
	totalAmounts = 0;
	for( i=0; i<numRatioAmounts; i++ ) {
		bool ok=true;
		float ra = ratioAmountsString.at(i).toFloat(&ok);
		if( !ok ) return false;
		ratioAmounts << ra;
		totalAmounts += ra;
	}
	return true;
}
float HisaabRatio::total() const {
	return totalAmounts;
}
float HisaabRatio::at(int i) const {
	return ratioAmounts.at(i);
}
int HisaabRatio::numAmounts() const {
	return ratioAmounts.size();
}
