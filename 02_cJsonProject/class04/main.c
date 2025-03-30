#include "cJSON.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //json字符串
    const char* json_str = "{ \"fruits\": [\"苹果\", \"香蕉\", \"葡萄\"] }";

    //解析josn字符串
    cJSON* json = cJSON_Parse(json_str);
    if(json == NULL)
    {
        printf("解析失败！\n");
        return -1;
    }

    //解析数组
    cJSON* fruits = cJSON_GetObjectItem(json, "fruits");
    if(cJSON_IsArray(fruits))
    {
        int array_size = cJSON_GetArraySize(fruits);
        for(int i = 0; i < array_size; i++){
            cJSON* item = cJSON_GetArrayItem(fruits, i);
            printf("水果 %d, %s\n", i+1, item->valuestring);
        }
    }


    //打印解析后的json对象
    char* printed_json = cJSON_Print(json);
    printf("解析后的josn：%s\n", printed_json);

    //释放内存
    cJSON_Delete(json);
    free(printed_json);

    return 0;
}