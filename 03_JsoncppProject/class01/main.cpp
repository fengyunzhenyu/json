#include <iostream>
#include "json/json.h"
#include "fstream"

int main(){
    //json字符串
    std::string json_string = R"({"name":"John", "age":30})";

    //创建json解析器
    Json::CharReaderBuilder readerBuilder;
    Json::Value root;
    std::string errs;

    //解析json字符串
    std::istringstream iss(json_string);
    if(Json::parseFromStream(readerBuilder, iss, &root, &errs)){
        //解析成功
        std::cout<<"解析成功："<<std::endl;

        //创建一个格式化工具
        Json::StreamWriterBuilder writerBuilder;
        writerBuilder["indentation"] = "   ";//设置4个空格为缩进
        std::string json_str = Json::writeString(writerBuilder, root);

        //输出格式化
        std::cout<<json_str<<std::endl;
    }
    return 0;
}