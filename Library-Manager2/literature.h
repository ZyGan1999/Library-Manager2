#ifndef LITERATURE_H
#define LITERATURE_H
#include <string>
#include <list>
#include "resource.h"

using namespace std;

class Literature : public Resource
{
public:
    //Literature();
    //~Literature();

    //查找名称中包含关键词@keyWord的任何一个文献（可以是图书或论文）
    static Literature searchLiterature(string keyWord);


    void setAuthors(string authors);
    void setPubTime(string pubTime);

    const string & getAuthors() const;
    const string & getPubTime() const;

protected:
    string _authors;
    string _pub_time;
	static std::list<Literature> Llist;//自己加的
};

#endif // LITERATURE_H
