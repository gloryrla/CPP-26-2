#include <iostream>
using namespace std;

class User{
private:
    int hp = 20;
    int itemCnt = 0; //아이템 먹은 횟수를 저장하는 변수

public:
    void DecreasedHP();
    void IncreasedHP();
    void IncreasedItemCnt();
    int GetHp() const;
    int GetItemCnt() const;
    bool CheckUser() const;
    void printItemCnt() const;
    virtual void doAttack();

};

ostream& operator<<(ostream& os, const User& user);

class Magician : public User {
public:
    void doAttack() ;
};

class Warrior : public User {
public:
    void doAttack();
};