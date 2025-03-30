#include "json.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <map>

int main()
{
    //vector 转 json
    //创建vector
    std::vector<std::string> names = {"Alice", "Bob", "Charlie"};

    //将vector转为json数组
    nlohmann::json _json = names;

    //输出json数组
    std::cout<<"Json array: "<<_json.dump(4)<<std::endl;

    //创建map
    std::map<std::string, int> data = {
        {"age", 25},
        {"height", 180},
        {"weight", 80}
    };

    //将map转换为json对象
    nlohmann::json _json_map = data;
    //输出json数组
    std::cout<<"Json map: "<<_json_map.dump(4)<<std::endl;
    return 0;
}