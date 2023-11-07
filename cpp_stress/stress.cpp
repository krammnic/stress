//
// Created by krammnic on 07.11.23.
//
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef pair<long long, long long> pii;
std::mt19937 ran(time(0));

int irand(int a, int b) {
    return a + ran() % (b - a + 1);
}

struct Test {
    int n, w;
    vector<int> coins;
};

struct Answer {
    bool correct = true;
    int wrongAnswer, rightAnswer;
};

Test gen() {
    Test ready;
    ready.n = irand(1, 5);
    ready.w = irand(5, 20);
    ready.coins.resize(ready.n);
    for (int i = 0; i < ready.n; ++i) {
        ready.coins[i] = irand(1, 6);
    }
    return ready;
}

int wrong_answer(Test &a) {
    sort(a.coins.begin(), a.coins.end());
    int ans = 0;
    for (int i = a.coins.size() - 1; i >= 0; --i) {
        while (a.w >= a.coins[i]) {
            ans++;
            a.w -= a.coins[i];
        }
    }
    if (a.w > 0) {
        return -1;
    }
    return ans;
}

int correct_answer(Test &a) {
    int INF = 1e9;
    vector<int> dp(a.w + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= a.w; ++i) {
        for (auto j : a.coins) {
            if (i - j >= 0 && dp[i - j] + 1 < dp[i]) {
                dp[i] = dp[i - j] + 1;
            }
        }
    }
    if (dp[a.w] == INF) {
        return -1;
    }
    return dp[a.w];
}

ostream& operator<<(ostream& out, Test& t) {
    out << t.n << " " << t.w << '\n';
    for (int i : t.coins) {
        out << i << " ";
    }
    out << "\n";
    return out;
}

Answer check(Test& a) {
    int correctAnswer = correct_answer(a);
    int wrongAnswer = wrong_answer(a);
    return {correctAnswer == wrongAnswer, wrongAnswer, correctAnswer};
}



int main() {
    int countTest;
    cin >> countTest;
    while (countTest--) {
        Test a = gen();
        auto test = check(a);
        if (!test.correct) {
            cout << "Wrong answer! \nTest: " << a << "\n";
            cout << "Participant: " << test.wrongAnswer << "\nJury: " << test.rightAnswer << "\n\n";
        } else {
            cout << "Accepted! \nTest: " << a << "\n\n";
        }
    }
}
