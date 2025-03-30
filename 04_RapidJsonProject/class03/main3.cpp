#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

int main(){
    //Json数组
    const char* json = R"({
                        "name": "John",
                        "age": 30,
                        "address": {
                            "street": "5th Avenue",
                            "city": "New York"
                            }
                        })";

    //Document
    rapidjson::Document doc;
    doc.Parse(json);

    // 创建一个StringBuffer用于保存格式化后的json字符串
    rapidjson::StringBuffer buffer;

    //创建PrettyWriter独享，传入StringBuffer
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);

    //将json数据格式化，并输出到stringBuffer
    doc.Accept(writer);

    //输出格式化后的Json字符串
    std::cout<<"格式化后的json数据："<<std::endl;
    std::cout<<buffer.GetString()<<std::endl;
    

    return 0;
}