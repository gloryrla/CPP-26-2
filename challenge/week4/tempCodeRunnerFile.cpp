#include <iostream>
using namespace std;

int main() {
    int vowel = 0; //모음 개수 a, e, i, o , u   
    int consosnat = 0; // 자음 개수
    int count = 0; //천제 입력 개수

    cout << "영문자를 입력하고 ctrl + z를 치세요" << endl;

    char ch;

    while (cin >> ch) {
        
        switch (ch){
        case 'a':
        case 'e':
        case 'i':;
        case 'o':
        case 'u':
            vowel++;
            break;
        
        default:
            consosnat++;
        }

    
    }

    cout << "모음: " << vowel << endl;
    cout << "자음: " << consosnat << endl;
    return 0;
}