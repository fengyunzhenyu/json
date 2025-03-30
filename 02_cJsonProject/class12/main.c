#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

int main() {
    const char *json_string = "{\"name\":\"John\", \"age\":30, \"address\":\"123 Main St\"}";
    cJSON *json = cJSON_Parse(json_string);
    
    if (json == NULL) {
        printf("Error parsing JSON.\n");
        return 1;
    }

    //使用格式化输出
    char* print_json = cJSON_Print(json);
    printf("Format Json: %s\n", print_json);
    free(print_json);

    // 使用紧凑的输出
    char *printed_json = cJSON_PrintUnformatted(json);
    printf("Parsed JSON (compact): %s\n", printed_json);

    // 清理
    free(printed_json); 
    cJSON_Delete(json);
    
    return 0;
}