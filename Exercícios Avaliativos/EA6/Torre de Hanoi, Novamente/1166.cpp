#include <iostream>
#include <cmath>

#define NMAX 50
#define EMPTY -1

using namespace std;

int T, N, i, ball;
int TOP[NMAX];

bool isPerfectSquare(int x) {
    if (x >= 0) {
        int sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--) {
        cin >> N;
        fill(TOP, TOP + N, EMPTY);  // Initialize array elements to EMPTY
        ball = 1;
        for (i = 0; i < N; i++) {
            if ((TOP[i] == EMPTY) || (isPerfectSquare(TOP[i] + ball))) {
                TOP[i] = ball++;
                i = -1;
            }
        }
        cout << ball - 1 << endl;
    }

    return 0;
}
