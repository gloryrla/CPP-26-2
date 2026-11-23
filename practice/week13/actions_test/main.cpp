#include "user.h"

// g++ -std=c++17 main.cpp user.cpp -o main

int main() {
    const User player{"Knight", 100};
    printStatus(player);
    return 0;
}
