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
		case 1: {AddBook(); cls; break; }
		case 2: {AddPaper(); pause; cls; break; }
		case 3: {Query(); pause; cls; break; }
		case 4: {lendBook(); cls; break; }
		case 5: {backBook(); cls; break; }
		case 6: {readOnline(); pause; cls; break; }
		case 7: {SaveItAll(); Sleep(1000); return 0; }
		}
	}
    return 0;
}
