#pragma once
#include <string>
#include <iostream>
using namespace std;

class Student
{
private : 
	char ID[10];
	char name[30];
	char sex[20];
	char birth[20];
	char address[30];
	char number[20];
public  :
	Student();
	Student(char*, char*,char*, char*, char*, char*);
	~Student();
	//char* getID();
	//char* getName();
	//char* getBirth();
	//char* getAddress();
	//char* getNumberr();
	//void setID(char* );
	//void setName(char* );
	//void setBirth(char* );
	//void setAddress(char*);
	//void setNumberr(char*);
	void setStudent();
	string insertQuerr();

};

