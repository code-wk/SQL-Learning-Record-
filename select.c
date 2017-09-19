/*************************************************************************
	> File Name: select.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Sat 16 Sep 2017 02:25:20 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sqlite3.h>

static int callback(void *NotUsed, int argc, char** argv, char **azColName){
	int i;
	for(i = 0; i < argc; i++){
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

int main(int argc, char* argv[]){
	sqlite3* db = NULL;
	char* zErrMsg = NULL;
	int ret = 0;
	char* sql = NULL;
	const char* data = "Callback function called";
	sqlite3_callback p = &callback;

	sqlite3_open("test.db", &db);
	sql = "SELECT * FROM COMPANY";
	ret = sqlite3_exec(db, sql, p, (void*)data, &zErrMsg);
	if(ret != SQLITE_OK){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}else{
		fprintf(stderr, "select successful\n");
	}	
	sqlite3_close(db);
	return 0;
}
