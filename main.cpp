#include <iostream>
#include <string>
#include <vector>

// 構造を大きく変えるために新しい関数を追加
void leaky_function() {
    int* leak = new int[100]; // わざとらしいメモリリークその1
    leak[0] = 10;
    // delete[] leak; // あえてコメントアウト
}

int main() {
    std::cout << "Starting new analysis test..." << std::endl;

    // 前回のバグも残しつつ、少し形を変える
    std::string s1 = "Sonar";
    std::string s2 = "Cloud";
    const char* p = (s1 + s2).c_str(); // ダングリングポインタ（危険！）

    leaky_function();

    // 未使用の変数（これも指摘対象になるはず）
    int unused_variable = 42;

    std::cout << "Result: " << p << std::endl; 
    return 0;
}
