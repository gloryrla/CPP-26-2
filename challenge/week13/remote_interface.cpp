#include <iostream>
using namespace std;

//리모컨 인터페이스 정의
class RemoteControl {
public:
    //순수 가상 함수 정의
    virtual void TurnON() = 0; // 가전 제품을 켠다
    virtual void TurnOFF() = 0; // 가전 제품을 끈다
};

//Tv 클래스 정의
class Television : public RemoteControl {
public:
    void TurnON() {
        cout << "TV를 켭니다." << endl;
    }

    void TurnOFF() {
        cout << "TV를 끕니다." << endl;
    }
};

//냉장고 클래스 정의
class Refrigerator : public RemoteControl {
public:
    void TurnON() {
        cout << "냉장고를 켭니다." << endl;
    }

    void TurnOFF() {
        cout << "냉장고를 끕니다." << endl;
    }
};

int main() {
    //TV를 켜고 끄는 동작을 인터페이스를 통해 수행
    RemoteControl* remoteTv =  new Television();
    remoteTv -> TurnON();
    remoteTv -> TurnOFF();
    
    RemoteControl* remoteRefigerator =  new Refrigerator();
    remoteRefigerator -> TurnON();
    remoteRefigerator -> TurnOFF();

    delete remoteTv, remoteRefigerator;
    return 0;

}