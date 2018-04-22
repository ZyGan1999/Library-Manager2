#pragma once
#ifndef BOOK_H
#define BOOK_H


#include "literature.h"

class Book : public Literature
{
public:
    Book(string name = "", string id = "", string filename = "", string content = "", string authors = "",
		string pubtime = "", string ISBN = "");
	Book(int d,string name = "", string id = "", string filename = "", string content = "", string authors = "",
		string pubtime = "", string ISBN = "");
    //~Book();

    void borrowBook(string user);//借书，记录该图书被某用户借阅
    void returnBook();//还书；记录该图书_hold_by 字段为空字符串

    void setHoldBy(string user);
    void setISBN(string isbn);
    const string & getISBN() const;
    const string & getHoldBy() const;

protected:
    string _ISBN;
    string _hold_by; //记录该图书被某个用户借阅。若未被借阅，则此项为空字符串
};

#endif // BOOK_H
