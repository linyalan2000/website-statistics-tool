#include<string.h>
#include "include/cgic.h"
#include "include/connect_mysql.h"
#include <mysql/mysql.h>
#include "include/pass_msg.h"
#include "include/get_pos.h"

int cgiMain() {
    cgiWriteEnvironment("/CHANGE/TH;IS/PATH/capcgi.dat");
    cgiHeaderContentType("text/html;charset=utf-8");
    fprintf(cgiOut, "<title>count</title>");
    printf("<body background=\"https://tva1.sinaimg.cn/large/007S8ZIlgy1gfzo0kb93cj31hc0p01gw.jpg\" style=\" background-repeat:no-repeat;background-attachment: fixed;\">");
    fprintf(cgiOut, "<h1 align=\"center\">欢迎访问本站！</h1>");
    char url[100];
    sprintf(url,"%s%s","http://freeapi.ipip.net/",cgiRemoteAddr);
    call_url(url);
    pass_browser(cgiUserAgent);
    pass_os(cgiUserAgent);
    printResult();
    printf("</body>");
 return 0;
}
