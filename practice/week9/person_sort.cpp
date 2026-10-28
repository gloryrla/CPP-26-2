#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;
public:
    Person(string n , int a) {
        name = n;
        age = a;
    }

    string GetName() {
        return name;
    }

    int GetAge() {
        return age;
    }

    void Print() {
        cout << name << " " << age << endl;
    }
};

bool Compare(Person &p, Person &q) {
    return p.GetAge() < q.GetAge();  // 이거 자체가 true면 스왑하지 않는다
}

int main() {

    vector<Person> list;

    list.push_back(Person("Kim", 30));
    list.push_back(Person("Park", 22));
    list.push_back(Person("Lee", 26));

    sort(list.begin(), list.end(), Compare);  //어디서부터 어디까지 어떤 연산을 통해서 정렬을 할 것인가

    for (auto& e : list) {
        e.Print();
    }

    return 0;
}