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
	sqlite3 *db = NULL;
	char *zErrMsg = NULL;
	int rc = 0;
	char *sql = NULL;

	/* Open database */
	rc = sqlite3_open("test.db", &db);
	if(rc){
		fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(db));
		exit(0);
	}else{
		fprintf(stderr, "Open database successful\n");
	}
	
	/* Create SQL statement */
	
	sql = "CREATE TABLE COMPANY(" \
		   "ID INT PRIMARY KEY NOT NULL," \
		   "NAME TEXT NOT NULL," \
		   "AGE  INT  NOT NULL," \
		   "ADDRESS CHAR(50),"	\
		   "SALARY REAL);";
	
	/* Execute SQL statement */
	
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if(rc != SQLITE_OK){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}else{
		fprintf(stderr, "Table create successful\n");
	}

	sqlite3_close(db);
	return 0;
}
