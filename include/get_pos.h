#ifndef GET_POS_H
#define GET_POS_H
#include <mysql/mysql.h>
#include <curl/curl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>	//exit
int call_url(char *url);
size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp);
#endif