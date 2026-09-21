#include <iostream>
#include <time.h>
using namespace std;

int main() {
    srand(time(NULL));

    int answer = rand() % 100;
    int tries = 0;
    

    int guess;


   while(true){
        cout << "정답을 추측하여 보시오: ";
        cin >> guess;

        if (guess > answer){
            cout << "제시한 정수보다 낮습니다." << endl;
            tries++;
        } else if (guess < answer){
            cout << "제사한 정수보다 높습니다." << endl;
            tries++;
        }

        if (answer == guess) {
            cout << "축하합니다 시도 횟수;  "  << tries << endl;
            break;
        }
   }


    return 0;
}