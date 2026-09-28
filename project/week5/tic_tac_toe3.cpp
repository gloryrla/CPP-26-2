#include <iostream>
using namespace std;

int main() {
    const int numCell = 3;
    char borad[numCell][numCell]{};
    int x, y; //사용자에게 입력 받는 x, y 좌표를 저장할 변수
    int count = 0; //보드칸에 사용자가 돌을 놓은 횟수을 저장할 변수

    //보드판 초기화
    for (x = 0; x < numCell; x++){
        for (y = 0; y < numCell; y++){
            borad[x][y] = ' ';
        }
    }


    //게임하는 코드
    int k = 0; //누구 차례인지 체크하기 위한 변수
    char currentUser = 'x'; //현재 유저의 돌을 저장하기 위한 문자 변수
    while (true){
        //1. 누구 차례인지 출력
        switch (k % 3){
        case 0:
            cout << k % 2 + 1 << "번 유저(x)의 차례입니다 -> ";
            currentUser = 'x';
            break;
        
        case 1:
            cout << k % 2 + 1 << "번 유저(o)의 차례입니다 -> ";
            currentUser = 'o';
            break;   
            
        case 2:
            cout << k % 2 + 1 << "번 유저(^)의 차례입니다 -> ";
            currentUser = '^'; //세모는 1바이트 넘어서 대체했습니다!
            break;       
        }        

        //2. 좌표 입력 받기
        cout << "(x, y) 좌표를 입력하세요: ";
        cin >> x >> y;

        //3. 입력받은 좌표의 유효성 체크
        if (x >= numCell || y >= numCell){
            cout << x << ", " << y << ": ";
            cout << " x와 y 둘 중 하나가 칸을 벗어납니다. " << endl;
            continue;
        }
        if (borad[x][y] != ' '){
            cout << x << ",  " << y << ": 이미 돌이 차있습니다." << endl;
            continue;
        }

        //4. 입력받은 좌표에 현재 유저의 돌 놓기
        borad[x][y] = currentUser;
        count++; //유저가 돌 놓으면 횟수 추가 
    

       


        //5. 현재 보드 판 출력
        for (int i = 0; i < numCell; i++) {
            cout << "---|---|---" << endl;
            for (int j = 0; j < numCell; j++){
                cout << borad[i][j];
                if (j == numCell - 1) {
                    break;
                }
                cout << "  |";
            }
            cout << endl;
        }
        cout << "---|---|---" << endl;
        k++;
        



        bool flag = false; //승자 체크하기
         //빙고 시 승자 출력 후 종료(가로, 세로, 대각선)
        //가로 & 세로  검증
        for (int i = 0; i < numCell; i++){
            if (borad[i][0] == borad[i][1] && borad[i][1] == borad[i][2] && borad[i][1] == currentUser){
                cout << "가로에 모두 돌이 놓였습니다!: " << k % 2 + 1 << "번 유저의(" << currentUser << ")의 승리입니다!";
                flag = true;
                break;
            }
            if (borad[0][i] == borad[1][i] && borad[1][i] == borad[2][i] && borad[1][i] == currentUser){
                cout << "세로에 모두 돌이 놓였습니다!: " << k % 2 + 1 << "번 유저의(" << currentUser << ")의 승리입니다!";
                flag = true;
                break;
            }
        }   


        //대각선 검증
        if (borad[0][0] == borad[1][1] && borad[1][1] == borad[2][2] && borad[1][1] == currentUser){
            cout << "대각선에 모두 돌이 놓였습니다!: " << k % 2 + 1 << "번 유저의(" << currentUser << ")의 승리입니다!";
            flag = true;
            break;
        }
        if (borad[0][2] == borad[1][1] && borad[1][1] == borad[2][0] && borad[1][1] == currentUser){
            cout << "대각선에 모두 돌이 놓였습니다!: " << k % 2 + 1 << "번 유저의(" << currentUser << ")의 승리입니다!";
            flag = true;
            break;
        }
        

        if (flag) {
            cout << k % 2 + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
            cout << "종료합니다" << endl;
            break;
        }
        

        //모든 칸이 다 찬 경우 종료 -> 유저가 돌을 놓은 횟수가 칸보다 넘게 되면 종료
        if (count >= numCell * numCell){
            cout << "모든 칸이 다 찼습니다. 종료합니다.";
            break;
        }
       

    }
    
    return 0;

    
}