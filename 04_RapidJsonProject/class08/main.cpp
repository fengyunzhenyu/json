#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filewritestream.h"
#include "fstream"

int main()
{
    //创建一个Document对象
    rapidjson::Document doc;
    //创建一个json对象
    rapidjson::Value obj(rapidjson::kObjectType);

    //创建一个allocator
    rapidjson::Document::AllocatorType& alloctor = doc.GetAllocator();

    //向对象中添加元素
    obj.AddMember("name", "John", alloctor);
    obj.AddMember("age", 30, alloctor);

    //创建一个json对象
    rapidjson::Value arr(rapidjson::kArrayType);
    //向数组中添加元素
    arr.PushBack(1, alloctor);
    arr.PushBack(2, alloctor);
    arr.PushBack(3, alloctor);

    obj.AddMember("array", arr, alloctor);

    //输出json数据
    rapidjson::StringBuffer buffer;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);
    obj.Accept(writer);

    //输出
    std::cout<<buffer.GetString()<<std::endl;

    //打开文件，写入json数据
    FILE* fp = fopen("output.json", "w");

    //创建一个字符缓冲区
    const size_t bufferSize = 65536;
    char writerBuffer[bufferSize];

    //创建一个FileWriterStream对象
    rapidjson::FileWriteStream fileStream(fp, writerBuffer, sizeof(writerBuffer));

    //创建一个writer对象，将json数据写入文件
    rapidjson::Writer<rapidjson::FileWriteStream> _writer(fileStream);
    obj.Accept(_writer);

    //关闭文件
    fclose(fp);

    return 0;
}