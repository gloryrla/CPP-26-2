#include "user.h"

User::User(){
    hp = 20;
}

void User::DecreasedHP() {
        hp -= 1;
}

void User::increasedHP() {
        hp += 1;
}


int User::GetHp(){
        return hp;
}

