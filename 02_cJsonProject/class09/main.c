#include "cJSON.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //创建json对象
    cJSON* root = cJSON_CreateObject();
    cJSON_AddStringToObject(root, "name", "Alice");
    cJSON_AddNumberToObject(root, "age", 25);


    //将json数据保存到文件中e
    FILE* file = fopen("output.json", "w");
    if(file == NULL)
    {
        printf("无法打开文件!\n");
        cJSON_Delete(root);
        return -1;
    }

    char* print_json = cJSON_Print(root);
    fprintf(file, "%s\n", print_json);

    //关闭文件
    fclose(file);

    //释放内存
    cJSON_Delete(root);


    FILE* file_ = fopen("output.json", "r");
    if(file == NULL)
    {
        printf("无法打开文件！\n");
        return -1;
    }
    char buffer[1024];
    fread(buffer, 1, sizeof(buffer), file);
    fclose(file_);

    cJSON* json = cJSON_Parse(buffer);
    printf("文件中的json:\n%s\n", cJSON_Print(json));

    cJSON_Delete(json);

    return 0;
}