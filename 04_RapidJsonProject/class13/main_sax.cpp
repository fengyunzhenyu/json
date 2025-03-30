#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/reader.h"
#include <iostream>
#include <fstream>

//继承Handler类，实现Sax解析的回调方法
class MyHandler: public rapidjson::BaseReaderHandler<rapidjson::UTF8<>, MyHandler>
{
public:
    bool Key(const Ch* str, rapidjson::SizeType len, bool copy) 
    { 
        std::cout<<"Key: "<<std::string(str, len)<<std::endl;
        return true; 
    }
    bool String(const Ch* str, rapidjson::SizeType len, bool copy) 
    { 
        std::cout<<"Value: "<<std::string(str, len)<<std::endl;
        return true; 
    }
    bool Int(int i) 
    { 
        std::cout<<"Int: "<<i <<std::endl;
        return true; 
    }
    bool Uint(unsigned u) 
    { 
        std::cout<<"Uint: "<<u<<std::endl;
        return true; 
    }
};

int main()
{
    //json数据
    const char* json_str = R"({"name": "Alice", "age":25, "city":"New York"})";

    //创建Reader对象
    rapidjson::Reader reader;
    rapidjson::StringStream ss(json_str);

    MyHandler hander;

    //解析Json（sax方式）
    reader.Parse(ss, hander);

    return 0;
}