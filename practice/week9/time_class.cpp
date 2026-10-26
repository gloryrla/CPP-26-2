#include <iostream>
using namespace std;

class Time {
public:
    int hour;   //시를 나타낸다. 0-23가  가능하다.
    int minute;  //분을 나타낸다. 0-59가 가능하다.

    Time() {}  //오버로딩
    Time(int h, int m) {
        hour = h;
        minute = m;
    }


    void Print() {
        cout << hour << ":"  << minute << endl;
    }
};

int main() {
    
    
    Time a;  //1. 오버로딩으로 해결!
    Time b (10, 25);  //2. OK 하지만 예전의 방법이다.
    Time c {10, 25};  //3. OK 최선의 방법이다. 
    Time d = {10, 25};  //4. OK 하지만 간결하지 않다.


    a.Print();
    b.Print();
    c.Print();
    d.Print();

    return 0;
}