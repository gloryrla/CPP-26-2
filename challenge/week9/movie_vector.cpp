#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Movie{
private:
    string name;
    double score;
public:
    Movie(string n , double s) {
        name = n;
        score = s;
    }

    string GetNmae() {
        return name;
    }

    double GetScore() {
        return score;
    }

    //변수 출력 함수
    void PrintMovie() {
        cout << name << ": " <<  score << endl;
    }
 
};

int main() {


    vector<Movie> movies;

    //영화 객체 추가
    movies.push_back(Movie("titinic", 9.9));
    movies.push_back(Movie("gone with the wind", 9.6));
    movies.push_back(Movie("terminator", 9.7));

    //iter로 영화 출력 
    for (auto& p : movies) {
        p.PrintMovie();
    }

    for (auto p : movies) {
        p.PrintMovie();
    }




}
