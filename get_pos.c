#include <curl/curl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>	
#include "include/pass_msg.h"

//从返回的信息中解析出省份信息
size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp)
{
    FILE *fp;
	int total;
    char * raw = (char *)buffer;
    char *raw2 = NULL;
    char  result[10] = {};
    int len = strlen(raw);
    int l = 0,r = 0;
   int cnt = 0;
   for (int i = 0; i < len; i++){
       if (raw[i] == '"'){
           
           cnt++;
       }
       if (cnt == 3){
           l = i;
           break;
       }
   }
   cnt = 0;
      for (int i = 0; i < len; i++){
       if (raw[i] == '"'){
           cnt++;
       }
       if (cnt == 4){
           r = i;
           break;
       }
   }
    for (int i = l + 1; i < r; i++){
        result[i - l - 1] = raw[i];
    }
    if (r == l + 1){
        sprintf(result,"%s","未知");
    }
    pass_location(result);

	return 1;
}

int call_url(char *url)
{
	// 初始化libcurl
    CURLcode return_code;

    return_code = curl_global_init(CURL_GLOBAL_ALL);
    if (CURLE_OK != return_code)
    {
        return -1;
    }
 
    CURL *easy_handle = curl_easy_init();
    if (NULL == easy_handle)
    {
        curl_global_cleanup(); 
        return -1;
    }

    curl_easy_setopt(easy_handle,CURLOPT_URL,url);//
	//回调函数
    curl_easy_setopt(easy_handle,CURLOPT_WRITEFUNCTION,write_data);//
    //如果没有通过CURLOPT_WRITEFUNCTION属性给easy handle设置回调函数
    //libcurl会提供一个默认的回调函数，它只是简单的将接收到的数据打印到标准输出。
    //也可以通过CURLOPT_WRITEDATA属性给默认回调函数传递一个已经打开的文件指针，

	//执行请求
    curl_easy_perform(easy_handle);   

    curl_easy_cleanup(easy_handle);
    curl_global_cleanup();

}
