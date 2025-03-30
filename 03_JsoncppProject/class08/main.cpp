#include <iostream>
#include <fstream>
#include "json/json.h"

int main()
{
    std::map<std::string, std::string> _map = {
        {"name", "John"},
        {"age", "30"},
        {"city", "New York"}
    };

    Json::Value root;
    for (const auto& item: _map)
    {
        root[item.first] = item.second;
    }
    
    std::cout<<root.toStyledString()<<std::endl;

    return 0;
}