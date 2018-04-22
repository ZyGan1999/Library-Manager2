#pragma once
#ifndef PAPER_H
#define PAPER_H

#include "literature.h"


class Paper : public Literature
{
public:
    Paper(string name,string id,string filename,string content,string authors,string pubtime,string journal);
    //~Paper();

    string viewContent();//查看论文的内容；该内容应被记录在论文的文件中

    void setJournal(string journal);
    const string & getJournal();
protected:
    string _journal;

};

#endif // PAPER_H
