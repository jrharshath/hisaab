#ifndef HISAABUTILS_H
#define HISAABUTILS_H

#include <QString>
#include <QFile>
#include <QDateTime>

bool isNumeric(QString num);
QString readMessage(int argc, char* argv[], int &startIndex, char terminator='\0');
QFile* getConfigFile(QString filename, QIODevice::OpenMode mode=QIODevice::WriteOnly|QIODevice::Append);

int stringToInt(QString num);
float stringToFloat(QString num);

#endif
