#include <iostream>
#include "json/json.h"

int main(){
    //创建一个Json对象
    Json::Value root;

    root["name"] = "John";
    root["age"] = 30;
    root["city"] = "New York";

    std::cout<<"Generated Json: "<<root.toStyledString()<<std::endl;

    //访问json对象的成员
    std::cout<<"name: "<<root["name"].asString()<<std::endl;
    std::cout<<"age: "<<root["age"].asInt()<<std::endl;
    std::cout<<"city: "<<root["city"].asString()<<std::endl;



    return 0;   
}