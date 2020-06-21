#ifndef PASS_MSG
#define PASS_MSG
#include <mysql/mysql.h>
void pass_os(char * cgiUserAgent);
void pass_browser(char * cgiUserAgent);
void pass_location(char * pos);
#endif