#include <iostream>
#include <string>
using namespace std;

int main() {

    string s1 = "사과";
    string s2;
    //s2 = s1 + " " + 10 + "개"; -> 더하려는 타입의 형이 달라서 에러가 발생합니다.
    s2 = s1 + " " + to_string(10) + "개";
    cout << s2 << endl;

}