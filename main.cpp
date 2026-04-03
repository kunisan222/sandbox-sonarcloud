#include <iostream>
#include <string>

// 解析を走らせるためのテストコメント
int main() {
    std::string s = "Hello";
    const char* p = (s + " World").c_str(); 
    std::cout << p << std::endl;
    return 0;
}
