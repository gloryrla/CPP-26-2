#include <iostream>
#include <string>
using namespace std;


int main(void) {

    vector<int> scores;
    int i;
    int cnt = 0;
    int sum = 0;

    while (true) {
        cout << "성적을 입력하시오 (종료는 -1) :";
        cin >> i;
        
        if (i == -1) {
            break;
        } else {
            scores.push_back(i);  //백테에 값 push
            cnt++;  //입력 횟수 증가
            sum += i; //전체 성적 값에 입력 성적 더하기 
        }

       
    }
  
    // 전체 성적 값에서 입력 횟수로 나누기 출력
    cout << "1. 성적 평균 = " << sum / cnt << endl;

    //동적 배열을 통해 구하기

    sum = 0;

    for(auto& value: scores) {
        sum += value;
    }
    double avg = (double) sum / scores.size();
    cout << "2. 성적 평균 = " << avg << endl;
     
    return 0;

}