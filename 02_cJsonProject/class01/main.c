#include "cJSON.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    const char* json_str = "{\"name\":\"Alice\",\"age\":25,\"is_student\":false}";

    cJSON* json = cJSON_Parse(json_str);
    if (json == NULL)
    {
        printf("解析失败！\n");
        return -1;
    }

    //打印出来
    char* printd_json = cJSON_Print(json);
    printf("解析后的Json：%s\n", printd_json);

    //释放内存
    cJSON_Delete(json);
    free(printd_json);
    return 0;
}