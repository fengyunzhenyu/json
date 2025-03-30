#include "rapidjson/document.h"
#include "rapidjson/reader.h"
#include <iostream>
#include <fstream>

using namespace rapidjson;

// 自定义 SAX 事件处理器
class MyHandler : public BaseReaderHandler<UTF8<>, MyHandler> {
public:
    bool Key(const Ch* str, SizeType length, bool copy) {
        // 如果遇到键名为name或者age，则处理它们
        if (std::string(str, length) == "name") {
            currentKey = "name";
        } else if (std::string(str, length) == "age") {
            currentKey = "age";
        }
        return true;
    }

    bool String(const Ch* str, SizeType length, bool copy) {
        if (currentKey == "name") {
            std::cout << "User Name: " << std::string(str, length) << std::endl;
        }
        return true;
    }

    bool Uint(unsigned u) {
        if (currentKey == "age") {
            std::cout << "Age: " << u << std::endl;
        }
        return true;
    }

    // 用于标记当前解析的键
    std::string currentKey;            
};

void ParseJSONFileWithSAX(const char* filename) {
    // 打开文件并读取内容
    std::ifstream ifs(filename);
    std::string json((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());

    // 使用 RapidJSON 提供的 StringStream
    rapidjson::StringStream ss(json.c_str());
    
    MyHandler handler;
    Reader reader;
    
    // 使用 StringStream 作为输入流
    reader.Parse(ss, handler);
}

int main() {
    const char* filename = "output.json";
    ParseJSONFileWithSAX(filename);
    return 0;
}