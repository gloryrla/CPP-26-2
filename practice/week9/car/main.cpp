#include <iostream>
#include "car.h"
using namespace std;

int main() {
    Car myCar;

    myCar.setSpeed(80);  //Car 클래스 속도 80 초기화
    cout << "현재 속도는 : ";
    cout << myCar.getSpeed(); //Car 클래스내 public 함수 

    return 0;

}