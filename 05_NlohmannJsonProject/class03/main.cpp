#include "json.hpp"
#include <iostream>

int main()
{
    std::string json_str = R"({
        "name": "Alice",
        "address": {
            "street": "123 Main St",
            "city": "New York"
        },
        "skills":["Json", "C++", "Java"],
        "age": 25
    })";

    //解析json字符串
    nlohmann::json _json = nlohmann::json::parse(json_str);

    //格式化输出
    std::cout<<"Parsed Json:"<<std::endl;
    std::cout<<_json.dump(4)<<std::endl;

    //访问对象
    std::cout<<"name: "<<_json["name"]<<std::endl;
    std::cout<<"street: "<<_json["address"]["street"]<<std::endl;
    std::cout<<"city: "<<_json["address"]["city"]<<std::endl;
    std::cout<<"age: "<<_json["age"]<<std::endl;

    //遍历json对象
    std::cout<<"Iterating over Json object:"<<std::endl;
    for(auto& el: _json.items()){ //item返回一个键值对的迭代器
        std::cout<<"key: "<<el.key()<<", value: "<<el.value()<<std::endl;
    }

    //另外一种
    std::cout<<"-----------------------------------"<<std::endl;
    for(auto& [key, value]: _json.items()){
        std::cout<<key<<" : "<<value<<std::endl;
    }

    //遍历数组
    std::cout<<"-----------------------------------"<<std::endl;
    std::cout<<"Iterating over Json Array: "<<std::endl;
    for(auto& el: _json["skills"]){
        std::cout<<el<<std::endl;
    }
    //使用索引
    for (size_t i = 0; i < _json["skills"].size(); i++)
    {
        std::cout<<"Index: "<<i<<", value: "<<_json["skills"][i]<<std::endl;
    }
    
    return 0;
}