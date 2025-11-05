#include <bits/stdc++.h>
using namespace std;

// Structure to store player data
struct Player {
    string name;
    int score;
};

// Function to display the quiz and calculate score
int startQuiz() {
    int score = 0;
    char ans;

    cout << "\n===== COMPUTER APTITUDE QUIZ =====\n";

    cout << "\nQ1. Which data structure uses LIFO order?\n";
    cout << "a) Queue\nb) Stack\nc) Linked List\nd) Tree\n";
    cout << "Your answer: ";
    cin >> ans;
    if (tolower(ans) == 'b') score++;

    cout << "\nQ2. Which of these is not a programming language?\n";
    cout << "a) Python\nb) HTML\nc) Java\nd) C++\n";
    cout << "Your answer: ";
    cin >> ans;
    if (tolower(ans) == 'b') score++;

    cout << "\nQ3. What is the time complexity of binary search?\n";
    cout << "a) O(n)\nb) O(log n)\nc) O(n^2)\nd) O(1)\n";
    cout << "Your answer: ";
    cin >> ans;
    if (tolower(ans) == 'b') score++;

    cout << "\nQ4. Which symbol is used to write comments in C++?\n";
    cout << "a) //\nb) <>\nc) **\nd) #\n";
    cout << "Your answer: ";
    cin >> ans;
    if (tolower(ans) == 'a') score++;

    cout << "\nQ5. Which of the following is used for dynamic memory allocation?\n";
    cout << "a) malloc()\nb) new\nc) alloc()\nd) memory()\n";
    cout << "Your answer: ";
    cin >> ans;
    if (tolower(ans) == 'b') score++;

    cout << "\nQuiz completed! ✅\n";
    cout << "You scored " << score << " out of 5.\n";
    return score;
}

// Function to show performance feedback
void showPerformance(int score) {
    cout << "\n===== PERFORMANCE ANALYSIS =====\n";
    if (score == 5)
        cout << "Excellent! You have great command over concepts.\n";
    else if (score >= 3)
        cout << "Good! You have decent understanding, keep practicing.\n";
    else
        cout << "Needs improvement. Revise basic computer aptitude topics.\n";
}

// Function to save score to leaderboard file
void saveScore(string name, int score) {
    ofstream fout("leaderboard.txt", ios::app);
    fout << name << " " << score << endl;
    fout.close();
}

// Function to display top 5 leaderboard
void showLeaderboard() {
    vector<Player> players;
    ifstream fin("leaderboard.txt");
    Player p;

    while (fin >> p.name >> p.score) {
        players.push_back(p);
    }
    fin.close();

    sort(players.begin(), players.end(), [](Player &a, Player &b) {
        return a.score > b.score;
    });

    cout << "\n===== LEADERBOARD (Top 5) =====\n";
    for (int i = 0; i < min(5, (int)players.size()); i++) {
        cout << i + 1 << ". " << players[i].name << " - " << players[i].score << "/5\n";
    }
}

int main() {
    cout << "===== APTITUDE MASTER SYSTEM =====\n";
    string name;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);

    int score = startQuiz();
    showPerformance(score);
    saveScore(name, score);
    showLeaderboard();

    cout << "\nThank you for playing Aptitude Master! 🌟\n";
    return 0;
}

