#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

//自定义内存分配函数
void* custom_malloc(size_t size)
{
    printf("分配%zu字节内存\n", size);
    return malloc(size);//可以换成内存池管理方法
}

void custom_free(void * ptr)
{
    printf("释放内存\n");
    free(ptr); //自定义释放内存方法
}


int main() {

    //设置自定义的内存管理函数
    cJSON_Hooks hooks = {custom_malloc, custom_free};
    cJSON_InitHooks(&hooks);


    // 解析 JSON 字符串
    const char *json_string = "{\"name\":\"John\", \"age\":30}";
    cJSON *json = cJSON_Parse(json_string);

    if (json == NULL) {
        printf("Error parsing JSON.\n");
        return 1;
    }

    // 打印 JSON 数据
    // char *printed_json = cJSON_Print(json);
    // printf("Parsed JSON: %s\n", printed_json);
    
    // 释放内存
    cJSON_Delete(json);
    // free(printed_json); // free cJSON_Print 的输出

    return 0;
}