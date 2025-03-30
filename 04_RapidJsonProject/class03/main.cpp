#include <iostream>
#include "rapidjson/document.h"

int main(){
    //Json数组
    const char* json = R"({"cities": ["北京", "上海", "广州"]})";

    //Document
    rapidjson::Document doc;
    doc.Parse(json);

    if(doc.HasMember("cities") && doc["cities"].IsArray()){
        const rapidjson::Value& cities = doc["cities"];
        for(size_t i = 0; i < cities.Size(); i++){
            std::cout<<"城市 "<<i+1<<" : "<<cities[i].GetString()<<std::endl;
        }
    }

    return 0;
}