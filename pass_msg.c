#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>
#include "include/connect_mysql.h"
void pass_os(char * cgiUserAgent){
    int OS_name = 4; //如果无法与以下三个系统匹配，则归为其他
    char OS[100][100] = {"Mac","Linux","Windows"}; //列出可能的操作系统名字
    for (int i = 0; i < 3; i++){
        char * pos = strstr(cgiUserAgent, OS[i]);
        if (pos != NULL){
            OS_name = i + 1;
            printf("您的操作系统为%s，",OS[i]);
            break; //找到就退出循环
        }
    }
    MYSQL conn;
    Init_mysql(&conn,"VISITER");
    Insert(&conn ,1, OS_name);
    Close_mysql(&conn);
}
void pass_browser(char * cgiUserAgent)
{
    int Browser_name = 4; //如果无法与以下浏览器匹配，则归为其他
    char OS[100][100] = {"Edge", "IE", "Chrome", "Presto", "360", "Firefox", "Safari"}; //列出可能的浏览器名字
    for (int i = 0; i < 7; i++){
        char * pos = strstr(cgiUserAgent, OS[i]);
        if (pos != NULL){
            Browser_name = i + 1;
            printf("您的操作系统为%s，",OS[i]);
            break; //找到就退出循环
        }
    }
    MYSQL conn;
    Init_mysql(&conn,"VISITER");
    Insert(&conn ,2, Browser_name);
    Close_mysql(&conn);
}
void pass_location(char * pos)
{
    MYSQL conn;
    Init_mysql(&conn,"VISITER");
    Insert_loc(&conn ,pos);
    Close_mysql(&conn);
}