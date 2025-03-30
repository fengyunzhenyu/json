#include "json.hpp"
#include <iostream>

int main()
{
    //创建json对象
    nlohmann::json _json = {
        {"name", "Alice"},
        {"age", 25},
        {"city", "New York"}
    };

    //输出json
    std::cout<<_json.dump(4)<<std::endl;

    return 0;
}