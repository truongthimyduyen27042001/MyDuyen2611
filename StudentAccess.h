#pragma once
#include <iostream>
using namespace std;
#include "Connect.h"
#include "Student.h"
class StudentAccess
:public Connect
{
public : 
	void Select(Student*&);
	void Insert();
	void Update();
	void Delete();
	void Show();

};

