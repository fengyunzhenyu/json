#include "json.hpp"
#include <fstream>
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
    //创建的json数据
    std::cout<<"Create Json:"<<std::endl;
    std::cout<<_json.dump(4)<<std::endl;

    //修改json对象的某个字段
    //判断是否包含 age 字段，且是数字
    if(_json.contains("age") && _json["age"].is_number())
        _json["age"] = 40;
    if(_json.contains("city") && _json["city"].is_string())
        _json["city"] = "Los Angeles";
    if(_json.contains("email") && _json["email"].is_string())
        _json["email"] = "xxxx@qq.com";
    else
        std::cout<<"Json not find email key"<<std::endl;
    

    std::cout<<"modified Json:"<<std::endl;
    std::cout<<_json.dump(4)<<std::endl;

    // //删除age键
    // _json.erase("age");

    // std::cout<<"Delete Json: "<<std::endl;
    // std::cout<<_json.dump(4)<<std::endl;

    // //将json数据保存到文件中
    // std::ofstream o("output.json");
    // o<<std::setw(4)<<_json<<std::endl; //格式化输出（4个空格缩进）
    // std::cout<<"Json data save to file!"<<std::endl;

    // //从文件夹中读取json数据
    // std::ifstream i("output.json");
    // nlohmann::json _i_json;
    // i >> _i_json; //读取json数据到json对象中
    // std::cout<<"Read json data from file: "<<std::endl;
    // std::cout<<_i_json.dump(4)<<std::endl;
    return 0;
}