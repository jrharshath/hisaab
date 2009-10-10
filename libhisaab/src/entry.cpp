#include "entry.h"

#include <QDataStream>

float Entry::getAmount() { return amount; }
void Entry::setAmount(float amount) { this->amount = amount; }

QString Entry::getMessage() { return message; }
void Entry::setMessage(QString message) { this->message = message; }

QDateTime Entry::getDateTime() { return dt; }
void Entry::setDateTime(QDateTime dt) { this->dt = dt; }
