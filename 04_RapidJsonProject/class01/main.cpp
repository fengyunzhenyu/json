#include <iostream>
#include "rapidjson/document.h"

int main(){
    const char* json = R"({"name": "Alice", "age": 25, "skills": ["C++", "Python"]})";

    //解析json
    rapidjson::Document doc;
    doc.Parse(json);

    //读取数据
    std::cout<<doc["name"].GetString()<<std::endl;
    std::cout<<doc["age"].GetInt()<<std::endl;

    for(auto& skill : doc["skills"].GetArray()){
        std::cout<<skill.GetString()<<" ";
    }
    std::cout<<std::endl;

    return 0;
}