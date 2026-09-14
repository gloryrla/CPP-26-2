#include <iostream>
#include <string>
using namespace std;

int main() {
    
    int amount; //현재 가지고 있는 돈
    int price; //캔디의 가격
    int count; //살 수 있는 캔디 개수
    int change; //캔디 구입 후 남은 돈

    cout << "현재 가지고 있는 돈: ";
    cin >> amount;

    cout << "캔디의 가격: ";
    cin >> price;

    count = amount / price;
    change = amount - price * count;

    cout << "최대로 살 수 있는 캐디 = " + to_string(count) << endl;
    cout << "캔디 구입 후 남은 돈 = " + to_string(change) << endl;
    
}
