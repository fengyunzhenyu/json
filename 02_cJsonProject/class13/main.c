#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"
#include <string.h>

int main()
{
    FILE* file = fopen("output.json", "r");
    if(file == NULL){
        printf("文件打开失败！\n");
        return -1;
    }

    char* buffer = malloc(1024);
    if(buffer == NULL)
    {
        printf("内存分配失败！\n");
        fclose(file);
        return -1;
    }

    size_t read_size;
    cJSON* json;
    const char* end_ptr = NULL;
    char* remaining_data = NULL; //用于保存上次解析中未完全解析的数据

    while((read_size = fread(buffer, 1, 1024 - 1, file)) > 0){
        buffer[read_size] = '\0';
        //如果有残余数据，拼接到当前读取的buffer中
        if(remaining_data){
            size_t remaining_len = strlen(remaining_data);
            size_t new_data_len = read_size;
            size_t total_len = remaining_len+new_data_len;

            //创建新的缓冲区来存储拼接后的数据
            char* new_buffer = malloc(total_len+1);
            if(new_buffer == NULL){
                printf("内存分配失败！\n");
                fclose(file);
                free(buffer);
                return -2;
            }

            //将残余的数据和新数据拼接
            memcpy(new_buffer, remaining_data, remaining_len);
            memcpy(new_buffer+remaining_len, buffer, new_data_len);
            new_buffer[total_len] = '\0';

            //更新buffer的大小和数据
            free(buffer);
            buffer = new_buffer;
            read_size = total_len;
            free(remaining_data);
            remaining_data = NULL;
        }

        //使用cjson_prarsewithopts解析缓冲区中的数据
        const char* buffer_tmp = buffer;
        while(1){
            json = cJSON_ParseWithOpts(buffer_tmp, &end_ptr, 0);
            if(json == NULL){
                //如果还有剩余数据未解析，则更新remaining data，并继续读取数据
                if(*end_ptr != '{'){
                    remaining_data = strdup(buffer_tmp);
                    break; //跳出当前循环，继续读取文件
                }
            }
            //解析一个完整的json数据
            char* print_json = cJSON_Print(json);
            printf("解析的json数据：\n%s\n", print_json);
            free(print_json);
            cJSON_Delete(json);

            if(*end_ptr == '\0'){
                break; //跳出当前循环，继续读取文件
            }
            // 继续解析下一个json对象
            buffer_tmp = end_ptr;
        }

        //如果仍然有残余数据，表示当前读取的数据并没有解析完，继续拼接
        if(remaining_data){
            continue;
        }
    }

    if(remaining_data)
    {
        printf("剩余的json数据：%s\n", remaining_data);
    }

    free(buffer);
    fclose(file);
    return 0;
}