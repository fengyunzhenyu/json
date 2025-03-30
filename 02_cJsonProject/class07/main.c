#include "cJSON.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //创建json对象
    cJSON* json = cJSON_CreateObject();
    cJSON_AddStringToObject(json, "name", "李四");
    cJSON_AddNumberToObject(json, "age", 25);

    cJSON* name = cJSON_CreateString("王五");
    cJSON_AddItemToObject(json, "name1", name);

    //创建josn数组
    cJSON* hobbies = cJSON_CreateArray();
    cJSON_AddItemToArray(hobbies, cJSON_CreateString("排球"));
    cJSON* ball = cJSON_CreateString("网球");
    cJSON_AddItemToArray(hobbies, ball);

    //把数组对象添加到json里
    cJSON_AddItemToObject(json, "hobbies", hobbies);

    //输出json字符串
    char *print_json = cJSON_Print(json);
    printf("创建的json：%s\n", print_json);


    //修改age的值
    cJSON* age = cJSON_GetObjectItem(json, "age");
    printf("age修改前的int值：%d\n", age->valueint);
    printf("age修改前的double值：%f\n", age->valuedouble);
    if(cJSON_IsNumber(age))
    {
        age->valueint = 30;
        age->valuedouble = 30;
    }
    printf("age的int值：%d\n", age->valueint);
    printf("age的double值：%f\n", age->valuedouble);

    //输出json字符串
    char *print_json1 = cJSON_Print(json);
    printf("修改的json：%s\n", print_json1);
    free(print_json1);

    cJSON* new_age = cJSON_CreateNumber(35);
    if(new_age == NULL){
        printf("创建失败！\n");
        return -1;
    }
    //替换age键值
    cJSON_ReplaceItemInObject(json, "age", new_age);

    //输出json字符串
    char *print_json2 = cJSON_Print(json);
    printf("修改的json：%s\n", print_json2);
    free(print_json2);

    //释放内存
    cJSON_Delete(json);
    free(print_json);

    return 0;
}