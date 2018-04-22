#pragma once
#include<iostream>
#include"book.h"
#include"paper.h"

map<string, Literature>index;
map<string, Book>bindex;

/*���ļ����ݼ��ص�������*/
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
		
		if (isBook) {//�����鼮�Ĵ���ʽ
			string id; string authors; string pubtime; string ISBN; string holdby; string content;
			getline(ReadFile, id); getline(ReadFile, authors); getline(ReadFile, pubtime); getline(ReadFile, ISBN);
			getline(ReadFile, content); getline(ReadFile, holdby);
			Book b(1,curName, id, curName + ".txt", content, authors, pubtime, ISBN);
			b.borrowBook(holdby);

			index[curName] = b;
			bindex[curName] = b;
		}
		else {//�������ĵĴ���ʽ
			string id; string authors; string pubtime; string journal; string content;
			getline(ReadFile, id); getline(ReadFile, authors);
			getline(ReadFile, pubtime); getline(ReadFile, journal);
			Paper p(1,curName, id, curName + ".txt", line1, authors, pubtime, journal);

			index[curName] = p;
		}
	}
}

void menu() {//���˵�
	std::cout << "��ѡ����Ҫ���еĲ���" << std::endl;
	std::cout << "1��¼��ͼ��" << std::endl;
	std::cout << "2��¼������" << std::endl;
	std::cout << "3����������" << std::endl;
	std::cout << "4�����ͼ��" << std::endl;
	std::cout << "5���黹ͼ��" << std::endl;
	std::cout << "6�������Ķ�" << std::endl;
	std::cout << "7�������˳�" << std::endl;
}

void AddBook() {
	std::cout << "����������" << std::endl;
	string name; cin >> name;
	std::cout << "������������" << std::endl;
	string authors; cin >> authors;
	std::cout << "���������ʱ��" << std::endl;
	string pubtime; cin >> pubtime;
	std::cout << "������ISBN���" << std::endl;
	string ISBN; cin >> ISBN;
	std::cout << "����������" << std::endl;
	string content; cin >> content;

	string id = "id" + ISBN;

	Book b(name, id, name + ".txt", content, authors, pubtime, ISBN);
	/*string name, string id, string filename, string content, string authors, string pubtime, string ISBN*/
	index[name] = b;
	bindex[name] = b;
}

void AddPaper() {
	std::cout << "������������" << std::endl;
	string name; cin >> name;
	std::cout << "������������" << std::endl;
	string authors; cin >> authors;
	std::cout << "���������ʱ��" << std::endl;
	string pubtime; cin >> pubtime;
	std::cout << "�����뷢����־��" << std::endl;
	string journal; cin >> journal;
	std::cout << "����������" << std::endl;
	string content; cin >> content;

	string id = "id" + journal + name;

	Paper p(name, id, name + ".txt", content, authors, pubtime, journal);
	/*string name,string id,string filename,string content,string authors,string pubtime,string journal*/
	index[name] = p;
}

void Query() {
	std::cout << "�������ѯ�Ĺؼ���" << std::endl;
	string keyword; cin >> keyword;
	
	Literature l = Literature::searchLiterature(keyword);
	if (l.getID() != "NotExsist") cout << l.getName() << ' ' << l.getAuthors() << endl;
	else cout << "δ�ҵ�ƥ����������ϣ�" << endl;
}

void lendBook() {
	cout << "����������ͼ�������" << endl;
	string name; cin >> name;
	cout << "��������Ķ��ߵ��û���" << endl;
	string user; cin >> user;

	bindex[name].borrowBook(user);
}

void backBook() {
	cout << "������黹��ͼ�������" << endl;
	string name; cin >> name;
	
	bindex[name].returnBook();
}

void readOnline() {
	cout << "������Ҫ�����Ķ������ĵ�����" << endl;
	string name; cin >> name;
	cout << index[name].load() << endl;
}

/*�������е����ݴ��뵽�ļ���*/
void SaveItAll() {
	cout << "ллʹ�ã��ټ���" << endl;

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

