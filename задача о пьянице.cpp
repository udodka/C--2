#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> player1, player2;
    int card;
    // считываем карты игроков
    for (int i = 0; i < 5; i++) {
        cin >> card;
        player1.push_back(card);
    }
    for (int i = 0; i < 5; i++) {
        cin >> card;
        player2.push_back(card);
    }
    int steps = 0;
    while (!player1.empty() && !player2.empty() && steps <= 1000000) {
        steps++;
        int card1 = player1.front();
        player1.pop_front();
        int card2 = player2.front();
        player2.pop_front();
        if (card1 == 0 && card2 == 9) { // проверка на специальный случай
            player1.push_back(card1);
            player1.push_back(card2);
        }
        else if (card1 == 9 && card2 == 0) { // проверка на специальный случай
            player2.push_back(card1);
            player2.push_back(card2);
        }
        else if (card1 > card2) {
            player1.push_back(card1);
            player1.push_back(card2);
        }
        else {
            player2.push_back(card1);
            player2.push_back(card2);
        }
    }
    if (steps > 1000000) {
        cout << "botva\n";
    }
    else if (player1.empty()) {
        cout << "second " << steps << "\n";
    }
    else {
        cout << "first " << steps << "\n";
    }
    return 0;
}