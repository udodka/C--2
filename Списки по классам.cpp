#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, vector<string>> students;

    // считываем данные и заполняем map
    for (int i = 0; i < n; i++) {
        int grade;
        string name;
        cin >> grade >> name;
        students[grade].push_back(name);
    }

    // выводим список школьников по классам
    for (int grade = 9; grade <= 11; grade++) {
        vector<string> names = students[grade];
        for (string name : names) {
            cout << grade << " " << name << endl;
        }
    }

    return 0;
}