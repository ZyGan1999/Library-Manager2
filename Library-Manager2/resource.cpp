#include "resource.h"

string Resource::RESOURCE_DIR = "c:\\Resource2\\";

void Resource::setContent(string content)
{
	this->content = content;
}

void Resource::setName(string name)
{
	this->_name = name;
}

void Resource::setID(string id)
{
	this->_id = id;
}

void Resource::setFileName(string fileName)
{
	this->_file_name = fileName;
}

bool Resource::save(string content)
{
	ofstream SaveFile(RESOURCE_DIR + _file_name,ios::app);
	if (!SaveFile) return false;

	SaveFile << content;
	return true;
}

string Resource::load()
{
	ifstream ReadFile(RESOURCE_DIR + _file_name);
	if (!ReadFile) return "";
	
	string _content;
	ReadFile >> _content;
	return _content;
}

const string & Resource::getName() const
{
	return this->_name;
}

const string & Resource::getID() const
{
	return this->_id;
}

const string & Resource::getFileName() const
{
	return this->_file_name;
}

const string & Resource::getContent() const
{
	return this->content;
}
