#include <iostream>
#include <string>
using namespace std;

int main() {

    double fah; //화시온도
    double cel = (5.0/9.0) * (fah - 32); //섭씨 온도

    
    cout << "화씨온도: ";
    cin >> fah;

    //double cel = (5.0/9.0) * (fah - 32); //섭씨 온도

    cout << "섭씨 온도 = " << cel << endl;


}