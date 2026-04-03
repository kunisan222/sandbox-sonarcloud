#include <iostream>
#include <string>
#include <vector>

// 1. メモリリーク: new したのに delete していない
void trigger_memory_leak() {
    int* data = new int[100];
    data[0] = 42;
    // delete[] data; // ここをコメントアウトしてリークさせる
}

// 2. 未定義の動作: 範囲外アクセス
void trigger_out_of_bounds() {
    std::vector<int> vec = {1, 2, 3};
    int val = vec[10]; // 範囲外アクセス
    std::cout << val << std::endl;
}

int main() {
    std::cout << "Starting full analysis test..." << std::endl;

    // 3. ダングリングポインタ: 寿命が切れた文字列のポインタを参照
    const char* p;
    {
        std::string s = "Dangling Pointer Test";
        p = s.c_str();
    }
    // ここで p を使うのは危険！
    std::cout << "Dangerous pointer access: " << *p << std::endl;

    trigger_memory_leak();
    trigger_out_of_bounds();

    return 0;
}
// Force analysis update２
