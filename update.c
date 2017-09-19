/*************************************************************************
	> File Name: update.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Mon 18 Sep 2017 12:24:50 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sqlite3.h>


int main()
{
	sqlite3* db = NULL;
	char* errMsg = NULL;
	int ret = 0;
	char *sql = NULL;

	ret = sqlite3_open("test.db", &db);
	if(ret != 0)
	{
		fprintf(stderr, "open db failed:%s\n",sqlite3_errmsg(db));
	}

	sql = "UPDATE COMPANY set SALARY = 18888.0 WHERE ID = 1;";

	ret = sqlite3_exec(db, sql, NULL, NULL, &errMsg);
	if(ret != SQLITE_OK)
	{
		fprintf(stderr, "error:%s\n", errMsg);
		sqlite3_free(errMsg);
	}
	sqlite3_close(db);
	return 0;
}
