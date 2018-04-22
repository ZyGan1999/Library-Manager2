#include "paper.h"

Paper::Paper(string name, string id, string filename, string content, string authors, string pubtime,string journal)
{//用于录入论文的构造函数
	
	setFileName(filename);
	setContent(content); save(content + '\n');
	setName(name);
	setID(id); save(id + '\n');
	setAuthors(authors); save(authors + '\n');
	setPubTime(pubtime); save(pubtime + '\n');
	setJournal(journal); save(journal);
	
}

Paper::Paper(int d,string name, string id, string filename, string content, string authors, string pubtime, string journal)
{//用于从文件重构索引的构造函数
	setFileName(filename);
	setContent(content); 
	setName(name);
	setID(id); 
	setAuthors(authors); 
	setPubTime(pubtime); 
	setJournal(journal); 
}

string Paper::viewContent()
{
	return load();
}

void Paper::setJournal(string journal)
{
	this->_journal = journal;
}

const string & Paper::getJournal()
{
	return _journal;
}
