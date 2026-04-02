#include <iostream>
#include <string>

// 文字列を返す関数
std::string getMessage() {
    return "Hello Sonar!";
}

int main() {
    // 【わざとバグ：一時オブジェクトのポインタ保持】
    // getMessage()が返した一時的な string オブジェクトは、
    // この行が終わった瞬間に消滅します。
    // その結果、ptr は「もう存在しない場所」を指すことになり、
    // 次の行で std::cout をした瞬間に「未定義動作（バグ）」となります。
    const char* ptr = getMessage().c_str(); 

    std::cout << ptr << std::endl; 
    return 0;
}
