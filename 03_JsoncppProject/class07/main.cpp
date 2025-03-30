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

    std::cout<<"Parse to Json: "<<root.toStyledString()<<std::endl;

    //打开文件
    std::ofstream outFile("output.json");
    outFile<<root.toStyledString();
    outFile.close();

    std::cout<<"Json saved to output.json"<<std::endl;

    return 0;
}