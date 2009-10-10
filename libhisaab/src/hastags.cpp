#include "hastags.h"
#include <QChar>

const QChar HasTags::TAG_STARTER = '~';

HasTags::HasTags() {}

void HasTags::addTag(QString tag) {
	tag = tag.trimmed();
	if( hasTag(tag) ) return;
	if( tag[0]==TAG_STARTER )
		tags.append(tag);
	else
		tags.append(TAG_STARTER+tag);
}
void HasTags::addTags(QStringList tags) {
	foreach(QString tag, tags) {
		addTag(tag);
	}
}

void HasTags::removeTag(QString tag) {
	tag = tag.trimmed();
	int index = tagIndex(tag);
	if( index==-1 ) return;
	tags.removeAt(index);
}

bool HasTags::hasTag(QString tag) {
	tag = tag.trimmed();
	return (tagIndex(tag)!=-1);
}

int HasTags::tagIndex(QString tag) {
	tag = tag.trimmed();
	int index = tags.indexOf(tag);
	if( index==-1 ) {
		if( tag[0]==TAG_STARTER ) return -1;
		return tags.indexOf( TAG_STARTER+tag );
	}
	return index;
}

QString HasTags::getJoinedTags(const QString &sep) {
	return tags.join(sep);
}
