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


    //打印解析后的json对象
    char* printed_json = cJSON_Print(json);
    printf("解析后的josn：%s\n", printed_json);

    //释放内存
    cJSON_Delete(json);
    free(printed_json);

    return 0;
}