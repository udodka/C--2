#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

int main() {
    string line;
    getline(cin, line);  // ������ ������ � ����������

    stringstream ss(line);  // ������� ����� �� ������ ��� �������� ������
    stack<int> st;

    // �������� �� ��������� � ������������ ������ �������
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

    cout << st.top() << endl;  // ������� ���������

    return 0;
}