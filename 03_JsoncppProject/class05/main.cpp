#include <iostream>
#include <fstream>
#include "json/json.h"

int main(){

    //Json字符串
    std::string json_string = R"({"name":"John", "age":30, "city":"New York",
        "array":[1,2,3,4,5]})";

    //创建一个解析器
    Json::CharReaderBuilder readerBuilder;
    Json::Value root;

    std::string errs;
    std::istringstream iss(json_string);

    if(!Json::parseFromStream(readerBuilder, iss, &root, &errs)){
        std::cout<<"Failed to parse Json: "<<errs<<std::endl;
    }

    //修改之前的数据
    std::cout<<"Before Json: "<<root.toStyledString()<<std::endl;

    //修改数据
    //判断成员是否存在
    if(root.isMember("name"))
        root["name"] = "Alice";
    else{
        std::cout<<"Member name dose not exist!"<<std::endl;
    }
    if(root.isMember("age"))
        root["age"] = 31;
    else{
        std::cout<<"Member age dose not exist!"<<std::endl;
    }

    if(root.isMember("sex"))
        root["sex"] = "male";
    else{
        std::cout<<"Member sex dose not exist!"<<std::endl;
    }
    root["array"][0] = 100;

    std::cout<<"Updated Json: "<<root.toStyledString()<<std::endl;


    return 0;
}