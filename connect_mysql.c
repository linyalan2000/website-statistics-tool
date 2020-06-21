#include <stdio.h>
#include <mysql/mysql.h>
#include <string.h>

//初始化以及连接到对应数据库
 void Init_mysql(MYSQL * conn,char * DB_name){
     mysql_init(conn);
    if(mysql_real_connect(conn,"localhost","root","123456",DB_name,0,NULL,CLIENT_FOUND_ROWS)) 
    {
        // printf("connect success!\n");
    }
    else{
        printf("connect error!\n");
    }
 }

//插入浏览器和操作系统的信息
int Insert(MYSQL * conn ,int flag, int num){

    int res = 0;
    char str[100] = {};
     if (flag == 1){
        char str[100] = "update OS set num=num+1 where id = ";
        str[strlen(str)] = num + '0';
        res = mysql_query(conn,str);
     }
     if (flag == 2){
        char str[100] = "update Browser set num=num+1 where id = ";
        str[strlen(str)] = num + '0';
        res = mysql_query(conn,str);
     }
     return res;
 }

 //插入地区信息
 int Insert_loc(MYSQL * conn ,char* loc){
        char s[100];
        int res;
        sprintf(s,"%s%s%s","INSERT Location (province) VALUES ('",loc,"\');");
        res = mysql_query(conn,s);
        return res;
 }

//关闭接口
 void Close_mysql(MYSQL * conn){
      mysql_close(conn);
 }

//打印结果
 void printResult()
{
    MYSQL mysqlPrint;
    Init_mysql(&mysqlPrint,"VISITER");
    mysql_set_character_set(&mysqlPrint, "utf8" );
    MYSQL_RES * result;
    char s[100];
    int numFields = 0;
    int numRows = 0;
    MYSQL_FIELD * field;
    MYSQL_ROW row;
    int i = 0;


    sprintf(s,"%s","SELECT COUNT(*) FROM Location;");
    mysql_query(&mysqlPrint,s);
    result = mysql_store_result(&mysqlPrint);//将查询的全部结果读取到客户端
    printf("是本站的第%s位访客。来看看访问这个网站的其他朋友来自哪里吧～</h4>", mysql_fetch_row(result)[0]);

    printf("<h2 align=\"center\">访客使用的操作系统统计</h2><br>");
    sprintf(s,"%s","select * from OS;");
    mysql_query(&mysqlPrint,s);
    result = mysql_store_result(&mysqlPrint);//将查询的全部结果读取到客户端
    numFields = mysql_num_fields(result);//统计结果集中的字段数
    numRows = mysql_num_rows(result);//统计结果集的行数
    printf("<table border=\"1\" width=\"200\" align=\"center\">");
    if(result)
    {
        while(row = mysql_fetch_row(result))//返回结果集中行的记录
        {
            printf("<tr>");
            for(i = 1; i < numFields; i++)
            {
                printf("<td>%s</td>", row[i]);
            }
            printf("</tr>");
        }
    }
    printf("</table>");
    printf("<h2 align=\"center\">访客使用的浏览器统计</h2><br>");
    sprintf(s,"%s","select * from Browser;");
    mysql_query(&mysqlPrint,s);
    result = mysql_store_result(&mysqlPrint);//将查询的全部结果读取到客户端
    numFields = mysql_num_fields(result);//统计结果集中的字段数
    numRows = mysql_num_rows(result);//统计结果集的行数
    printf("<table border=\"1\" width=\"200\" align=\"center\">");
    if(result)
    {
        while(row = mysql_fetch_row(result))//返回结果集中行的记录
        {
            printf("<tr>");
            for(i = 1; i < numFields; i++)
            {
                printf("<td>%s</td>", row[i]);
            }
            printf("</tr>");
        }
    }
    printf("</table>");
    printf("<h2 align=\"center\">访客地域分布统计</h2><br>");
    sprintf(s,"%s","SELECT province, COUNT(*) AS totalUsers FROM Location GROUP BY province;");
    mysql_query(&mysqlPrint,s);
    result = mysql_store_result(&mysqlPrint);//将查询的全部结果读取到客户端
    numFields = mysql_num_fields(result);//统计结果集中的字段数
    numRows = mysql_num_rows(result);//统计结果集的行数
    printf("<table border=\"1\" width=\"200\" align=\"center\">");
    if(result)
    {
        while(row = mysql_fetch_row(result))//返回结果集中行的记录
        {
            printf("<tr>");
            for(i = 0; i < numFields; i++)
            {
                printf("<td>%s</td>", row[i]);
            }
            printf("</tr>");
        }
    }
    printf("</table>");
    mysql_free_result(result);//释放result空间，避免内存泄漏
}
 