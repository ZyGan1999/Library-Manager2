#include "resource.h"

Resource::Resource()
{
	RESOURCE_DIR = "c:\\Resource2\\";
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
	ofstream SaveFile(RESOURCE_DIR + _file_name + ".txt");
	if (!SaveFile) return false;

	SaveFile << content;
	return true;
}

string Resource::load()
{
	ifstream ReadFile(RESOURCE_DIR + _file_name + ".txt");
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
