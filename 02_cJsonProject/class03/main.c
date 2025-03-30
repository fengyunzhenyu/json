#include "cJSON.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //json字符串
    const char* json_str = "{\"name\":\"Alice\", \"age\":25, \"is_student\":false}";

    //解析josn字符串
    cJSON* json = cJSON_Parse(json_str);
    if(json == NULL)
    {
        printf("解析失败！\n");
        return -1;
    }

    //访问name字段
    cJSON* name = cJSON_GetObjectItem(json, "name");
    if(cJSON_IsString(name))
    {
        printf("姓名：%s\n", name->valuestring);
        printf("key: %s\n", name->string);
    }

    //读取age字段
    cJSON* age = cJSON_GetObjectItem(json, "age");
    if(cJSON_IsNumber(age))
    {
        printf("年龄：%d\n", age->valueint);
    }

    //读取is_student字段
    cJSON* is_student = cJSON_GetObjectItem(json, "is_student");
    if(cJSON_IsBool(is_student))
    {
        printf("是否是学生：%d\n", is_student->valueint);
    }

    //打印解析后的json对象
    char* printed_json = cJSON_Print(json);
    printf("解析后的josn：%s\n", printed_json);

    //释放内存
    cJSON_Delete(json);
    free(printed_json);

    return 0;
}