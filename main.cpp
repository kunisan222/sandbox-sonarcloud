#include <iostream>
#include <string>

int main() {
    // 既存のコード（バグがある部分）
    std::string s = "Hello";
    const char* p = (s + " World").c_str(); 
    
    // 【新しく追加】わざとらしいメモリリーク（解析対象を増やす）
    int* leak = new int[100]; 
    
    std::cout << p << std::endl;
    return 0;
}
