#pragma once
#include<iostream>
#include"book.h"
void menu() {
	std::cout << "��ѡ����Ҫ���еĲ���" << std::endl;
	std::cout << "1��¼��ͼ��" << std::endl;
	std::cout << "2��¼������" << std::endl;
	std::cout << "3����������" << std::endl;
	std::cout << "4�����ͼ��" << std::endl;
	std::cout << "5���黹ͼ��" << std::endl;
	std::cout << "6�������Ķ�" << std::endl;
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

	string id = "1";
	Book b(name, id, name + ".txt", content, authors, pubtime, ISBN);
	/*string name, string id, string filename, string content, string authors, string pubtime, string ISBN*/
}