#include"book.h"
#include"literature.h"
#include"paper.h"
#include"resource.h"
#include"menu.h"
#include<Windows.h>
#define cls system("cls")
#define pause system("pause")

int main()
{
	LoadItAll();
	while (true) {
		menu();
		int choice; cin >> choice; cls;
		switch (choice) {
		case 1: {AddBook(); cls; break; }//录入书籍
		case 2: {AddPaper(); pause; cls; break; }//录入论文
		case 3: {Query(); pause; cls; break; }//查询文献
		case 4: {lendBook(); cls; break; }//借出书籍
		case 5: {backBook(); cls; break; }//归还书籍
		case 6: {readOnline(); pause; cls; break; }//在线阅读
		case 7: {SaveItAll(); Sleep(1000); return 0; }//保存退出
		}
	}
    return 0;
}
