#include <iostream>
#include <string>
using namespace std;

int main() {

    const int STUDENT = 5;
    const int SUBEJECT = 3;
    int scores[STUDENT][SUBEJECT];
    string studentName[STUDENT]
                = {"영수", "영희", "철수", "미미", "쥬쥬"};
    string subjectName[SUBEJECT]
                = {"수학", "영어", "CPP"};
    
    for (int i = 0; i < STUDENT; i++){
        cout << studentName[i] << "의 성적을 하나씩 입력하세요." << endl;
        for (int j = 0; j < SUBEJECT; j++) {
            cout << subjectName[j] << ":";
            cin >> scores[i][j];
        }

    }

    for (int i = 0; i < STUDENT; i++){
        cout << studentName[i] << "의 평균 점수는 :";
        double sum = 0;
        double average = 0;
        for (int j = 0; j < SUBEJECT; j++) {
            sum += scores[i][j];
        }

        average = sum / SUBEJECT;
        cout << average << "입니다" << endl;
    }

    return 0;

}