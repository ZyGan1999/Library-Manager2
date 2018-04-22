#pragma once
#include<iostream>
#include"book.h"
#include"paper.h"

map<string, Literature>index;
map<string, Book>bindex;

/*将文件内容加载到索引中*/
void LoadItAll() {
	ifstream ReadName("c:\\Resource2\\list.txt");
	string curName;
	while (!ReadName.eof()) {
		getline(ReadName, curName);
		ifstream ReadFile("c:\\Resource2\\" + curName + ".txt");
		bool isBook = false;
		string line1;
		string curLine;
		getline(ReadFile, line1);
		if (line1 == curName) isBook = true;
		
		if (isBook) {//对于书籍的处理方式
			string id; string authors; string pubtime; string ISBN; string holdby; string content;
			getline(ReadFile, id); getline(ReadFile, authors); getline(ReadFile, pubtime); getline(ReadFile, ISBN);
			getline(ReadFile, content); getline(ReadFile, holdby);
			Book b(1,curName, id, curName + ".txt", content, authors, pubtime, ISBN);
			b.borrowBook(holdby);

			index[curName] = b;
			bindex[curName] = b;
		}
		else {//对于论文的处理方式
			string id; string authors; string pubtime; string journal; string content;
			getline(ReadFile, id); getline(ReadFile, authors);
			getline(ReadFile, pubtime); getline(ReadFile, journal);
			Paper p(1,curName, id, curName + ".txt", line1, authors, pubtime, journal);

			index[curName] = p;
		}
	}
}

void menu() {//主菜单
	std::cout << "请选择您要进行的操作" << std::endl;
	std::cout << "1、录入图书" << std::endl;
	std::cout << "2、录入论文" << std::endl;
	std::cout << "3、查找文献" << std::endl;
	std::cout << "4、借出图书" << std::endl;
	std::cout << "5、归还图书" << std::endl;
	std::cout << "6、在线阅读" << std::endl;
	std::cout << "7、保存退出" << std::endl;
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

	string id = "id" + ISBN;

	Book b(name, id, name + ".txt", content, authors, pubtime, ISBN);
	/*string name, string id, string filename, string content, string authors, string pubtime, string ISBN*/
	index[name] = b;
	bindex[name] = b;
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

	string id = "id" + journal + name;

	Paper p(name, id, name + ".txt", content, authors, pubtime, journal);
	/*string name,string id,string filename,string content,string authors,string pubtime,string journal*/
	index[name] = p;
}

void Query() {
	std::cout << "请输入查询的关键词" << std::endl;
	string keyword; cin >> keyword;
	
	Literature l = Literature::searchLiterature(keyword);
	if (l.getID() != "NotExsist") cout << l.getName() << ' ' << l.getAuthors() << endl;
	else cout << "未找到匹配的文献资料！" << endl;
}

void lendBook() {
	cout << "请输入借出的图书的名字" << endl;
	string name; cin >> name;
	cout << "请输入借阅读者的用户名" << endl;
	string user; cin >> user;

	bindex[name].borrowBook(user);
}

void backBook() {
	cout << "请输入归还的图书的名字" << endl;
	string name; cin >> name;
	
	bindex[name].returnBook();
}

void readOnline() {
	cout << "请输入要在线阅读的论文的名字" << endl;
	string name; cin >> name;
	cout << index[name].load() << endl;
}

/*将索引中的内容存入到文件中*/
void SaveItAll() {
	cout << "谢谢使用！再见！" << endl;

	ofstream SaveName("c:\\Resource2\\list.txt");
	bool flag = false;
	for (map<string, Literature>::iterator i = index.begin(); i != index.end(); ++i) {
		if (flag) {
			SaveName << endl;
		}
		SaveName << i->first;
		flag = true;
	}

	for (map<string, Book>::iterator i = bindex.begin(); i != bindex.end(); ++i) {
		string curName = i->first;
		ofstream SaveBook("c:\\Resource2\\" + curName + ".txt");
		SaveBook << i->first << endl << i->second.getID() << endl << i->second.getAuthors() << endl
			<< i->second.getPubTime() << endl << i->second.getISBN() << endl << i->second.getContent() << endl
			<< i->second.getHoldBy();
	}
}

Literature Literature::searchLiterature(string keyWord)
{
	map<string, Literature>::iterator i;
	for (i = index.begin(); i != index.end(); ++i) {
		if ((i->second).getName().find(keyWord) != string::npos) {
			return i->second;
		}
	}
	Literature l; l.setID("NotExsist");
	return l;
}

