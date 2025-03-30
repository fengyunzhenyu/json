#include <iostream>
#include "rapidjson/document.h"

int main(){
    //Json数组
    const char* json = R"({
                        "name": "John",
                        "age": 30,
                        "address": {
                            "street": "5th Avenue",
                            "city": "New York"
                            }
                        })";

    //Document
    rapidjson::Document doc;
    doc.Parse(json);
    //输出基础字段
    std::cout<<"name: "<<doc["name"].GetString()<<std::endl;
    std::cout<<"age: "<<doc["age"].GetInt()<<std::endl;
    
    //解析嵌套的json对象 address
    if(doc.HasMember("address") && doc["address"].IsObject()){
        const rapidjson::Value & address = doc["address"];
        std::cout<<"street: "<<address["street"].GetString()<<std::endl;
        std::cout<<"city: "<<address["city"].GetString()<<std::endl;
    }

    return 0;
}