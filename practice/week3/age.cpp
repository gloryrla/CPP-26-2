#include <iostream>
using namespace std;

int main() {
    
    int age;
<<<<<<< HEAD
    cout << "나이를 입력해주세요!: ";
=======
    cout << "나이를 입력해: ";
>>>>>>> 90e5b461ddd70f5bbb7c2ec8cca43c01b16ebde9
    cin >> age;

    if (age <= 12)
        cout << "어린이입니다." << endl;
    else if ( age <= 19)
        cout << "청소년입니다." << endl;
    else
        cout << "성인입니다." << endl;


    return 0;
}
