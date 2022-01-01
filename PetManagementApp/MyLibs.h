#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <Windows.h>
using namespace std;

struct ThuCung {
	string Ma;
	string Ten;
	float TrongLuong = 0;
	float tuoi = 0;
	string mau;
};

struct Node {
	struct ThuCung data;
	Node* pNext;
};

struct List {
	Node* pHead;
	Node* pTail;
	int soluong = 0;
};

void PetMenu(int& quickCheck);
void PetMenuEnglish(int& quickcheck);
void ShowCur(bool CursorVisibility);

