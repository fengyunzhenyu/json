#include "cJSON.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //打开文件
    FILE* file = fopen("setting.json","r");
    if(!file){
        printf("无法打开文件\n");
        return -1;
    }
    char buffer[1024];
    fread(buffer, 1, sizeof(buffer), file);
    fclose(file);

    cJSON* json = cJSON_Parse(buffer);
    if(json == NULL)
    {
        printf("解析失败\n");
        return -1;
    }
    //服务器的IP
    cJSON* server = cJSON_GetObjectItem(json, "server");
    if(cJSON_IsString(server)){
        printf("服务器: %s\n", server->valuestring);
    }
    //端口
    cJSON* port = cJSON_GetObjectItem(json, "port");
    if(cJSON_IsNumber(port))
    {
        printf("端口：%d\n", port->valueint);
    }
    //调试模式d
    cJSON* debug = cJSON_GetObjectItem(json, "debug");
    if(cJSON_IsBool(debug)){
        printf("调试模式：%d\n", debug->valueint);
    }

    return 0;
}