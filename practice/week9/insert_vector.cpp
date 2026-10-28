#include <iostream>
#include <vector>
using namespace std;

void PrintVector(vector<int> va) {
    for (auto& e : va) {
        cout << e << " ";
    }
    cout << endl;
}

int main(void) {
    vector<int> v;
    for(int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    cout << "현재의 v = ";
    PrintVector(v);
    

    auto it = v.begin() + 5;
    v.insert(it, 100);

    cout << "5번의 인덱스에 값을 추가한 후 v = ";
    PrintVector(v);

    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    cout << "현재의  v = ";
    PrintVector(v);

    v.erase(v.begin()+5);

    cout << "5번의 인데스를 제거한 후 v = ";
    PrintVector(v);
}