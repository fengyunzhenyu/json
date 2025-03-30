#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

int main()
{
    //创建一个Document对象
    rapidjson::Document doc;

    //创建一个json数组
    rapidjson::Value arr(rapidjson::kArrayType);

    //创建一个Allocator
    rapidjson::Document::AllocatorType& allocator = doc.GetAllocator();

    //向数组中添加元素
    arr.PushBack(1, allocator);
    arr.PushBack(2, allocator);
    arr.PushBack(3, allocator);


    //输出json数据
    rapidjson::StringBuffer buffer;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);

    arr.Accept(writer);

    //打印输出json数组
    std::cout<<buffer.GetString()<<std::endl;

    return 0;
}