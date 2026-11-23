#include <iostream>
#include <string>
#include <vector>
#include "user.h"
using namespace std;

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(vector<vector<int>> map, int user_x, int user_y);
bool checkGoal(vector<vector<int>> map, int user_x, int user_y);
void checkState(vector<vector<int>> map, int user_x, int user_y, User& user);
void printInmap(bool inMap);
void moveUp(vector<vector<int>> map, int& user_x, int& user_y, User& user);
void moveDown(vector<vector<int>> map, int& user_x, int& user_y, User& user);
void moveLeft(vector<vector<int>> map, int& user_x, int& user_y, User& user);
void moveRight(vector<vector<int>> map, int& user_x, int& user_y, User& user);
bool CheckUser(User& user);


// 메인  함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
    // 2차원 배열 백터로 표현
	vector<vector<int>> map = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };



	// 유저의 위치를 저장할 변수
	int user_x = 0; // 가로 번호
	int user_y = 0; // 세로 번호

    //magician, warrior 담을 User 객체 생성
    User* user;

    //magicion, warrior 구분하기 위한 cnt
    int cnt = 0;

    //magician, warrior 유저객체 생성
    Magician magician;
    Warrior warrior;


	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프


        if (cnt % 2 == 0) {
            user = &magician;
            cout << "magicaion 차례입니다" << endl;
        } else {
            user = &warrior;
            cout << "warrior 차례입니다" << endl;
        }
        // 다음 차례를 위한 cnt 값 증가 
        cnt++; 

		// 사용자의 입력을 저장할 변수
		string user_input = "";

        //user 체력이 1미만이면 실패 출력
        CheckUser(*user);

		cout << "명령어를 입력하세요 (상,하,좌,우,지도,정보,종료): ";
		cin >> user_input;

		if (user_input == "상") {
            moveUp(map, user_x, user_y, *user);
		}
		else if (user_input == "하") {
            moveDown(map, user_x, user_y, *user);
		}
		else if (user_input == "좌") {
            moveLeft(map, user_x, user_y, *user);
		}
		else if (user_input == "우") {
            moveRight(map, user_x, user_y, *user);
		}
		else if (user_input == "지도") {
			// TODO: 지도 보여주기 함수 호출
			displayMap(map, user_x, user_y);
		}
        //정보 명령어 추가
        else if(user_input == "정보") {
            // 정보 입력시 cout << user << endl; 현재 사용자 정보 보여주게 개선
            cout << *user << endl;
        }
		else if (user_input == "종료") {
			cout << "종료합니다.";
			break;
		}
		else {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}

		// 목적지에 도달했는지 체크
		if (checkGoal(map, user_x, user_y)) {
			break;
		}

        // 도착지에 아이템.적.포션 확인 후 출력 및 유저 체력 변경
        checkState(map, user_x, user_y, *user);

	}
	return 0;
}


// 지도와 사용자 위치 출력하는 함수
void displayMap(vector<vector<int>> map, int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // 양 옆 1칸 공백
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6칸 공백
					break;
				case 1:
					cout << "아이템|";
					break;
				case 2:
					cout << "  적  |"; // 양 옆 2칸 공백
					break;
				case 3:
					cout << " 포션 |"; // 양 옆 1칸 공백
					break;
				case 4:
					cout << "목적지|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 후 도착 메시지 출력
bool checkGoal(vector<vector<int>> map, int user_x, int user_y) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
		return true;
	}
	return false;
}

// 도착지에 아이템.적.포션 확인 후 출력 및 유저 체력 변경
void checkState(vector<vector<int>> map, int user_x, int user_y, User& user) {
    // 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션
    switch (map[user_y][user_x]){
    case 0:
        //빈공간
        break;
    case 1: 
        cout << "아이템이 있습니다. " << endl;
        //아이템에 도달시 user 객체에 아이템 cnt 1증가
        user.IncreasedItemCnt();
        break;
    case 2:
        cout << "적이 있습니다. " << endl;
        //적 만나면 공력
        user.doAttack();
        //hp 감소되는 부분 객체의 DecreaseHP 맴버함수 호출로 진행
        user.DecreasedHP();
        user.DecreasedHP();
        cout << "HP가 2 줄어듭니다. " << endl;
        break;
    case 3:
        cout << "포션이 있습니다. " << endl;
        //hp 증가되는 부분 객체의 IncreaseHP 맴버함수 호출로 진행
        user.IncreasedHP();
        user.IncreasedHP();
        cout << "HP가 2 증가합니다. " << endl;
        break;   
    }
}

//위로 움직이는 함수
void moveUp(vector<vector<int>> map, int& user_x, int& user_y, User& user) {
     // 위로 한 칸 올라가기
        user_y -= 1;


        if (!checkXY(user_x, mapX, user_y, mapY)) {
            cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
        }
        else {
            cout << "위로 한 칸 올라갑니다." << endl;

            displayMap(map, user_x, user_y);

            // user hp 1 감소
            user.DecreasedHP();
        }
}

//아래로 움직이는 함수
void moveDown(vector<vector<int>> map, int& user_x, int& user_y, User& user) {
    // TODO: 아래로 한 칸 내려가기
    user_y += 1;

    if (!checkXY(user_x, mapX, user_y, mapY)) {
        cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
        user_y -= 1;
    } 
    else {
        cout << "위로 한 칸 내려갑니다." << endl;
        displayMap(map, user_x, user_y);
        
        // user hp 1 감소
        user.DecreasedHP();
    }
}

//왼쪽로 움직이는 함수
void moveLeft(vector<vector<int>> map, int& user_x, int& user_y, User& user) {
    // TODO: 왼쪽으로 이동하기
    user_x -= 1;


    if (!checkXY(user_x, mapX, user_y, mapY)) {
        cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
        user_x += 1;
    }
    else {
        cout << "왼쪽으로 이동합니다." << endl;
        displayMap(map, user_x, user_y);

        // user hp 1 감소
        user.DecreasedHP();
    }
}


//오른쪽로 움직이는 함수
void moveRight(vector<vector<int>> map, int& user_x, int& user_y, User& user) {
    // TODO: 오른쪽으로 이동하기
    user_x += 1;

    if (!checkXY(user_x, mapX, user_y, mapY)) {
        cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
        user_x -= 1;
    }
    else {
        cout << "오른쪽으로 이동합니다." << endl;
        displayMap(map, user_x, user_y);

        // user hp 1 감소
        user.DecreasedHP();
    }
}

// User 객체를 넣으면 hp가 0인지 체크하고 0이라면 false 반환, 그렇지 않다면 true 반환
bool CheckUser(User& user) {
    cout << "현재 Hp: " << user.GetHp() << " ";

    if (user.GetHp() < 1) {
        cout << "실패" << endl;
        return false;
    }

    return true;
}