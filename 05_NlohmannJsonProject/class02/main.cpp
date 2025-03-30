#include "json.hpp"
#include <iostream>

int main()
{
    //json字符串
    std::string json_str = R"({"name":"Alice", "age":25, "city":"New York"})";
    //json数组
    std::string json_arr = R"([{"name":"Alice", "age":25, "city":"New York"},{"name":"Bob", "age":20, "city":"Beijing"}])";

    //解析json字符串
    nlohmann::json _json = nlohmann::json::parse(json_str);

    //访问Json对象的值
    std::cout<<"name: "<<_json["name"]<<std::endl;
    std::cout<<"age: "<<_json["age"]<<std::endl;
    std::cout<<"city: "<<_json["city"]<<std::endl;

    //格式化输出
    std::cout<<"Parsed Json:"<<std::endl;
    //格式化 4 表示缩进的空格数
    std::cout<<_json.dump(4)<<std::endl; 

    //解析json数组
    nlohmann::json _arr = nlohmann::json::parse(json_arr);

    //格式化输出Json数组
    std::cout<<"Parsed Json Array:"<<std::endl;
    std::cout<<_arr.dump(4)<<std::endl; 
    return 0;
}