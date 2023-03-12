#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

int main() {
    string line;
    getline(cin, line);  // читаем строку с выражением

    stringstream ss(line);  // создаем поток из строки для удобства чтения
    stack<int> st;

    // проходим по выражению и обрабатываем каждый элемент
    while (ss >> line) {
        if (line == "+") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            st.push(a + b);
        }
        else if (line == "-") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            st.push(a - b);
        }
        else if (line == "*") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            st.push(a * b);
        }
        else {
            int num = stoi(line);
            st.push(num);
        }
    }

    cout << st.top() << endl;  // выводим результат

    return 0;
}