#pragma once
#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include<stdlib.h>
#include <string>
class Connect {
protected:
#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1024
#define MAX_ROW_SHOW 30
	//define handles and variables
	SQLHANDLE SQLEnvHandle;
	SQLHANDLE SQLConnectionHandle;
	SQLHANDLE SQLStatementHandle;
	SQLRETURN retCode;
public:
	void Init();
	void Select();
	//virtual void ExecuteDB(string query);
	virtual void Insert() = 0;
	virtual void Update() = 0;
	virtual void Delete() = 0;
	virtual void Show() = 0;
	void Close();

};
