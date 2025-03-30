#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

int main()
{
    //创建一个Document对象
    rapidjson::Document doc;

    //创建一个json对象
    rapidjson::Value obj(rapidjson::kObjectType);

    //创建一个Allocator
    rapidjson::Document::AllocatorType& allocator = doc.GetAllocator();

    //向对象中添加成员（键值对）
    obj.AddMember("name", "John", allocator);
    obj.AddMember("age", 20, allocator);

    //输出json数据
    rapidjson::StringBuffer buffer;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);

    obj.Accept(writer);

    //打印输出json
    std::cout<<buffer.GetString()<<std::endl;

    return 0;
}