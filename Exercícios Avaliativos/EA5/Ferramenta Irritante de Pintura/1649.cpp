#include <iostream>
#include <cstring>

#define NMAX 100
#define MMAX 100

using namespace std;

int n, m, r, c, operations;
int area[NMAX][MMAX], blank[NMAX][MMAX];

void initializeMemoization() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            blank[i][j] = 0;
        }
    }
}

void paint(int x, int y) {
    operations++;
    for (int i = x; i < x+r; i++) {
        for (int j = y; j < y+c; j++) {
            blank[i][j] = (blank[i][j] == 0)? 1 : 0;
        }
    }
}

int solve() {
    operations = 0;
    initializeMemoization(); // Reset pixels
    char ch;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ch;
            area[i][j] = ch - '0';
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (area[i][j] != blank[i][j]) {
                if ((i+r-1 >= n) || (j+c-1 >= m)) return -1;
                paint(i, j);
            }
        }
    }

    return operations;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        cin >> n >> m >> r >> c;
        if (n == 0 && m == 0 && r == 0 && c == 0) break;
        cout << solve() << '\n';
    }

    return 0;
}
