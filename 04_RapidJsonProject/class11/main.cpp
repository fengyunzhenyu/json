#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include <fstream>

//使用内存池优化json解析
void ParseWithMomeryPool(const char* json){
    char buffer[65536]; //预分配64KB
    //创建内存池分配器
    rapidjson::MemoryPoolAllocator<> allocator(buffer, sizeof(buffer));

    //使用内存池分配器解析json
    rapidjson::Document doc(&allocator);
    doc.Parse(json);

    //输出生成的json
    {
        rapidjson::StringBuffer buffer;
        rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);
        doc.Accept(writer);

        std::cout<<"Generated Json: "<<buffer.GetString()<<std::endl;
    }
}

int main()
{

    const char* json_str =R"({"message": "使用内存池加速"})";
    ParseWithMomeryPool(json_str);
    return 0;
}