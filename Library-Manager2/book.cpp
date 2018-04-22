#include "book.h"

Book::Book(string name, string id, string filename, string content , string authors ,string pubtime, string ISBN)
{//用于录入书籍的构造函数
	setFileName(filename);
	setName(name); save(name + '\n');
	setID(id); save(id + '\n');
	setAuthors(authors); save(authors + '\n');
	setPubTime(pubtime); save(pubtime + '\n');
	setISBN(ISBN); save(ISBN + '\n');
	setContent(content); save(content + '\n');
	setHoldBy(""); 
}

Book::Book(int d,string name, string id, string filename, string content, string authors, string pubtime, string ISBN)
{//用于从文件重构索引的构造函数
	setFileName(filename);
	setName(name); 
	setID(id); 
	setAuthors(authors); 
	setPubTime(pubtime); 
	setISBN(ISBN); 
	setContent(content); 
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
