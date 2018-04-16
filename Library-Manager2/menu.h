#pragma once
#include<iostream>
#include"book.h"
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

	string id = "1";
	Book b(name, id, name + ".txt", content, authors, pubtime, ISBN);
	/*string name, string id, string filename, string content, string authors, string pubtime, string ISBN*/
}