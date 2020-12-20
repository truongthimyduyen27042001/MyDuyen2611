#include <iostream>
using namespace std;
#include "Connect.h"
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include<stdlib.h>
#include <string>

void Connect::Init() {
	do {
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvHandle))
			// Allocates the environment
			break;

		if (SQL_SUCCESS != SQLSetEnvAttr(SQLEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
			// Sets attributes that govern aspects of environments
			break;

		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvHandle, &SQLConnectionHandle))
			// Allocates the connection
			break;

		if (SQL_SUCCESS != SQLSetConnectAttr(SQLConnectionHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0))
			// Sets attributes that govern aspects of connections
			break;

		SQLCHAR retConString[1024]; // Conection string
		switch (SQLDriverConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"DRIVER={SQL Server}; SERVER=DESKTOP-D9VU28Q\\SQLEXPRESS; DATABASE=QLKTX_Test6;User Id = sa;Password = 27042001;", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT)) {
			// Establishes connections to a driver and a data source
		case SQL_SUCCESS:
			break;
		case SQL_SUCCESS_WITH_INFO:
			break;
		case SQL_NO_DATA_FOUND:
			//showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
			retCode = -1;
			break;
		case SQL_INVALID_HANDLE:
			//showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
			retCode = -1;
			break;
		case SQL_ERROR:
			//showSQLError(SQL_HANDLE_BC, SQLConnectionHandle);
			retCode = -1;
			break;
		default:
			break;
		}

		if (retCode == -1)
			break;

		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, SQLConnectionHandle, &SQLStatementHandle))
			// Allocates the statement
			break;
	} while (FALSE);
}
void Connect::Close() {
		SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
		SQLDisconnect(SQLConnectionHandle);
		SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
		SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);
}
void Connect::Select() {

}
