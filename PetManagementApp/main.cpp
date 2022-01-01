#include "MyLibs.h"

int main() {
	// Trước là màu nền
	// Sau la màu chữ
	system("COLOR 5F");
	string input;
	int key = 1;
	int count = 0;
	int quitCheck = 0;
	SetConsoleTitle(L"PetManagementSystem. Copyright by: minhtrifit");
	ShowCur(0);

	do {
		if (count != 0) {
			cout << "   //=====***=====//" << endl;
			cout << "   * Nhap sai cu phap, hay nhap lai! " << endl;
			cout << "   * Wrong input, try again! " << endl;
			cout << "   //=====***=====//" << endl;
		}
		count++;
		cout << "   1/ English: eng" << endl;
		cout << "   2/ Vietnamese: vn" << endl;
		cout << "   # Choose your language: " << endl;
		cout << "   => ";
		getline(cin, input);
		if (input == "eng") {
			PetMenuEnglish(quitCheck);
		}
		else if (input == "vn") {
			PetMenu(quitCheck);
		}
		else {
			key == 0;
		}
	} while (key == 1 && quitCheck == 0);

	system("pause");
	return 0;
}