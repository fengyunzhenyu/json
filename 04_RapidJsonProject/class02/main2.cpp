/*
{
    "name": "张三",
    "age": 30,
    "married": true
}
*/
#include <iostream>
#include "rapidjson/document.h"

int main(){
    const char* json = R"(
    {
    "name": "张三",
    "age": 30,
    "married": true
    })";

    rapidjson::Document doc;
    if(doc.Parse(json).HasParseError()){
        std::cout<<"Parsed to Json Failed!"<<std::endl;
        return -1;
    }
    //检查每个成员 jsoncpp isMember/ rapidjson HasMember
    if(doc.HasMember("name1") && doc["name1"].IsString())
        std::cout<<"name: "<<doc["name1"].GetString()<<std::endl;
    else
        std::cout<<"Json has not name1 key!"<<std::endl;
    if(doc.HasMember("age") && doc["age"].IsInt())
        std::cout<<"age: "<<doc["age"].GetInt()<<std::endl;
        
    if(doc.HasMember("married") && doc["married"].IsInt())
        std::cout<<"married: "<<(doc["married"].GetBool() ?"True":"False")<<std::endl;

    return 0;
}
