#include <iostream>
#include <cstring>  // Include this header for memset

#define XMAX 25001
#define EMPTY -1

using namespace std;

typedef long long int ll;

ll memoization[XMAX];

void initializeMemoization() {
    memset(memoization, EMPTY, sizeof(memoization));
}

ll fibonnaci(int x) {
    if (memoization[x] == EMPTY) {
        memoization[0] = 1;
        memoization[1] = 1;

        for (int i = 2; i <= x; i++) {
            memoization[i] = memoization[i - 1] + memoization[i - 2];
        }
    }
    return memoization[x];
}

int lastGreatestFibonacci(int x) {
    int last = 0;
    for (int i = 1; fibonnaci(i) <= x; i++) last++;
    return last;
}

void shiftRight(int v[], int size) {
    for (int i = size - 1; i > 0; i--) {
        v[i] = v[i - 1];
    }
    v[0] = 0;
}

int convert(int v[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += v[i] * fibonnaci(size - i);
    }
    return sum;
}

int solve(int x) {
    int size = lastGreatestFibonacci(x);
    int v[size];
    memset(v, 0, sizeof(v));
    v[0] = 1;
    while (x > 0) {
        int i = lastGreatestFibonacci(x);
        v[size - i] = 1;
        x %= fibonnaci(i);
    }
    shiftRight(v, size);
    return convert(v, size);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    initializeMemoization();

    int t, x;
    cin >> t;

    while (t--) {
        cin >> x;
        cout << solve(x) << endl;
    }

    return 0;
}
