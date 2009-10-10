#include "utils.h"
#include "accountsentry.h"

#include <QTextStream>
#include <QMap>

QTextStream out(stdout);

int main(int argc, char* argv[]) {
	QFile* accounts = getConfigFile("accounts", QIODevice::ReadOnly);
	if( accounts==0 ) {
		out << argv[0] << ": could not read accounts log \"~/.hisaab/accounts\"! Aborting..\n";
		return -1;
	}
	QMap<QString,float> summary;
	while(accounts->bytesAvailable()) {
		QString line = accounts->readLine();
		AccountsEntry e(line);
		QString name = e.getName();
		if( summary.contains(name) )
			summary[name] += e.getAmount();
		else
			summary[name] = e.getAmount();
	}
	foreach(QString name, summary.keys()) {
		out << name << '\t' << summary[name] << '\n';
	}
	Q_UNUSED(argc);
	return 0;
}
