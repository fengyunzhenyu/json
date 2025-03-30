#include "json.hpp"
#include <iostream>

int main()
{
    //1 创建json对象
    nlohmann::json _json = {
        {"name", "Alice"},
        {"age", 25},
        {"city", "New York"},
        {"skills", {"C++", "Json", "Python"}}
    };

    std::cout<<_json.dump(4)<<std::endl;

    //2 创建json对象
    nlohmann::json _json2;
    _json2["name"] = "Eve";
    _json2["age"] = 35;
    _json2["city"] = "Beijing";
    _json2["skills"].push_back("Rust");
    _json2["skills"].push_back("Java");
    std::cout<<_json2.dump(4)<<std::endl;

    //3 创建数组
    // nlohmann::json arr = {"Alice", "Bob", "Charlie"};
    nlohmann::json arr = nlohmann::json::array({1,2,3,4});
    std::cout<<arr.dump(4)<<std::endl;
    return 0;
}