#include <iostream>
#include "user.h"

void printStatus(const User& user) {
    cout << user.name << " HP: " << user.hp << endl;
}
