#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/reader.h"
#include <iostream>
#include <fstream>

//DOM解析
int main()
{
    //json字符串 、文件
    const char* json_str = R"({"name": "Alice", "age":25, "city":"New York"})";

    //创建一个json对象并解析
    rapidjson::Document doc;
    doc.Parse(json_str);

    //访问json字段// 修改、删除、增加
    if(doc.HasMember("name")){
        std::cout<<"name: "<<doc["name"].GetString()<<std::endl;
    }
    if(doc.HasMember("age")){
        std::cout<<"age: "<<doc["age"].GetInt()<<std::endl;
    }

    return 0;
}