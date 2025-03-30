#include "cJSON.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    cJSON* root = cJSON_CreateObject();
    cJSON_AddStringToObject(root, "name", "Alice");
    cJSON_AddNumberToObject(root, "age", 25);

    //创建skills数组
    cJSON* skills = cJSON_CreateArray();
    cJSON_AddItemToArray(skills, cJSON_CreateString("C++"));
    cJSON_AddItemToArray(skills, cJSON_CreateString("Python"));
    cJSON_AddItemToObject(root, "skills", skills);

    printf("Original Json:\n%s\n", cJSON_Print(root));

    //删除skills数组中的python
    cJSON_DeleteItemFromArray(skills, 1);
    printf("after deleteing python from skills:\n%s\n", cJSON_Print(root));


    //删除age这个对象
    cJSON_DeleteItemFromObject(root, "age");
    printf("after deleting age :\n%s\n", cJSON_Print(root));

    //删除skills数组
    cJSON_DeleteItemFromObject(root, "skills");
    printf("after deleting skills :\n%s\n", cJSON_Print(root));


    cJSON_Delete(root);//释放内存

    return 0;
}