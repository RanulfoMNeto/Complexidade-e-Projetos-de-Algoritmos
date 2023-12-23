#include <iostream>

#define MAXX 39
#define UNVISITED -1
#define result first
#define num_calls second

using namespace std;

pair<int, int> memorize[MAXX+1];

// Recursive Fibonacci function with memoization
int fibobacci(int x) {
    if (x == 0 || x == 1) {
		memorize[x].num_calls = 1;
        return x;
    }
    if (memorize[x].result == UNVISITED) {
        memorize[x].result = fibobacci(x - 1) + fibobacci(x - 2);
		memorize[x].num_calls = memorize[x - 1].num_calls + memorize[x - 2].num_calls + 1;
    }
    return memorize[x].result;
}

int main() {
	int N, i, X;
	fill_n(memorize, MAXX + 1, make_pair(UNVISITED, 0));
	cin >> N;
	for(i = 0; i < N; i++) {
			cin >> X;
			fibobacci(X);
			cout << "fib(" << X << ") = " << memorize[X].num_calls - 1 << " calls = " << memorize[X].result << "\n";
	}
	return 0;
}