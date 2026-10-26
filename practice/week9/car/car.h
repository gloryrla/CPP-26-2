#include <iostream>
#include <string>
using namespace std;

class Car{
    //접근 지정자 기본값 private
    int speed;  //속도
    int gear;  //기어
    string color;  //색상

public:
    int getSpeed();
    void setSpeed(int s);
};