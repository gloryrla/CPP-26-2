#include <iostream>
using namespace std;

int main() {
    long fact = 1;
    int n;  //곱하기 연산하면 커지니까 int보다 큰 변수 생성

    cout << "정수를 입력하시오: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
        fact = fact * i;


    cout << n << "!은 " << fact << "입니다.\n";
    
    return 0;
    
}