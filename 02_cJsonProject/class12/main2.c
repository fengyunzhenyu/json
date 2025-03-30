#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

int main()
{
    const char *json_string = "{\"name\":\"Alice\",\"age\":25}{\"name\":\"Alice\",\"age\":25} extra_data";

    //正常解析
    // cJSON* json = cJSON_Parse(json_string);

    //解析结束位置
    const char* end_ptr = NULL;
    //解析json
    // 0 不要求NULL终止, 1 强制要去NULL终止
    cJSON* json = cJSON_ParseWithOpts(json_string, &end_ptr, 1); 
    if(json == NULL)
    {
        // printf("解析失败！\n");
        printf("解析失败：json必须以'\\0' 结尾!\n");
        return -1;
    }


    //使用格式化输出
    char* print_json = cJSON_Print(json);
    printf("Format Json: %s\n", print_json);
    printf("解析结束的位置：%s\n", end_ptr);
    free(print_json);

    cJSON_Delete(json);

    return 0;
}