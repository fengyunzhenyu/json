#include <iostream>
#include "json/json.h"

int main(){
    //定义一个json字符串
    std::string jsonString = R"({"name":"John", "age":30, "city":"New York"})";

    //创建一个CharReaderBuilder实例，构建解析器
    Json::CharReaderBuilder readerBuilder;
    //用于存储解析的结果
    Json::Value root;
    std::string errs;

    std::istringstream iss(jsonString);
    //使用CharReaderBuilder 创建CharReader并解析字符串
    if(Json::parseFromStream(readerBuilder, iss, &root, &errs)){
        //解析成功
        std::cout<<"name: "<<root["name"].asString()<<std::endl;
        std::cout<<"age: "<<root["age"].asInt()<<std::endl;
        std::cout<<"city: "<<root["city"].asString()<<std::endl;

    }

    //创建StreamWriterBuilder
    Json::StreamWriterBuilder writerBuilder;
    //定义输出格式（添加缩进）
    writerBuilder["indentation"] = "  ++";//设置缩进为空格 加号
    //将json对象转换成为字符串 格式化的
    std::string json_str = Json::writeString(writerBuilder, root);

    std::cout<<"Formatted Json :"<<std::endl;
    std::cout<<json_str<<std::endl;


    //创建StyledStreamWriter
    Json::StyledStreamWriter styledWriter;
    //输出格式化的json字符串
    std::cout<<"Styled Formatted Json: "<<std::endl;
    styledWriter.write(std::cout, root); //输出到控制台
    
    return 0;
}