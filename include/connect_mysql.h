#ifndef CONNECT_MYSQL_H
#define CONNECT_MYSQL_H
#include <mysql/mysql.h>
void Init_mysql(MYSQL * conn,char * DB_name);
int Insert(MYSQL * conn ,int flag, int num);
void Close_mysql(MYSQL * conn);
int Insert_loc(MYSQL * conn ,char* loc);
// void printResult(MYSQL *mysqlPrint);
void printResult();
#endif