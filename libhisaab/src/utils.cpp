#include "utils.h"

#include <QRegExp>
#include <QDir>

bool isNumeric(QString num) {
	return QRegExp("^[\\+\\-]?[0-9]+(\\.[0-9]+)?$").exactMatch(num);
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

int stringToInt(QString num) {
	num = num.trimmed();
	int len = num.size();
	int retval = 0;
	for( int i=0; i<len; i++ ) {
		char digit = num.at(i).toAscii();
		digit -= '0';
		if( digit<0 || digit>9 ) return -1;
		retval *= 10;
		retval += (int) digit;
	}
	return retval;
}

float stringToFloat(QString num) {
	num = num.trimmed();
	int len = num.size();
	float whole = 0.0;
	int i=0;

	int sign=1;
	char signdigit = num.at(0).toAscii();
	if( signdigit=='-' ) {
		sign = -1;
		i++;
	} else if( signdigit=='+' ) {
		i++;
	}

	for( ; i<len; i++ ) {
		char digit = num.at(i).toAscii();
		if( digit=='.' ) break;
		digit -= '0';
		if( digit<0 || digit>9 ) return 0;
		whole*= 10;
		whole += digit;
	}
	float fraction = 0.1;
	for( i++; i<len; i++ ) {
		char digit = num.at(i).toAscii();
		digit -= '0';
		if( digit<0 || digit>9 ) return 0;
		whole += fraction*digit;
		fraction/= 10;
	}
	return whole*sign;
}
