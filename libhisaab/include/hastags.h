#ifndef HASTAGS_H
#define HASTAGS_H

#include <QStringList>

class HasTags
{
public:
	static const QChar TAG_STARTER;

	QStringList getTagList();
	void addTag(QString tag);
	void addTags(QStringList tags);
	void removeTag(QString tag);

	bool hasTag(QString tag);


protected:
	int tagIndex(QString tag);
	QString getJoinedTags(const QString &sep=" ");
    HasTags();
	QStringList tags;
};

#endif // HASTAGS_H
