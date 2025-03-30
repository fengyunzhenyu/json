#include "json.hpp"
#include <fstream>
#include <iostream>

int main()
{
    //与std：：vector转换
    //创建json数组
    nlohmann::json _json = {"Alice", "Bob", "Charlie"};

    //将json数组转换为vector
    std::vector<std::string> names = _json.get<std::vector<std::string>>();

    //输出std::vector内容
    std::cout<<"names Vector: "<<std::endl;
    for(const auto& name: names){
        std::cout<<name<<std::endl;
    }

    //转化成map
    //创建json对象
    nlohmann::json json_map = {
        {"name", "Alice"},
        {"age", 25}, 
        {
            "city","New York"
        }
    };

    //将json对象转换成map
    std::map<std::string, nlohmann::json> data = json_map.get<std::map<std::string, nlohmann::json>>();

    //输出map内容
    std::cout<<"Data Map: "<<std::endl;
    for(const auto& item:data){
        std::cout<<item.first<<" : "<<item.second<<std::endl;
    }
    return 0;
}