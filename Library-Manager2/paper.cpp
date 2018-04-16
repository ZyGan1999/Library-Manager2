#include "paper.h"

Paper::Paper(string name, string id, string filename, string content, string authors, string pubtime,string journal)
{
	setName(name);
	setID(id);
	setFileName(filename);
	save(content);
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
