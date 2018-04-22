#include "literature.h"



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
