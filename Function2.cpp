#include "Function.h"
#include <iostream>
using namespace std;
void Title() {
	system("cls");
	cout << "------------------------------------------------------------------------------------------------\n";
	cout << "|					MENU							|" << endl;
	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << "|				1. Student							|" << endl;
	cout << "|				2. Staff							|" << endl;
	cout << "|				3. Contract							|" << endl;
	cout << "|				4. Bill								|" << endl;
	cout << "|				5. Room								|" << endl;
	cout << "|				6. Exit								|" << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
}
void TitleStudent() {
	cout << "------------------------------------------------------------------------------------------\n";
	cout << "|		CHUC NANG THUC HIEN CUA BANG SINH VIEN					  |\n";
	cout << "------------------------------------------------------------------------------------------\n";
	cout << "|		1. Hien thi danh sach sinh vien						  |" << endl;
	cout << "|		2. Them sinh vien							  |" << endl;
	cout << "|		3. Sua thong tin sinh vien 						  |" << endl;
	cout << "|		4. Xoa thong tin sinh vien						  |" << endl;
	cout << "|		5. Exit									  |" << endl;
	cout << "------------------------------------------------------------------------------------------" << endl;
}

void Function::ChucNang(StudentAccess& s) {
	Title();
	int choose;
	cout << "Nhap lua chon cua ban : ";
	cin >> choose;
	system("cls");
	cout << "\n\n";
	s.Init();
	switch (choose) {

	case 1: {
		int action;
		do {
			system("cls");
			TitleStudent();
			cout << "Nhap chuc nang ban muon thuc hien  : ";
			cin >> action;
			
			s.Init();

			switch (action) {
			case 1: {
				cout << "Ban dang chon thuc hien chuc nang hien thi danh sach sinh vien ! \n";

				s.Show();
				system("pause");
				break;
			}
			case 2: {
				cout << "Ban dang chon thuc hien chuc nang them sinh vien : ";
				s.Insert();
				system("pause");
				break;
			}
			case 3: {
				cout << "Ban dang thuc hien chuc nang sua thong tin sinh vien. "<<endl;
				s.Update();
				system("pause");
				break;
			}
			case 4: {
				cout << "Ban dang chon thuc hien chuc nang xoa sinh vien \n ";
				s.Delete();
				system("pause");
				break;
			}
			case 5: {
				cout << "Ban dang chon thuc hien chuc nang thoat chuc nang!\n";
				break;
			}
			default: {
				cout << "Khong co chuc nang nay !\n";
				break;
			}

			}
		} while (action != 5);

		break;
	}

	case 2: {
		cout << "Ban da lua chon Staff " << endl;

		break;
	}
	
	case 3: {
		cout << "Ban da lua chon Contract " << endl;
		break;
	}
	case 4: {
		cout << "Ban da lua chon Bill " << endl;
		break;
	}
	case 5: {
		cout << "Ban da lua chon Room " << endl;
		break;
	}
	case 6: {
		cout << "Ban da lua chon thoat chuong trinh " << endl;
		break;
	}
	default:{
		cout << "Khong co chuc nang ban chon!" << endl;
		break;
	}
	}
}

