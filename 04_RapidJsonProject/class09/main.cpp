#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>

int main()
{
    //Json字符串
    const char* json_string = R"({"name":"John", "age":30, "city":"Beijing"})";

    //创建json对象 document
    rapidjson::Document doc;

    //解析json字符串
    doc.Parse(json_string);

    //检查是否解析成功
    if(doc.HasParseError())
    {
        std::cout<<"Json parse error!"<<std::endl;
        return -1;
    }

    //输出解析后的数据
    std::cout<<"name: "<<doc["name"].GetString()<<std::endl;
    std::cout<<"age: "<<doc["age"].GetInt()<<std::endl;
    std::cout<<"city: "<<doc["city"].GetString()<<std::endl;

    return 0;
}