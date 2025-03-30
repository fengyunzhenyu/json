#include <iostream>
#include <fstream>
#include "json/json.h"

int main()
{
    //示例的json字符串
    std::string jsonString = R"({
        "name": "John",
        "age": 30,
        "city": "New York",
        "isEmployed": true,
        "skills": ["C++", "Python", "Java"]
    })";


    //创建Json::CharReaderBuilder，用于解析Json字符串
    Json::CharReaderBuilder readerBuilder;
    Json::Value root;
    std::string errs;

    //解析json字符串
    std::istringstream iss(jsonString);
    if(Json::parseFromStream(readerBuilder, iss, &root, &errs)){
        //解析成功，输出Json内容
        std::cout<<"Parsed Json: "<<std::endl;

        //创建StreamWriterBuilder， 用于输出格式化的Json字符串
        Json::StreamWriterBuilder writerBuilder;
        writerBuilder["indentation"] = "****";//设置缩进为4的空格
        std::string jsonStr = Json::writeString(writerBuilder, root);

        //输出格式化后的Json字符串
        std::cout<<jsonStr<<std::endl;
    }
    return 0;
}