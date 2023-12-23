// https://www.topcoder.com/thrive/articles/Binary%20Indexed%20Trees
// https://www.youtube.com/watch?v=d5PBN2hf2Xo

#include <iostream>
#include <vector>

#define MAXN 100001

using namespace std;

class FenwickTree {

    private:
        int BIT[MAXN];
        int N;
        
    public:
        FenwickTree(int N) {
            this->N = N;
            for(int i = 1; i <= N; i++) BIT[i] = 0;
        }

        int read(int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += BIT[idx];
                idx -= (idx & -idx);
            }
            return sum;
        }

        void update(int idx, int val) {
            while (idx <= N) {
                BIT[idx] += val;
                idx += (idx & -idx);
            }
        }

};

int main() {

	ios::sync_with_stdio(0);
    cin.tie(0);
	
	int N, X, i;
	while(1) {
		cin >> N;
		if (N == 0) break;

        FenwickTree fenwickTree(N);
        int winner = 0;
		for (i = 0; i < N; i++) {
			cin >> X;
			fenwickTree.update(X, 1);
            winner += fenwickTree.read(N) - fenwickTree.read(X); 
		}

		cout << ((winner % 2 == 0)?"Carlos\n":"Marcelo\n");
	}

	return 0;
}