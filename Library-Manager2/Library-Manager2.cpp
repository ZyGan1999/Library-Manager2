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
	while (true) {
		menu();
		int choice; cin >> choice; cls;
		switch (choice) {
		case 1: {AddBook(); cls; }
		case 2: {AddPaper(); pause; cls; }
		case 3: {Query(); cls; }
		case 4: {lendBook(); cls; }
		case 5: {backBook(); cls; }
		case 6: {readOnline(); pause; cls; }
		}
	}

    return 0;
}

