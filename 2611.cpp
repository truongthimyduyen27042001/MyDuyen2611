#include <iostream>
using  namespace std;
#include "StudentAccess.h"
#include "Student.h"
#include "StudentAccess.h"
#include "Connect.h"
#include "Function.h"
int main() {
	//Connect h;
	/*StudentAccess s;
	s.Init();
	s.Show();
	s.Insert();
	s.Show();*/
	Function fc;
	char key;
	StudentAccess s;
	cout << "Chao mung ban den voi quan li ki tuc xa !" << endl;
	/*do {
		fc.ChucNang(s);
		cout << "Ban co muon tiep tuc ?";
		cout << "Neu muon thoat hay nhan 'y' ";
		cin >> key;
	} while (key != 'y');*/
	fc.ChucNang(s);
	system("pause");
	





	return 0;
	


}
