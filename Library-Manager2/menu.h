#pragma once
#include<iostream>
#include"book.h"
#include"paper.h"
void menu() {
	std::cout << "请选择您要进行的操作" << std::endl;
	std::cout << "1、录入图书" << std::endl;
	std::cout << "2、录入论文" << std::endl;
	std::cout << "3、查找文献" << std::endl;
	std::cout << "4、借出图书" << std::endl;
	std::cout << "5、归还图书" << std::endl;
	std::cout << "6、在线阅读" << std::endl;
}

void AddBook() {
	std::cout << "请输入书名" << std::endl;
	string name; cin >> name;
	std::cout << "请输入作者名" << std::endl;
	string authors; cin >> authors;
	std::cout << "请输入出版时间" << std::endl;
	string pubtime; cin >> pubtime;
	std::cout << "请输入ISBN编号" << std::endl;
	string ISBN; cin >> ISBN;
	std::cout << "请输入内容" << std::endl;
	string content; cin >> content;

	string id = "1";//解决一下

	Book b(name, id, name + ".txt", content, authors, pubtime, ISBN);
	/*string name, string id, string filename, string content, string authors, string pubtime, string ISBN*/
}

void AddPaper() {
	std::cout << "请输入论文名" << std::endl;
	string name; cin >> name;
	std::cout << "请输入作者名" << std::endl;
	string authors; cin >> authors;
	std::cout << "请输入出版时间" << std::endl;
	string pubtime; cin >> pubtime;
	std::cout << "请输入发表杂志名" << std::endl;
	string journal; cin >> journal;
	std::cout << "请输入内容" << std::endl;
	string content; cin >> content;

	string id = "1";//解决一下

	Paper p(name, id, name + ".txt", content, authors, pubtime, journal);
	/*string name,string id,string filename,string content,string authors,string pubtime,string journal*/
}

void Query() {
	std::cout << "请输入查询的关键词" << std::endl;
	string keyword; cin >> keyword;
	//???
}

void lendBook() {
	cout << "请输入借出的图书的ID" << endl;
	string id; cin >> id;
	//???
}

void backBook() {
	cout << "请输入归还的图书的ID" << endl;
	string id; cin >> id;
	//???
}

void readOnline() {
	cout << "请输入要在线阅读的论文的名字" << endl;
	string name; cin >> name;
	//没有用到load函数？
}