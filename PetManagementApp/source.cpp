#include "MyLibs.h"

// Hàm kiểm tra màu của thú cưng
bool CheckColor(string x) {
	if (x == "vang" || x == "nau" || x == "trang" || x == "den" || x == "xam") {
		return true;
	}
	else {
		return false;
	}
}

// Hàm kiểm tra mã của thú cưng
bool Check(string& x, string& y) {
	int size = x.length();
	int giong = 0;
	for (int i = 0; i < size; i++) {
		if (x[i] == y[i]) {
			giong++;
		}
	}
	if (giong == size) {
		return true; // True nếu giống
	}
	else {
		return false; // False nếu khác
	}
}

bool CheckID(List& l, ThuCung& pet, Node*& p) {
	for (Node* linhcanh = l.pHead; linhcanh != NULL; linhcanh = linhcanh->pNext) {
		/*if (linhcanh == p) {
			linhcanh = linhcanh->pNext;
		}*/
		if (Check(linhcanh->data.Ma, p->data.Ma) == true) {
			return true;
		}
	}
	return false;
}

// Hàm nhập một thú cưng
void InputOnePet(struct ThuCung& pet) {
	do {
		cin.ignore();
		if (pet.Ma.length() >= 8) {
			cout << "# Ma thu cung vuot qua 7 ki tu, hay nhap lai! " << endl;
		}
		else if (pet.Ma.length() < 7 && pet.Ma.length() > 0) {
			cout << "# Ma thu cung nho hon 7 ki tu, hay nhap lai! " << endl;
		}
		cout << "=> Nhap ma thu cung (du 7 ky tu): ";
		getline(cin, pet.Ma);
	} while (pet.Ma.length() >= 8 || pet.Ma.length() < 7);

	do {
		if (pet.Ten.length() >= 31) {
			cout << "# Ten thu cung vuot qua 30 ki tu, hay nhap lai! " << endl;
		}
		cout << "=> Nhap ten thu cung (toi da 30 ky tu): ";
		getline(cin, pet.Ten);
	} while (pet.Ten.length() >= 31);

	do {
		if (pet.TrongLuong < 0) {
			if (pet.TrongLuong = 0) {
				cout << "# Trong luong phai la so thuc duong, hay nhap lai! " << endl;
			}
			else {
				cout << "# Trong luong phai la so thuc duong, hay nhap lai! " << endl;
			}
		}
		cout << "=> Nhap trong luong thu cung (so thuc duong): ";
		cin >> pet.TrongLuong;
	} while (pet.TrongLuong <= 0);

	do {
		if (pet.tuoi < 0) {
			if (pet.tuoi = 0) {
				cout << "# Tuoi thu cung phai la so nguyen duong, hay nhap lai! " << endl;
			}
			else {
				cout << "# Tuoi thu cung phai la so nguyen duong, hay nhap lai! " << endl;
			}
		}
		else if (pet.tuoi != (int)pet.tuoi) {
			cout << "# Tuoi thu cung phai la so nguyen duong, hay nhap lai! " << endl;
		}
		cout << "=> Nhap tuoi thu cung (so nguyen duong): ";
		cin >> pet.tuoi;
	} while (pet.tuoi <= 0 || pet.tuoi != (int)pet.tuoi);

	do {
		cout << "=> Nhap mau thu cung (5 mau: vang, nau, trang, den, xam): ";
		cin >> pet.mau;
		if (CheckColor(pet.mau) == false) {
			cout << "# Sai mau, hay nhap lai! " << endl;
		}
	} while (CheckColor(pet.mau) == false);
}

// Hàm Xuất một thú cưng
void OutputOnePet(struct ThuCung pet) {
	cout << "\t   * Ma thu cung: " << pet.Ma << endl;
	cout << "\t   * Ten thu cung: " << pet.Ten << endl;
	cout << "\t   * Trong luong thu cung: " << pet.TrongLuong << " kg" << endl;
	cout << "\t   * Tuoi thu cung: " << pet.tuoi << " tuoi" << endl;
	cout << "\t   * Mau thu cung: " << pet.mau << endl;
}

