#include <iostream>
#include "json/json.h"

int main()
{
    //创建一个json数组
    Json::Value array(Json::arrayValue);
    Json::Value obj1;
    obj1["name"] = "John";
    obj1["age"] = 30;

    Json::Value obj2;
    obj2["name"] = "Alice";
    obj2["age"] = 25;

    array.append(obj1);
    array.append(obj2);

    std::cout<<"Generated Josn Array: "<<array.toStyledString()<<std::endl;

    //访问数组中的对象
    for(const auto& item : array){
        std::cout<<"Name: "<<item["name"].asString()<<", age: "<<item["age"].asInt()<<std::endl;

    }

    return 0;
}