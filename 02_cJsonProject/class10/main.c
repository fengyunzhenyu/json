#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

int main() {
    
    //创建cjson 对象
    cJSON* root = cJSON_CreateObject();

    //向json对象中插入一个false布尔值
    // cJSON_AddBoolToObject(root, "is_active", cJSON_False);
    cJSON_AddBoolToObject(root, "is_active", 0);
    cJSON_AddBoolToObject(root, "is_true", cJSON_True);
    // cJSON_AddBoolToObject(root, "is_true", 1);

    //添加一个null值
    cJSON_AddNullToObject(root, "NULL");

    //打印json对象
    char* print_json = cJSON_Print(root);
    printf("包含false的json：\n%s\n", print_json);
    free(print_json);

    //解析json数据
    cJSON* is_active = cJSON_GetObjectItem(root, "is_active");
    if(cJSON_IsBool(is_active))
    {
        printf("is_active 的type: %d\n", is_active->type);
        printf("is_active 是布尔值：%s\n", cJSON_IsFalse(is_active)?"false":"ture");
    }

    //解释true
    cJSON* is_true = cJSON_GetObjectItem(root, "is_true");
    if(cJSON_IsBool(is_true))
    {
        printf("is_true 的type: %d\n", is_true->type);
        printf("is_true 是布尔值：%s\n", cJSON_IsFalse(is_true)?"false":"ture");
    }

    //解析null数据
    cJSON* _null = cJSON_GetObjectItem(root, "NULL");
    if(cJSON_IsNull(_null)){
        printf("_null is null\n");
    }

    cJSON_Delete(root);
    return 0;
}
