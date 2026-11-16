#include <iostream>
#include "user.h"
using namespace std;

void User::DecreasedHP() {
    hp -= 1;
}

void User::IncreasedHP() {
    hp += 1;
}

// 아이템 cnt 1 증가 하는 메서드
void User::IncreasedItemCnt() {
    itemCnt += 1;
}

int User::GetHp() const{
    return hp;
}

int User::GetItemCnt() const{
    return itemCnt;
}

bool User::CheckUser() const{
    if (hp < 1) {
        return false;
    }

    return true;
}

// 출력 연산자 중복 정의 
ostream& operator<<(std::ostream& os, const User& user) {
    os << "현재 HP는 " << user.GetHp() << "이고, 먹은 아이템은 총 " << user.GetItemCnt() << "개";
    return os;
}