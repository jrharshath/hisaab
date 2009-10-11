#include "utils.h"
#include "accountsentry.h"

#include <QTextStream>
#include <QMap>

QTextStream out(stdout);

int main(int argc, char* argv[]) {
	char* progname = argv[0];
	QFile* accounts = getConfigFile("accounts", QIODevice::ReadOnly);
	if( accounts==0 ) {
		out << progname << ": could not read accounts log \"~/.hisaab/accounts\"! Aborting.\n";
		return -1;
	}
	QMap<QString,float> summary;
	bool ok=true;
	while(accounts->bytesAvailable()) {
		QString line = accounts->readLine();
		AccountsEntry e;
		ok = e.fromString(line);
		if( !ok ) {
			out << progname << ": invalid accounts log \"~/.hisaab/accounts\"! Aborting.\n";
			return -1;
		}
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
