#include <iostream>
#include <fstream>
#include "json/json.h"

int main()
{
    //json数组
    std::string jsonString = R"([{"name":"John", "age":30}, {"name":"Alice", "age":25}])";

    //创建一个解析器
    Json::CharReaderBuilder readerBuilder;
    Json::Value root;
    std::string errs;

    std::istringstream iss(jsonString);
    if(Json::parseFromStream(readerBuilder, iss, &root, &errs)){
        //解析成功
        for(const auto& item: root){
            std::cout<<"Name: "<<item["name"].asString()<<", age: "<<item["age"].asInt()<<std::endl;
        }
    }

    
    return 0;
}