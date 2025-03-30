#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include <fstream>

int main()
{

    rapidjson::Document doc;
    //设置文档为对象类型
    doc.SetObject();

    //获取分配器
    rapidjson::Document::AllocatorType& alloctor = doc.GetAllocator();

    //向文档中添加成员
    doc.AddMember("name", "John", alloctor);
    doc.AddMember("age", 30, alloctor);
    doc.AddMember("city", "New York", alloctor);

    //输出生成的json
    {
        rapidjson::StringBuffer buffer;
        rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);
        doc.Accept(writer);

        std::cout<<"Generated Json: "<<buffer.GetString()<<std::endl;
    }
    //修改数据
    if(doc.HasMember("age") && doc["age"].IsInt()){
        doc["age"].SetInt(35);//修改年龄
    }

    doc["name"].SetString("王五", alloctor);

    //输出修改后的json
    {
        rapidjson::StringBuffer buffer;
        rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);
        doc.Accept(writer);
    
        std::cout<<"Modified Json: "<<buffer.GetString()<<std::endl;
    }

    //删除city 成员
    doc.RemoveMember("city");

    //输出删除后的json
    {
        rapidjson::StringBuffer buffer;
        rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);
        doc.Accept(writer);
    
        std::cout<<"remove Json: "<<buffer.GetString()<<std::endl;
    }

    //输出到文件
    std::ofstream ofs("output.json");
    {
        rapidjson::StringBuffer buffer;
        rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);
        doc.Accept(writer);
        ofs<<buffer.GetString();

        std::cout<<"Json saved to outpu.json"<<std::endl;
    }

    return 0;
}