#include <iostream>
#include <string>
using namespace std;

int main() {
    int number1, nubmber2;

    cout << "두 양수를 입력하세요: ";
    cin >> number1 >> nubmber2;

    if (number1 > 0 ) {
        if (nubmber2 > 0) {
            cout << number1 << " " << nubmber2 << " 두 숫자는 모두 양수입니다." << endl;
        }
        else {
            cout << number1 << "만 양수입니다." << endl;
        }
    }

    else {
        cout << number1 << "는 0이거나 음수입니다." << endl;
    }

    return 0;
}