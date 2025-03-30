#include <iostream>
#include "rapidjson/document.h"

int main()
{
    //初始化为整数
    rapidjson::Value val1(10);
    //初始化为字符串
    rapidjson::Value val2("hello world!");
    //初始化为布尔值
    rapidjson::Value val3(true);
    rapidjson::Value val4(false);

    //初始化为空的对象
    rapidjson::Value val5(rapidjson::kObjectType);



    std::cout<<"val1 = "<<val1.GetInt()<<std::endl;
    std::cout<<"val2 = "<<val2.GetString()<<std::endl;
    std::cout<<"val3 = "<<(val3.GetBool()?"true":"false")<<std::endl;
    std::cout<<"val4 = "<<(val4.GetBool()?"true":"false")<<std::endl;
    // std::cout<<"val5 = "<<val5.GetObject()<<std::endl;

    std::cout<<"val1 double = "<<val1.GetDouble()<<std::endl;
    return 0;
}