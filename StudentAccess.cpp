#include "StudentAccess.h"
#include "Connect.h"
#include <iostream>
#include <iomanip>
#include "Student.h"
#include <string>
using namespace std;
void StudentAccess::Select(Student*& s) {

	//output
	cout << "\n";
	cout << "Executing T-SQL query...";
	cout << "\n";

	//if there is a problem executing the query then exit application
	//else display query result
	if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle,(SQLCHAR*)L"SELECT * FROM SINHVIEN", SQL_NTS)) {
		cout << "Error querying SQL Server";
		cout << "\n";
	
	}
	else {
		//declare output variable and pointer
		SQLINTEGER ptrSqlVersion;
		char id[10];
		char name[50];
		char sex[20];
		char birth[50];

		char address[50];
		char number[50];
		int i = 0;
		while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS) {
			SQLGetData(SQLStatementHandle, 1, SQL_C_DEFAULT, &id, sizeof(id), NULL);
			SQLGetData(SQLStatementHandle, 2, SQL_C_DEFAULT, &name, sizeof(name), NULL);
			SQLGetData(SQLStatementHandle, 3, SQL_C_DEFAULT, &sex, sizeof(sex), NULL);

			SQLGetData(SQLStatementHandle, 4, SQL_C_DEFAULT, &birth, sizeof(birth), NULL);

			SQLGetData(SQLStatementHandle, 5, SQL_C_DEFAULT, &address, sizeof(address), NULL);

			SQLGetData(SQLStatementHandle, 6, SQL_C_DEFAULT, &number, sizeof(number), NULL);
			
			Student* temp = new Student(id, name,sex, birth, address, number);
			*(s + i) = *temp;
			i++;

		}
	}
	SQLCancel(SQLStatementHandle);

}
void StudentAccess::Insert() {
	string result = "INSERT INTO SINHVIEN VALUES( ";
	Student s;
	s.setStudent();
	result += s.insertQuerr();
	const char* SQLQuery = result.c_str();
	cout << SQLQuery << endl;
	//Connect c;
	//c.ExecuteDB(...);
	if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery, SQL_NTS)) {
		cout << "Loi khong the thuc hien duoc!" << endl;
		


	}
	else {
		cout << "Them Thanh Cong!" << endl;
		
	}
	SQLCancel(SQLStatementHandle);

}
void StudentAccess::Update() {
	string id;
	string name, sex,birth, address, number;
	cout<<"Nhap ma so sinh vien ban muon thay doi du lieu:  ";
	cin.ignore();
	getline(cin, id);


	


	/*string name,sex, birth, address, number;*/
	cout << "-----------------------------------------------------------------\n";
	cout << "|	1.Ho va ten						|" << endl;
	cout << "|	2.Gioi tinh						|" << endl;
	cout << "|	3.Ngay sinh						|" << endl;
	cout<<	"|	4.Que quan						|"<<endl;
	cout << "|	5.So dien thoai						|" << endl;
	cout << "------------------------------------------------------------------\n";

	int choose;
	cout << "Nhap cot du lieu ban muon update : ";
	cin >> choose;
	switch (choose) {
	case 1: {

	
		cout << "Nhap ten moi : ";
		cin.ignore();
		getline(cin, name);
		string querry = "update SINHVIEN set hoten = '" + name + "' where MSSV = '" + id + "'";
		const char* SQLQuery = querry.c_str();
		if (SQL_SUCCESS == SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery, SQL_NTS)) {
			cout << "Da cap nhat du lieu vao!" << endl;
		}
		else {

			cout << "Du lieu  cap nhat khong thanh cong !" << endl;
		}
		break;
	}

	case 2: {
		cout << "Nhap gioi tinh moi :  ";
		cin.ignore();
		getline(cin, sex);
		string querry = " update SINHVIEN set Ngaysinh = '" + sex + "' where MSSV = '" + id + "'";

		const char* SQLQuery = querry.c_str();
		if (SQL_SUCCESS == SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery, SQL_NTS)) {
			cout << "Da cap nhat du lieu vao!" << endl;
		}
		else {

			cout << "Du lieu  cap nhat thanh cong !" << endl;
		}
		break;
	}
			
	case 3: {
		cout << "Nhap ngay sinh moi : ";
		cin.ignore();
		getline(cin, birth);
		string querry = " update SINHVIEN set Diachi = " + birth + "' where MSSV = '" + id + "'";

		const char* SQLQuery = querry.c_str();
		if (SQL_SUCCESS == SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery, SQL_NTS)) {
			cout << "Da cap nhat du lieu vao!" << endl;
		}
		else {

			cout << "Du lieu  cap nhat thanh cong !" << endl;
		}
		break;
	}
	case 4: {
		cout << "Nhap que quan moi : ";
		cin.ignore();
		getline(cin, number);
		string querry = " update SINHVIEN set Sdt = " + address + "' where MSSV = '" + id + "'";

		const char* SQLQuery = querry.c_str();
		if (SQL_SUCCESS == SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery, SQL_NTS)) {
			cout << "Da cap nhat du lieu vao!" << endl;
		}
		else {

			cout << "Du lieu  cap nhat khong thanh cong !" << endl;
		}
		break;
	}
	case 5: {
		cout << "Nhap so dien thoai moi : ";
		cin.ignore();
		getline(cin, number);
		string querry = " update SINHVIEN set Sdt = " + number + "' where MSSV = '" + id + "'";

		const char* SQLQuery = querry.c_str();
		if (SQL_SUCCESS == SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery, SQL_NTS)) {
			cout << "Da cap nhat du lieu vao!" << endl;
		}
		else {

			cout << "Du lieu  cap nhat khong thanh cong !" << endl;
		}
		break;
	}
	default: {
		cout << "Khong co thong tin ban muon thay doi !";
		break;
	}


		return;


	}
}
void StudentAccess::Delete() {
	string id;
	cout << "Nhap ma so sinh vien cua sinh vien ban muon xoa : ";
	cin >> id;
	string querry = " DELETE from SINHVIEN where MSSV = "+  id;
	const char* SQLQuery = querry.c_str();
	if (SQL_SUCCESS == SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery, SQL_NTS)) {
		cout << "Da cap nhat du lieu vao!" << endl;
	}
	else {

		cout << "Du lieu  cap nhat khong thanh cong !" << endl;
	}


	return; 
}
void StudentAccess::Show() {
	//----thuc hien mo khoa 






	
	char SQLQuery[] = "SELECT * FROM SINHVIEN";


	if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery, SQL_NTS)) {
	
		cout << "Loi o ham show ";
	}


	else {
		cout << "Thuc hien duoc ham show"<<endl;
		char id[30], name[70],sex[20], birth[14], address[50], number[20];
		int i = 0;
		cout << "+--------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|\t\t\t\t DANH SACH SINH VIEN KY TUC XA DA NANG					       		                 |" << endl;
		cout << "+--------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|" << setw(20) << left << "   Ma Sinh Vien    " << "|" << setw(29) << "    \tTen Sinh Vien" << setw(3)<<"|" << "Gioi tinh   " << "|" << setw(12) << "  Ngay Sinh    " << "|" << setw(22) << "\tDia Chi" << "|" << setw(15) << "\tSo Dien Thoai	|" << endl;

		cout << "+--------------------------------------------------------------------------------------------------------------------------------------+" << endl;

		while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS) {
			cout << "|";
			// Fetches the next rowset of data from the result
			SQLGetData(SQLStatementHandle, 1, SQL_C_DEFAULT, &id, sizeof(id), NULL);
			SQLGetData(SQLStatementHandle, 2, SQL_C_DEFAULT, &name, sizeof(name), NULL);
			SQLGetData(SQLStatementHandle, 3, SQL_C_DEFAULT, &sex, sizeof(name), NULL);


			SQLGetData(SQLStatementHandle, 4, SQL_C_DEFAULT, &birth, sizeof(birth), NULL);

			SQLGetData(SQLStatementHandle, 5, SQL_C_DEFAULT, &address, sizeof(address), NULL);

			SQLGetData(SQLStatementHandle, 6, SQL_C_DEFAULT, &number, sizeof(number), NULL);


			// Retrieves data for a single column in the result set
			cout << "     " << setw(15) << left << id << "|    " << setw(30) << name << "|    "<<setw(10)<<sex<<"|   " << setw(12) << birth << "|   " << setw(25) << address << "  |  " << setw(15) << number << "|" << endl;
			++i;
			if (i == MAX_ROW_SHOW) break;
		}
		cout << "+---------------------------------------------------------------------------------------------------------------------------------------+" << endl;

	}

	SQLCancel(SQLStatementHandle);


}


//Gồm 3 tầng : tầng 1 (connect), tầng 2 (dataaccess) , tầng 3(student,studentaccess)
