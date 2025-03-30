#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

int main()
{
    //创建一个Document对象
    rapidjson::Document doc;

    //创建一个json对象
    rapidjson::Value arr(rapidjson::kArrayType);

    //创建一个json对象
    rapidjson::Value obj(rapidjson::kObjectType);

    //创建一个Allocator
    rapidjson::Document::AllocatorType& allocator = doc.GetAllocator();

    //向数组中添加元素
    arr.PushBack(1, allocator);
    arr.PushBack(2, allocator);
    arr.PushBack(3, allocator);

    //向对象中添加成员（键值对）
    obj.AddMember("name", "John", allocator);
    obj.AddMember("age", 20, allocator);

    obj.AddMember("array", arr, allocator);


    //输出json数据
    // rapidjson::StringBuffer buffer;
    // rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);

    // arr.Accept(writer);

    // //打印输出json数组
    // std::cout<<buffer.GetString()<<std::endl;

    // //获取值类型
    // rapidjson::Value& age = obj["age"];
    // if(age.GetType() == rapidjson::kNumberType){
    //     std::cout<<"age is a number!"<<std::endl;
    // }

    // //访问对象成员
    // rapidjson::Value& name = obj["name"];
    // std::cout<<"name = "<<name.GetString()<<std::endl;

    // //访问数组
    // std::cout<<"Array first element: "<<arr[0].GetInt()<<std::endl;
    // for(size_t i = 0; i < arr.Size(); i++)
    // {
    //     std::cout<<"Array "<<i+1<<" element: "<<arr[i].GetInt()<<std::endl;
    // }

    // //修改对象的数据
    // std::cout<<" before name = "<<obj["name"].GetString()<<std::endl;
    // obj["name"] = "Alice";
    // std::cout<<" after name = "<<obj["name"].GetString()<<std::endl;

    //数组
    arr[0] = 100;
    arr[1] = 200;
    rapidjson::StringBuffer buffer1;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer1(buffer1);
    arr.Accept(writer1);
    //打印输出json数组
    std::cout<<"updated array: "<<buffer1.GetString()<<std::endl;

    //删除对象中的成员
    obj.RemoveMember("age");
    rapidjson::StringBuffer buffer2;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer2(buffer2);
    obj.Accept(writer2);
    //打印输出json对象
    std::cout<<"updated obj: "<<buffer2.GetString()<<std::endl;

    //删除数组中的元素
    arr.Erase(arr.Begin());//删除数组中的第一个元素
    rapidjson::StringBuffer buffer3;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer4(buffer3);
    arr.Accept(writer4);
    //打印输出json数组
    std::cout<<"Delete array: "<<buffer3.GetString()<<std::endl;

    return 0;
}