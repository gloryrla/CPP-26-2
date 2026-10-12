#include <iostream>
#include <string>
using namespace std;


//아스키코드 기준으로 소문자 대문자 오프셋은 32
//소문자 시작은 96부터 그 이하는 대문자
//대문자 라면 오프셋 더해서 소문자 만들기
string toLowerStr(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] < 96){    
            str[i] += 32;
        }
        }
    return str;
}

//소문자 시작은 96부터 그 이하는 대문자
//소문자라면 오프셋 빼서 대문자 만들기
string toUpperStr(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] > 96){    
            str[i] -= 32;
        }
        }
    return str;
}


//각 문자열 대문자로 변환 후 해밍 거리 측정하기 
void calcHammingDist(string s1, string s2) {
    int count = 0;
    string str1 = toUpperStr(s1);
    string str2 = toUpperStr(s2);


    // 문자열 길이가 다르면 오류 문자 출력
    if (str1.length() != str2.length())
        cout << "오류: 길이가 다름 " << endl;
    else {
        for (int i = 0; i < str1.length(); i++) {
            if (str1[i] != str2[i]) 
                count += 1;
        }

        cout << "해밍 거리는 " << count << endl;
    }

}

int main() {
    string s1, s2;

    cout << "str1: ";
    cin >> s1;
    cout << "str2: ";
    cin >> s2;

    calcHammingDist(s1, s2);

    return 0;
}