// Hàm kiểm tra danh sách rỗng
int IsEmpty(List& l) {
	return(l.pHead == NULL && l.pTail == NULL);
}

// Hàm tạo node mới
Node* CreateNode(ThuCung x) {
	Node* p = NULL;
	p = new Node;
	p->data = x;
	p->pNext = NULL;
	return p;
}

// Hàm thêm node vào cuối
void InsertpTail(List& l, Node* p) {
	if (IsEmpty(l)) {
		l.pHead = l.pTail = p;
	}
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

// 1. (0.5đ) Khởi tạo cửa hàng thú cưng với số lượng thú cưng là 0.
void InitList(List& l) {
	l.pHead = NULL;
	l.pTail = NULL;
	l.soluong = 0; // Khởi tạo danh sách với số lượng thú cưng là 0
	cout << "Khoi tao thanh cong! " << endl;
}

// 2. (2.5đ) Nhập các thú cưng với tất cả các thông tin và thêm vào cửa hàng thú cưng.
void InputList(List& l, ThuCung& pet, int& n) {
	Node* p = NULL;
	bool check = true;
	for (int i = 0; i < n; i++) {
		cout << "* Nhap thu cung so " << i + 1 << " !" << endl;
		do {
			InputOnePet(pet);
			p = CreateNode(pet);
			if (i == 0) {
				l.soluong++;
				InsertpTail(l, p);
				cout << "So luong: " << l.soluong << endl;
				break;
			}
			else if (i != 0 && CheckID(l, pet, p) == false) {
				l.soluong++;
				InsertpTail(l, p);
				cout << "So luong: " << l.soluong << endl;
				break;
			}
			else if (i != 0 && CheckID(l, pet, p) == true) {
				cout << "# Vui long kiem tra ma cua thu cung ban vua nhap! " << endl;
				delete p;
				p = NULL;
			}
		} while (true);
	}
}

// 3. (0.5đ) In danh sách các thú cưng vừa nhập.
void OutputList(List& l) {
	Node* p = NULL;
	p = l.pHead;
	cout << endl;
	int k = 0;
	if (IsEmpty(l)) {
		cout << "Danh sach hien dang rong! " << endl;
	}
	cout << "   //===============###===============//" << endl;
	cout << "\t      BnB PET COMPANY " << endl;
	cout << "\t  So luong thu cung: " << l.soluong << " con" << endl;
	for (Node* i = l.pHead; i != NULL; i = i->pNext) {
		cout << "\t# Thong tin thu cung: " << k + 1 << " !" << endl;
		OutputOnePet(i->data);
		k++;
	}
	cout << "   //===============###===============//" << endl;
	cout << endl;
}

// Hàm tìm kiếm thú cưng theo mã
Node* FindByID(List& l, string& x) {
	Node* p = NULL;
	for (p = l.pHead; p != NULL; p = p->pNext) {
		if (p->data.Ma == x) {
			return p;
		}
	}
	p = NULL;
	return p;
}

int FindByID2(List& l, string& x) {
	Node* p = NULL;
	int index = 1;
	for (p = l.pHead; p != NULL; p = p->pNext) {
		if (p->data.Ma == x) {
			return index;
		}
		index++;
	}
	return index;
}

// Hàm xoá theo vị trí
void DeleteByIndex(List& l, int& index) {
	int dem = 0;
	Node* p = l.pHead;
	Node* q = NULL;
	if (index == 1) { // Trường hợp xoá đầu
		q = p;
		p = p->pNext;
		l.pHead = p;
		delete q;
		q = NULL;
	}
	else if (index == l.soluong) { // Trường hợp xoá cuối
		while (p->pNext != l.pTail) {
			p = p->pNext;
		}
		delete l.pTail;
		p->pNext = NULL;
		l.pTail = p;
	}
	else { // Trường hợp node bất kì
		while (dem != index - 1) {
			q = p;
			p = p->pNext;
			dem++;
		}
		q->pNext = p->pNext;
		delete p;
		p = NULL;
	}
}

// 4. (1.0đ) Bán thú cưng bằng cách nhập mã thú cưng.
void SellPet(List& l) {
	string x;
	Node* ketqua = NULL;
	int vitri;
	char choose;
	float cost;
	int key = 0;
	if (IsEmpty(l)) {
		cout << "Danh sach hien dang rong! " << endl;
	}
	else {
		do {
			cin.ignore();
			if (x.length() >= 8) {
				cout << "# Ma thu cung vuot qua 7 ki tu, hay nhap lai! " << endl;
			}
			else if (x.length() < 7 && x.length() > 0) {
				cout << "# Ma thu cung nho hon 7 ki tu, hay nhap lai! " << endl;
			}
			cout << "=> Nhap ma so thu cung ban muon mua (du 7 ky tu): ";
			getline(cin, x);
		} while (x.length() >= 8 || x.length() < 7);

		ketqua = FindByID(l, x);
		if (ketqua != NULL) {
			vitri = FindByID2(l, x);
			cost = 100 + (ketqua->data.TrongLuong * 2) - ketqua->data.tuoi;
		}

		if (ketqua != NULL) {
			cout << "\tThong tin thu cung ban muon mua! " << endl;
			OutputOnePet(ketqua->data);
			do {
				cout << "Gia tien thu cung: " << cost << " USD" << endl;
				cout << "STT thu cung: " << vitri << endl;
				cout << "Ban co dong y mua? [Co: y | Khong: n] " << endl;
				cout << "=> ";
				cin >> choose;
				if (choose == 'n') {
					cout << "Ban khong dong y mua! " << endl;
					break;
				}
				else if (choose == 'y') {
					cout << "Ban dong y mua! " << endl;
					cout << "Cam on ban da mua! " << endl;
					DeleteByIndex(l, vitri);
					l.soluong--;
					break;
				}
			} while (choose != 'y' || choose != 'n');


		}
		else {
			cout << "Khong tim thay thu cung can mua! " << endl;
		}
	}
}

void AddByIndex(List& l, Node* p, int& index) {
	Node* temp = NULL;
	Node* q = NULL;
	int dem = 0;
	if (l.pHead == l.pTail) { // Trường hợp 1 node thì thêm vào đầu
		p->pNext = l.pHead;
		l.pHead = p;
	}
	else if (index == 1) { // Trường hợp thêm vào đầu
		p->pNext = l.pHead;
		l.pHead = p;
	}
	else if (index == l.soluong) { // Trường hợp thêm vào cuối
		temp = l.pHead;
		while (temp->pNext != l.pTail) {
			temp = temp->pNext;
		}
		p->pNext = temp->pNext;
		temp->pNext = p;
	}
	else { // Trường hợp vị trí bất kì
		temp = l.pHead;
		while (dem != index - 2) {
			temp = temp->pNext;
			dem++;
		}
		p->pNext = temp->pNext;
		temp->pNext = p;
	}
}

// 5. (1.0đ) Thêm thú cưng vào 1 vị trí xác định trong danh sách (cho trước).
void AddPet(List& l, ThuCung& pet) {
	Node* p = NULL;
	int index = 1;
	if (IsEmpty(l)) {
		cout << "Danh sach hien dang rong! " << endl;
	}
	else {
		cout << "So luong thu cung: " << l.soluong << endl;
		cout << "Nhap thong tin cho thu cung can them: " << endl;
		InputOnePet(pet);
		do {
			if (index <= 0 || index > l.soluong) {
				cout << "# Vi tri khong hop le, hay nhap lai! " << endl;
			}
			cout << "Nhap vi tri can them: ";
			cin >> index;
		} while (index <= 0 || index > l.soluong);
		p = CreateNode(pet);
		AddByIndex(l, p, index);
		l.soluong++;
		cout << "Them thanh cong! " << endl;
	}
}

// 6. (1.0đ) Cập nhật màu lông cho thú cưng có mã số (cho trước).
void UpdateColor(List& l, ThuCung& pet) {
	string x;
	Node* ketqua = NULL;
	int vitri;
	int key = 0;
	char choose;
	if (IsEmpty(l)) {
		cout << "Danh sach hien dang rong! " << endl;
	}
	else {
		do {
			cin.ignore();
			if (x.length() >= 8) {
				cout << "# Ma thu cung vuot qua 7 ki tu, hay nhap lai! " << endl;
			}
			else if (x.length() < 7 && x.length() > 0) {
				cout << "# Ma thu cung nho hon 7 ki tu, hay nhap lai! " << endl;
			}
			cout << "=> Nhap ma so thu cung ban cap nhat (du 7 ky tu): ";
			getline(cin, x);
		} while (x.length() >= 8 || x.length() < 7);

		ketqua = FindByID(l, x);
		vitri = FindByID2(l, x);

		do {
			if (key == 1) {
				do {
					cin.ignore();
					if (x.length() >= 8) {
						cout << "# Ma thu cung vuot qua 7 ki tu, hay nhap lai! " << endl;
					}
					else if (x.length() < 7 && x.length() > 0) {
						cout << "# Ma thu cung nho hon 7 ki tu, hay nhap lai! " << endl;
					}
					cout << "=> Nhap ma so thu cung ban cap nhat (du 7 ky tu): ";
					getline(cin, x);
				} while (x.length() >= 8 || x.length() < 7);

				ketqua = FindByID(l, x);
				vitri = FindByID2(l, x);
			}
			if (ketqua != NULL) {
				cout << "\tThong tin thu cung ban muon cap nhat mau long! " << endl;
				OutputOnePet(ketqua->data);
				cout << "STT thu cung: " << vitri << endl;
				cout << "Cap nhat mau long moi! " << endl;
				do {
					cout << "=> Nhap mau thu cung (5 mau: vang, nau, trang, den, xam): ";
					cin >> ketqua->data.mau;
					if (CheckColor(ketqua->data.mau) == false) {
						cout << "# Sai mau, hay nhap lai! " << endl;
					}
				} while (CheckColor(ketqua->data.mau) == false);
				cout << "Cap nhat thanh cong! " << endl;
				break;
			}
			else {
				cout << "Khong tim thay thu cung can tim! " << endl;
				do {
					cout << "Ban co muon cap nhap lai? [Co: y | Khong: n] " << endl;
					cout << "=> ";
					cin >> choose;
					if (choose == 'n') {
						cout << "Ban chon khong tiep tuc cap nhat! " << endl;
						key = 0;
						break;
					}
					else if (choose == 'y') {
						cout << "Ban chon tiep tuc cap nhat! " << endl;
						key = 1;
						break;
					}
				} while (choose != 'y' || choose != 'n');
			}
		} while (key != 0);
	}
}

// 7. (1.0đ) Xóa tất cả thú cưng có thông tin trọng lượng lớn hơn ngưỡng k nhập vào từ bàn phím.
void DeleteByK(List& l, ThuCung& pet) {
	float weight = 0;
	Node* temp = NULL;
	Node* q = NULL;
	int dem = 0;
	if (IsEmpty(l)) {
		cout << "Danh sach hien dang rong! " << endl;
	}
	else {
		do {
			if (weight < 0) {
				if (weight = 0) {
					cout << "# Trong luong phai la so thuc duong, hay nhap lai! " << endl;
				}
				else {
					cout << "# Trong luong phai la so thuc duong, hay nhap lai! " << endl;
				}
			}
			cout << "=> Nhap trong luong thu cung (so thuc duong): ";
			cin >> weight;
		} while (weight <= 0);

		temp = l.pHead;
		while (l.pHead->data.TrongLuong > weight) {
			l.pHead = l.pHead->pNext;
		}
		while (temp->pNext != NULL) {
			if (temp->pNext->data.TrongLuong > weight) {
				temp->pNext = temp->pNext->pNext;
			}
			else {
				temp = temp->pNext;
			}
		}
		q = l.pHead;
		while (q != NULL) {
			q = q->pNext;
			dem++;
		}
		cout << "So luong thu cung bi xoa: " << l.soluong - dem << endl;
		if (dem == l.soluong) {
			cout << "Khong tim thay thu cung phu hop! " << endl;
		}
		else {
			cout << "Xoa thanh cong! " << endl;
			l.soluong = dem;
		}
	}
}

void DeleteList(List& l) {
	Node* p = NULL;
	Node* temp = NULL;
	if (IsEmpty(l)) {
		cout << "Danh sach hien dang rong! " << endl;
	}
	else {
		p = l.pHead;
		while (p) {
			temp = p;
			p = p->pNext;
			delete temp;
			temp = NULL;
		}
		l.pHead = l.pTail = NULL;
		cout << "Xoa danh sach thanh cong! " << endl;
		l.soluong = 0;
	}
}

void ShowInfor() {
	cout << "   //==================================================###==================================================//" << endl;
	cout << "\t||\t\t\t\t   THONG TIN VE PHAN MEM\t\t\t\t       ||" << endl;
	cout << "\t||     #. Ten phan mem: Phan mem quan ly thu cung\t\t                               ||" << endl;
	cout << "\t||     +. Nam hoan tat: Thang 7/2021\t\t\t\t                               ||" << endl;
	cout << "\t||     +. Ngon ngu lap trinh: C++\t\t\t\t                               ||" << endl;
	cout << "\t||     +. Do an cuoi ki mon: Ki thuat lap trinh\t\t\t                               ||" << endl;
	cout << "\t||     #. Ten tac gia: Le Minh Tri\t\t\t\t\t\t\t       ||" << endl;
	cout << "\t||     +. Khoa: Cong nghe thong tin K20\t\t\t\t                               ||" << endl;
	cout << "\t||     +. Truong dai hoc khoa hoc tu nhien - DHQG TPHCM\t\t                               ||" << endl;
	cout << "\t||     +. Them thong tin ve tac gia: linktr.ee/minhtri.fit\t                               ||" << endl;
	cout << "   //==================================================###==================================================//" << endl;
}

void ShowInforEnglish() {
	cout << "   //==================================================###==================================================//" << endl;
	cout << "\t||\t\t\t\t   INFORMATION ABOUT SYSTEM\t\t\t\t       ||" << endl;
	cout << "\t||     #. Name of app: Pet management system\t\t\t                               ||" << endl;
	cout << "\t||     +. Completed year: July/2021\t\t\t\t                               ||" << endl;
	cout << "\t||     +. Programming language: C++\t\t\t\t                               ||" << endl;
	cout << "\t||     +. Last course project: Programming Techniques\t\t                               ||" << endl;
	cout << "\t||     #. Name of author: Le Minh Tri\t\t\t\t\t\t\t       ||" << endl;
	cout << "\t||     +. Faculty: Information of technology K20\t\t                               ||" << endl;
	cout << "\t||     +. University of Science - VNU HCMC\t\t\t                               ||" << endl;
	cout << "\t||     +. More information about author: linktr.ee/minhtri.fit\t                               ||" << endl;
	cout << "   //==================================================###==================================================//" << endl;
}

void ShowMenu() {
	cout << "   //==================================================###==================================================//" << endl;
	cout << "\t||\t\t\t\t   MENU QUAN LY CUA HANG THU CUNG\t\t\t       ||" << endl;
	cout << "\t||     #. Thong tin ve phan mem.\t\t\t\t                               ||" << endl;
	cout << "\t||     0. Quit!\t\t\t\t\t\t\t\t\t\t       ||" << endl;
	cout << "\t||     1. Khoi tao cua hang thu cung voi so luong thu cung la 0.\t\t\t       ||" << endl;
	cout << "\t||     2. Nhap cac thu cung voi tat ca cac thong tin va them vao cua hang.\t\t       ||" << endl;
	cout << "\t||     3. In danh sach thu cung vua nhap.\t\t\t\t\t\t       ||" << endl;
	cout << "\t||     4. Ban thu cung bang cach nhap ma thu cung.\t\t\t\t\t       ||" << endl;
	cout << "\t||     5. Them thu cung vao vi tri k cho truoc vao danh sach.\t\t\t\t       ||" << endl;
	cout << "\t||     6. Cap nhat mau long cho thu cung theo ma so cho truoc.\t                               ||" << endl;
	cout << "\t||     7. Xoa cac thu cung co thong tin trong luong lon hon nguong k cho truoc.\t\t       ||" << endl;
	cout << "\t||     8. Xoa toan bo danh sach thu cung.\t\t\t                               ||" << endl;
	cout << "   //==================================================###==================================================//" << endl;
}

void ShowMenuEnglish() {
	cout << "   //==================================================###==================================================//" << endl;
	cout << "\t||\t\t\t\t   PET MANAGEMENT SYSTEM'S MENU\t\t\t\t       ||" << endl;
	cout << "\t||     #. About system.\t\t\t\t\t\t                               ||" << endl;
	cout << "\t||     0. Quit!\t\t\t\t\t\t\t\t\t\t       ||" << endl;
	cout << "\t||     1. Init List (Do this before using 2 to 8).\t\t\t\t\t       ||" << endl;
	cout << "\t||     2. Input pets's information into store.\t\t\t\t\t\t       ||" << endl;
	cout << "\t||     3. Output pets from store.\t\t\t\t\t\t\t       ||" << endl;
	cout << "\t||     4. Sell pet by input ID.\t\t\t\t\t\t\t\t       ||" << endl;
	cout << "\t||     5. Add pet into k index (k is input before).\t\t\t\t\t       ||" << endl;
	cout << "\t||     6. Update pet's skin color by input ID.\t\t\t                               ||" << endl;
	cout << "\t||     7. Delete pets which have weight bigger than k (k is input before).\t\t       ||" << endl;
	cout << "\t||     8. Delete list.\t\t\t\t\t\t                               ||" << endl;
	cout << "   //==================================================###==================================================//" << endl;
}

void PetMenuEnglish(int& quickcheck) {
	struct List l = {};
	struct ThuCung pet = {};
	char choose = 0;
	char a = 0;
	static bool keyinit = false;
	static bool keydelete = false;
	int n = 0;
	cout << "   Input n (amount of pets when starting): ";
	cin >> n;
	ShowMenuEnglish();
	while (true) {
		system("cls");
		ShowMenuEnglish();
		cout << "\t => Input your choose: ";
		cin >> choose;
		if (choose == '#') {
			cout << "You chose: ";
			cout << "About system! " << endl;
			ShowInforEnglish();
			system("pause");
		}
		if (choose == '0') {
			if (keydelete == true) {
				DeleteList(l);
			}
			cout << "You chose: ";
			cout << "Quit! " << endl;
			cout << "Good bye! seen you soon" << endl;
			quickcheck = 1;
			system("pause");
			break;
		}
		else if (choose == '1') {
			cout << "You chose: ";
			cout << "Init List! " << endl;
			InitList(l);
			keyinit = true;
			system("pause");
		}
		else if (choose == '2') {
			if (keyinit == false) {
				do {
					cout << "Please init list first! [y/n]" << endl;
					cout << "=> ";
					cin >> a;
					if (a == 'y') {
						InitList(l);
						keyinit = true;
					}
					if (a == 'n') {
						break;
					}
				} while (a != 'y' && a != 'n');
			}
			else {
				cout << "You chose: ";
				cout << "Input pets's information into store! " << endl;
				InputList(l, pet, n);
				keydelete = true;
				system("pause");
			}
		}
		else if (choose == '3') {
			if (keyinit == false) {
				do {
					cout << "Please init list first! [y/n]" << endl;
					cout << "=> ";
					cin >> a;
					if (a == 'y') {
						InitList(l);
						keyinit = true;
					}
					if (a == 'n') {
						break;
					}
				} while (a != 'y' && a != 'n');
			}
			else {
				cout << "You chose: ";
				cout << "Output pets from store! " << endl;
				OutputList(l);
				system("pause");
			}
		}
		else if (choose == '4') {
			if (keyinit == false) {
				do {
					cout << "Please init list first! [y/n]" << endl;
					cout << "=> ";
					cin >> a;
					if (a == 'y') {
						InitList(l);
						keyinit = true;
					}
					if (a == 'n') {
						break;
					}
				} while (a != 'y' && a != 'n');
			}
			else {
				cout << "You chose: ";
				cout << "Sell pet by input ID! " << endl;
				OutputList(l);
				SellPet(l);
				cout << "New pet list! " << endl;
				OutputList(l);
				system("pause");
			}
		}
		else if (choose == '5') {
			if (keyinit == false) {
				do {
					cout << "Please init list first! [y/n]" << endl;
					cout << "=> ";
					cin >> a;
					if (a == 'y') {
						InitList(l);
						keyinit = true;
					}
					if (a == 'n') {
						break;
					}
				} while (a != 'y' && a != 'n');
			}
			else {
				cout << "You chose: ";
				cout << "Add pet into k index (k is input before)! " << endl;
				OutputList(l);
				AddPet(l, pet);
				cout << "New pet list! " << endl;
				OutputList(l);
				system("pause");
			}
		}
		else if (choose == '6') {
			if (keyinit == false) {
				do {
					cout << "Please init list first! [y/n]" << endl;
					cout << "=> ";
					cin >> a;
					if (a == 'y') {
						InitList(l);
						keyinit = true;
					}
					if (a == 'n') {
						break;
					}
				} while (a != 'y' && a != 'n');
			}
			else {
				cout << "You chose: ";
				cout << "Update pet's skin color by input ID! " << endl;
				OutputList(l);
				UpdateColor(l, pet);
				cout << "New pet list! " << endl;
				OutputList(l);
				system("pause");
			}

		}
		else if (choose == '7') {
			if (keyinit == false) {
				do {
					cout << "Please init list first! [y/n]" << endl;
					cout << "=> ";
					cin >> a;
					if (a == 'y') {
						InitList(l);
						keyinit = true;
					}
					if (a == 'n') {
						break;
					}
				} while (a != 'y' && a != 'n');
			}
			else {
				cout << "You chose: ";
				cout << "Delete pets which have weight bigger than k (k is input before)! " << endl;
				OutputList(l);
				DeleteByK(l, pet);
				cout << "New pet list! " << endl;
				OutputList(l);
				system("pause");
			}
		}
		else if (choose == '8') {
			if (keyinit == false) {
				do {
					cout << "Please init list first! [y/n]" << endl;
					cout << "=> ";
					cin >> a;
					if (a == 'y') {
						InitList(l);
						keyinit = true;
					}
					if (a == 'n') {
						break;
					}
				} while (a != 'y' && a != 'n');
			}
			else {
				cout << "You chose: ";
				cout << "Delete list! " << endl;
				DeleteList(l);
				keydelete = false;
				system("pause");
			}
		}
	}
}

void PetMenu(int& quickcheck) {
	struct List l = {};
	struct ThuCung pet = {};
	char choose = 0;
	char a = 0;
	static bool keyinit = false;
	static bool keydelete = false;
	int n = 0;
	cout << "   Nhap n (so luong thu cung khi bat dau): ";
	cin >> n;
	ShowMenu();
	while (true) {
		system("cls");
		ShowMenu();
		cout << "\t => Nhap lua chon cua ban: ";
		cin >> choose;
		if (choose == '#') {
			cout << "Ban da chon: ";
			cout << "Hien thong tin! " << endl;
			ShowInfor();
			system("pause");
		}
		if (choose == '0') {
			if (keydelete == true) {
				DeleteList(l);
			}
			cout << "Ban da chon: ";
			cout << "Quit! " << endl;
			cout << "Tam biet! hen gap lai" << endl;
			quickcheck = 1;
			system("pause");
			break;
		}
		else if (choose == '1') {
			cout << "Ban da chon: ";
			cout << "Khoi tao cua hang thu cung! " << endl;
			InitList(l);
			keyinit = true;
			system("pause");
		}
		else if (choose == '2') {
			if (keyinit == false) {
				do {
					cout << "Hay khoi tao danh sach truoc! [y/n]" << endl;
					cout << "=> ";
					cin >> a;
					if (a == 'y') {
						InitList(l);
						keyinit = true;
					}
					if (a == 'n') {
						break;
					}
				} while (a != 'y' && a != 'n');
			}
			else {
				cout << "Ban da chon: ";
				cout << "Nhap danh sach thu cung! " << endl;
				InputList(l, pet, n);
				keydelete = true;
				system("pause");
			}
		}
		else if (choose == '3') {
			if (keyinit == false) {
				do {
					cout << "Hay khoi tao danh sach truoc! [y/n]" << endl;
					cout << "=> ";
					cin >> a;
					if (a == 'y') {
						InitList(l);
						keyinit = true;
					}
					if (a == 'n') {
						break;
					}
				} while (a != 'y' && a != 'n');
			}
			else {
				cout << "Ban da chon: ";
				cout << "In danh sach thu cung! " << endl;
				OutputList(l);
				system("pause");
			}
		}
		else if (choose == '4') {
			if (keyinit == false) {
				do {
					cout << "Hay khoi tao danh sach truoc! [y/n]" << endl;
					cout << "=> ";
					cin >> a;
					if (a == 'y') {
						InitList(l);
						keyinit = true;
					}
					if (a == 'n') {
						break;
					}
				} while (a != 'y' && a != 'n');
			}
			else {
				cout << "Ban da chon: ";
				cout << "Ban thu cung bang cach nhap ma! " << endl;
				OutputList(l);
				SellPet(l);
				cout << "Danh sach thu cung moi! " << endl;
				OutputList(l);
				system("pause");
			}
		}
		else if (choose == '5') {
			if (keyinit == false) {
				do {
					cout << "Hay khoi tao danh sach truoc! [y/n]" << endl;
					cout << "=> ";
					cin >> a;
					if (a == 'y') {
						InitList(l);
						keyinit = true;
					}
					if (a == 'n') {
						break;
					}
				} while (a != 'y' && a != 'n');
			}
			else {
				cout << "Ban da chon: ";
				cout << "Them thu cung vao vi tri k! " << endl;
				OutputList(l);
				AddPet(l, pet);
				cout << "Danh sach thu cung moi! " << endl;
				OutputList(l);
				system("pause");
			}
		}
		else if (choose == '6') {
			if (keyinit == false) {
				do {
					cout << "Hay khoi tao danh sach truoc! [y/n]" << endl;
					cout << "=> ";
					cin >> a;
					if (a == 'y') {
						InitList(l);
						keyinit = true;
					}
					if (a == 'n') {
						break;
					}
				} while (a != 'y' && a != 'n');
			}
			else {
				cout << "Ban da chon: ";
				cout << "Cap nhat mau long theo ma so! " << endl;
				OutputList(l);
				UpdateColor(l, pet);
				cout << "Danh sach thu cung moi! " << endl;
				OutputList(l);
				system("pause");
			}

		}
		else if (choose == '7') {
			if (keyinit == false) {
				do {
					cout << "Hay khoi tao danh sach truoc! [y/n]" << endl;
					cout << "=> ";
					cin >> a;
					if (a == 'y') {
						InitList(l);
						keyinit = true;
					}
					if (a == 'n') {
						break;
					}
				} while (a != 'y' && a != 'n');
			}
			else {
				cout << "Ban da chon: ";
				cout << "Xoa thu cung co trong luong lon hon nguong k! " << endl;
				OutputList(l);
				DeleteByK(l, pet);
				cout << "Danh sach thu cung moi! " << endl;
				OutputList(l);
				system("pause");
			}
		}
		else if (choose == '8') {
			if (keyinit == false) {
				do {
					cout << "Hay khoi tao danh sach truoc! [y/n]" << endl;
					cout << "=> ";
					cin >> a;
					if (a == 'y') {
						InitList(l);
						keyinit = true;
					}
					if (a == 'n') {
						break;
					}
				} while (a != 'y' && a != 'n');
			}
			else {
				cout << "Ban da chon: ";
				cout << "Xoa toan bo danh sach! " << endl;
				DeleteList(l);
				keydelete = false;
				system("pause");
			}
		}
	}
}

void ShowCur(bool CursorVisibility) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConCurInf;

	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = CursorVisibility;

	SetConsoleCursorInfo(handle, &ConCurInf);
}
