#include "paper.h"

Paper::Paper(string name, string id, string filename, string content, string authors, string pubtime,string journal)
{
	setName(name); save(name + '\n');
	setID(id); save(id + '\n');
	setFileName(filename);
	setAuthors(authors); save(authors + '\n');
	setPubTime(pubtime); save(pubtime + '\n');
	setJournal(journal); save(journal + '\n');
	save(content);
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
