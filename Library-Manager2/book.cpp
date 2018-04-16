#include "book.h"

Book::Book(string name, string id, string filename, string content, string authors, string pubtime, string ISBN)
{
	setName(name);
	setID(id);
	setFileName(filename);
	save(content);
	setAuthors(authors);
	setPubTime(pubtime);
	setISBN(ISBN);
	setHoldBy("");
}

void Book::borrowBook(string user)
{
	setHoldBy(user);
}

void Book::returnBook()
{
	setHoldBy("");
}

void Book::setHoldBy(string user)
{
	this->_hold_by = user;
}

void Book::setISBN(string isbn)
{
	this->_ISBN = isbn;
}

const string & Book::getISBN() const
{
	return _ISBN;
}

const string & Book::getHoldBy() const
{
	return _hold_by;
}
