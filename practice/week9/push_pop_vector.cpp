#include <vector>
#include <iostream>
using namespace std;

int main(void) {
    
    vector<int> v1;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    cout << "v1 = ";
    for (auto& e : v1) {
        cout << e << " ";
    }

    cout << endl;


    vector<int> v;
    for (int i = 0; i < 10; i++){
        v.push_back(i);
    }

    cout << "현재의 v = ";
    for (auto& e : v) {
        cout << e << " ";
    }
    cout << endl;

    cout << "삭제 요소 = ";

    while (v.empty() != true) {
        cout << v.back() << " ";
        v.pop_back();
    }

    cout << endl;

    return 0;

}