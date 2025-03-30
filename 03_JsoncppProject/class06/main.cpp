#include <iostream>
#include <fstream>
#include "json/json.h"

int main()
{
    //json 字符串
    std::string json_string =  R"({"name":"John", "age":30, "city":"New York"
                        ,"array":[1,2,3,4,5]})";

    //json解析器
    Json::CharReaderBuilder readerBuilder;
    Json::Value root;
    std::string errs;

    //输入流
    std::istringstream iss(json_string);

    //解析json
    if(!Json::parseFromStream(readerBuilder, iss, &root, &errs)){
        std::cout<<"Failed to parse Json: "<<errs<<std::endl;
    }

    std::cout<<"before Json: "<<root.toStyledString()<<std::endl;

    //删除“age”
    //判断age是否存在
    if(root.isMember("age")){
        root.removeMember("age");
    }

    //删除数组的元素
    if(root.isMember("array")){
        Json::Value removeItem;
        root["array"].removeIndex(1, &removeItem);// nullptr
        std::cout<<"remove Item: "<<removeItem.toStyledString()<<std::endl;
    }

    std::cout<<"remove Json: "<<root.toStyledString()<<std::endl;
    return 0;
}