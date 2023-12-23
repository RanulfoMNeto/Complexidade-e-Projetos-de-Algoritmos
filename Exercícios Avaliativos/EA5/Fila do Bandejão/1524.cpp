#include <iostream>
#include <climits>
#include <algorithm>

#define NMAX 1001
#define INF INT_MAX

using namespace std;

int N, K, queue[NMAX], dist[NMAX];

// Custom comparison function for sorting in descending order
bool compare(int a, int b) {
    return a > b;
}

int main() {
    while (cin >> N >> K) {
        queue[0] = 0;
        dist[0] = 0;
        for (int i = 1; i < N; i++) {
            cin >> queue[i];
            dist[i] = queue[i] - queue[i-1];
        }

        // Sort dist array in descending order
        sort(dist, dist + N, compare);

        int sum = 0;
        for (int i = K-1; i < N; i++) {
            sum += dist[i];
        }
        cout << sum << endl;
    }

    return 0;
}