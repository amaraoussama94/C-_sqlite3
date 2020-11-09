#include<iostream>
#include<conio.h>
#include "sqlite3.h"

using namespace std;

int main()
{
	char* err;
	int resp;
	sqlite3 *db;
	sqlite3_stmt *stmt;

	//create database
	sqlite3_open("Test_DB.db",&db);//name, pointer to the db
	//create table
	resp = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS test1(x1 INT, x2 INT , name VARCHAR(100)) ", NULL,NULL,&err);//test1 is the name of tab
	if (resp != SQLITE_OK)
	{
		cout <<"error"<< err;

	}
	///insert val into table ///for  string  here  use  only '' not ""
	resp = sqlite3_exec(db, "INSERT INTO test1 VALUES(10,20,'oussama') ", NULL, NULL, &err);//test1 is the name of tab
	if (resp != SQLITE_OK)
	{
		cout << "error" << err;

	}

	resp = sqlite3_exec(db, "INSERT INTO test1 VALUES(30,10,'amara') ", NULL, NULL, &err);//test1 is the name of tab
	if (resp != SQLITE_OK)
	{
		cout << "error" << err;

	}
	//select  from the table 
	sqlite3_prepare_v2(db,"SELECT x1,x2,name FROM test1 ",-1,&stmt,NULL);
	int a1, a2;
	const unsigned  char* myname;
	//return row  by  row
	sqlite3_step(stmt);//only first one 

	a1=sqlite3_column_int(stmt, 0);// a1=x1
	a2 = sqlite3_column_int(stmt, 1);// a2=x2
	myname = sqlite3_column_text(stmt, 2);// a2=x2
	cout << "\t hello=="<<a1<<"hi=="<<a2<<"hello"<< myname;
	//return all
	while (sqlite3_step(stmt)!=SQLITE_DONE) {
		a1 = sqlite3_column_int(stmt, 0);// a1=x1
		a2 = sqlite3_column_int(stmt, 1);// a2=x2
		myname = sqlite3_column_text(stmt, 2);// a2=x2
		cout << "\n hello==" << a1 << "hi==" << a2 << "hello" << myname;

	}
	_getch();
}
