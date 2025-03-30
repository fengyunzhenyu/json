#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/reader.h"
#include <iostream>
#include <fstream>

//自定义sax 事件处理器
class MyHandler: public rapidjson::BaseReaderHandler< rapidjson::UTF8<>, MyHandler>{
public:
    bool Key(const Ch* str, rapidjson::SizeType len, bool copy)
    {
        // std::cout<<"Key: "<<std::string(str, len)<<std::endl;
        //如果遇到键值为name age，处理
        if(std::string(str, len) == "name"){
            currentKey = "name";
        }
        else if(std::string(str, len) == "age"){
            currentKey = "age";
        }
        return true;
    }

    bool String(const Ch* str, rapidjson::SizeType len, bool copy) 
    { 
        // std::cout<<"String: "<<std::string(str, len)<<std::endl;
        if(currentKey == "name")
        {
            std::cout<<"User Name: "<<std::string(str, len)<<std::endl;
        }
        return true; 
    }
    bool Int(int i) 
    { 
        std::cout<<"Int: "<<i<<std::endl;
        return true; 
    }
    bool Uint(unsigned u) 
    { 
        // std::cout<<"Uint: "<< u<<std::endl;
        if(currentKey == "age")
        {
            std::cout<<"Age: "<<u<<std::endl;
        }
        return true; 
    }


    //.....
    std::string currentKey;//用于标记当前解析的Key
};

void ParseJsonFileWithSax(const char* filename)
{
    //打开文件并读取内容
    std::ifstream ifs(filename);
    std::string json_str((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());

    //使用RapidJson提供的StringStream
    rapidjson::StringStream ss(json_str.c_str());

    MyHandler handler;
    rapidjson::Reader reader;

    //使用stringStream作为输入流
    reader.Parse(ss, handler);
}

int main(){
    const char* filename = "output.json";
    ParseJsonFileWithSax(filename);
    return 0;
}