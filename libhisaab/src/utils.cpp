#include "utils.h"

#include <QRegExp>
#include <QDir>

bool isInt(QString num) {
	bool ok=true;
	num.toInt(&ok);
	return ok;
}
bool isFloat(QString num) {
	bool ok=true;
	num.toFloat(&ok);
	return ok;
}
bool isNumeric(QString num) {
	return isInt(num) || isFloat(num);
}

QString readMessage(int argc, char* argv[], int &index, char terminator) {
	QString message = "";
	for( ; index<argc; index++ ) {
		if( terminator!='\0' && argv[index][0]==terminator ) break;
		message += ' ';
		message += argv[index];
	}
	message = message.trimmed();
	return message;
}

QFile* getConfigFile(QString filename, QIODevice::OpenMode mode) {
	QDir hisaabDir = QDir(QDir::homePath()+"/.hisaab");
	if( !hisaabDir.exists() ) {
		if( !QDir::home().mkdir(".hisaab") ) {
			return 0;
		}
	}
	QFile* confFile = new QFile(hisaabDir.absoluteFilePath(filename));
	if( !confFile->open(mode) ) {
		return 0;
	}
	return confFile;
}
