#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <fstream>
using namespace std;
class Resource
{
public:
    static string RESOURCE_DIR;
    Resource();
    //~Resource();

    void setName(string name);
    void setID(string id);
    void setFileName(string fileName);

    //将@content 存储到由 RESOURCE_DIR 和 this._file_name所指定的文件中
    //保存成功返回 true，否则返回false
    bool save(string content);

    //从RESOURCE_DIR 和 this._file_name所指定的文件中读取内容
    //读取成功，返回文件内容；否则，返回空字符串
    string load();


    const string & getName() const;
    const string & getID() const;
    const string & getFileName() const;


protected:
    string _name;//资源名称
    string _id;//系统编号
    string _file_name;//文件名称
        //一个通用的文件格式如下（可自行设计其他的格式）
    /*
       name: 资源的名称
       id:资源的系统编号
       ########
       资源的具体内容（若有）
    */
    //调用load方法，获取上面的文件内容后，一个资源类（如图书）可以按照
    //每行的格式（key:value)读取相应的属性。

};

#endif // RESOURCE_H
