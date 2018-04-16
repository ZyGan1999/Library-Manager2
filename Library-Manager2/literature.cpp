#include "literature.h"

/*
Literature Literature::searchLiterature(string keyWord)
{
	for (std::list<Literature>::iterator i = Llist.begin(); i != Llist.end(); ++i) {
		if (i->getName().find(keyWord, 0) != string::npos) {
			return (*i);
		}
	}
}
*/
void Literature::setAuthors(string authors)
{
	this->_authors = authors;
}

void Literature::setPubTime(string pubTime)
{
	this->_pub_time = pubTime;
}

const string & Literature::getAuthors() const
{
	return _authors;
}

const string & Literature::getPubTime() const
{
	return _pub_time;
}
