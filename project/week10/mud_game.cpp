#include <iostream>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void checkState(int map[][mapX], int user_x, int user_y, int& userHp);
void printInmap(bool inMap);
void moveUp(int map[][mapX], int& user_x, int& user_y, int& userHp);
void moveDown(int map[][mapX], int& user_x, int& user_y, int& userHp);
void moveLeft(int map[][mapX], int& user_x, int& user_y, int& userHp);
void moveRight(int map[][mapX], int& user_x, int& user_y, int& userHp);
bool isValidkUserHp(int& userHp);


// 메인  함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };


	// 유저의 위치를 저장할 변수
	int user_x = 0; // 가로 번호
	int user_y = 0; // 세로 번호

    //유저 HP
    int userHp = 20;

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프

		// 사용자의 입력을 저장할 변수
		string user_input = "";


        //userHp < 1 이하면 isValidkUserHp false 반환
        if(!isValidkUserHp(userHp)) {
            return 0;
        }

		cout << "명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
		cin >> user_input;

		if (user_input == "상") {
            moveUp(map, user_x, user_y, userHp);
		}
		else if (user_input == "하") {
            moveDown(map, user_x, user_y, userHp);
		}
		else if (user_input == "좌") {
            moveLeft(map, user_x, user_y, userHp);
		}
		else if (user_input == "우") {
            moveRight(map, user_x, user_y, userHp);
		}
		else if (user_input == "지도") {
			// TODO: 지도 보여주기 함수 호출
			displayMap(map, user_x, user_y);
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
        checkState(map, user_x, user_y, userHp);

	}
	return 0;
}


// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX], int user_x, int user_y) {
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
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
		return true;
	}
	return false;
}

// 도착지에 아이템.적.포션 확인 후 출력 및 유저 체력 변경
void checkState(int map[][mapX], int user_x, int user_y, int& userHp) {
    // 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션
    switch (map[user_y][user_x]){
    case 0:
        //빈공간
        break;
    case 1: 
        cout << "아이템이 있습니다. " << endl;
        break;
    case 2:
        cout << "적이 있습니다. " << endl;
        userHp -= 2;
        cout << "HP가 2 줄어듭니다. " << endl;
        break;
    case 3:
        cout << "포션이 있습니다. " << endl;
        userHp += 2;
        cout << "HP가 2 증가합니다. " << endl;
        break;   
    }
}

//위로 움직이는 함수
void moveUp(int map[][mapX], int& user_x, int& user_y, int& userHp) {
     // 위로 한 칸 올라가기
        user_y -= 1;


        if (!checkXY(user_x, mapX, user_y, mapY)) {
            cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
        }
        else {
            cout << "위로 한 칸 올라갑니다." << endl;

            displayMap(map, user_x, user_y);

            // user hp 1 감소
            userHp -= 1;
        }
}

//아래로 움직이는 함수
void moveDown(int map[][mapX], int& user_x, int& user_y, int& userHp) {
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
        userHp -= 1;
    }
}

//왼쪽로 움직이는 함수
void moveLeft(int map[][mapX], int& user_x, int& user_y, int& userHp) {
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
        userHp -= 1;
    }
}


//오른쪽로 움직이는 함수
void moveRight(int map[][mapX], int& user_x, int& user_y, int& userHp) {
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
        userHp -= 1;
    }
}

// userHp 0이하시 실패 출력 후 종료하는 함수
bool isValidkUserHp(int& userHp) {
    cout << "현재 Hp: " << userHp << " ";
    
    // Hp 1이하면 false 반환
    if (userHp < 1) {
        cout << "실패"; 
        return false;
    }

    return true;
}