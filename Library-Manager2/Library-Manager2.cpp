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
		case 1: {AddBook(); }
		case 2:{}
		case 3:{}
		case 4:{}
		case 5:{}
		case 6:{}
		}
	}

    return 0;
}

