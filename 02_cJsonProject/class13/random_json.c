#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cJSON.h"

// 随机生成一个字符串
char* generate_random_string(size_t length) {
    static const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    char *random_string = (char*) malloc(length + 1);
    if (!random_string) {
        return NULL;
    }

    for (size_t i = 0; i < length; i++) {
        random_string[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    random_string[length] = '\0';
    return random_string;
}

// 随机生成一个 JSON 对象
cJSON* generate_random_json(size_t num_items) {
    cJSON *root = cJSON_CreateObject();
    if (!root) {
        return NULL;
    }

    for (size_t i = 0; i < num_items; i++) {
        char key[20];
        snprintf(key, sizeof(key), "key%zu", i);

        int random_type = rand() % 3;  // 选择一个随机类型（字符串、数字、数组）
        if (random_type == 0) {
            // 随机字符串
            cJSON_AddStringToObject(root, key, generate_random_string(10));
        } else if (random_type == 1) {
            // 随机数字
            cJSON_AddNumberToObject(root, key, rand() % 1000);
        } else {
            // 随机数组
            cJSON *array = cJSON_CreateArray();
            for (int j = 0; j < 5; j++) {
                cJSON_AddItemToArray(array, cJSON_CreateNumber(rand() % 1000));
            }
            cJSON_AddItemToObject(root, key, array);
        }
    }

    return root;
}

// 生成随机 JSON 数据并保存到文件
void generate_json_file(const char *filename, size_t size_in_mb) {
    size_t target_size = size_in_mb * 1024 * 1024;  // 转换为字节
    size_t current_size = 0;
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("无法创建文件！\n");
        return;
    }

    // 使用随机数种子，确保每次生成的数据不同
    srand((unsigned int)time(NULL));

    while (current_size < target_size) {
        // 生成一个随机 JSON 对象
        cJSON *root = generate_random_json(10);  // 每个 JSON 对象包含 10 个字段
        if (!root) {
            printf("内存分配失败！\n");
            fclose(file);
            return;
        }

        // 转换为字符串
        char *json_str = cJSON_PrintUnformatted(root);
        if (json_str) {
            size_t json_len = strlen(json_str);
            if (current_size + json_len > target_size) {
                json_str[target_size - current_size - 1] = '\0';  // 截断字符串到指定大小
            }
            fputs(json_str, file);  // 写入文件
            current_size += json_len;
            free(json_str);  // 释放 JSON 字符串
        }

        // 删除 JSON 对象以释放内存
        cJSON_Delete(root);
    }

    fclose(file);
    printf("JSON 文件生成完毕，文件大小: %zu MB\n", current_size / (1024 * 1024));
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("使用方法: %s <输出文件名> <文件大小(MB)>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    size_t size_in_mb = atoi(argv[2]);

    generate_json_file(filename, size_in_mb);

    return 0;
}