#include <iostream>
#include <string>

#define MAXN 101

using namespace std;

int k, n, instance = 0;
string P[MAXN];

int menor(string arr[], int l, int r) {
	int min = l;
	for (int h = l; h < r; h++) {
		if (arr[h] < arr[min]) {
			min = h;
		}
	}
	return min;
}

void solve(string arr[], int n) {
	for (int i = 0; i < n; i++) {
		int len = (i+k < n)?i+k+1:n;
		for (int j = menor(arr, i, len); j > i; j--) {
			string temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			k--;
			if (k == 0) return;
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
    cin.tie(0);

	string name;
	while(1) {
		cin >> n >> k;
		if (n == 0 && k == 0) break;

		for (int i = 0; i < n; i++) {
			cin >> name;
			P[i] = name;
		}
		solve(P, n);
		
		cout << "Instancia " << ++instance << "\n";
		for (int i = 0; i < n; i++) {
			cout << P[i] << " ";
		}
		cout << "\n\n";
	}

	return 0;
}
