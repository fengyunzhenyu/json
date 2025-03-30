#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

int main() {
    // 解析 JSON 字符串
    const char *json_string = "{\"name\":\"John\", \"age\":30}";
    cJSON *json = cJSON_Parse(json_string);

    if (json == NULL) {
        printf("Error parsing JSON.\n");
        return 1;
    }

    // 打印 JSON 数据
    char *printed_json = cJSON_Print(json);
    printf("Parsed JSON: %s\n", printed_json);
    
    // 释放内存
    cJSON_Delete(json);
    free(printed_json); // free cJSON_Print 的输出

    return 0;
}