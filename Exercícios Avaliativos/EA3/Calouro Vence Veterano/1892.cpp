#include <iostream>

using namespace std;

long long int merge(string l[], int n, string r[], int m, string a[]) {
    int i = 0, j = 0, k = 0;
	long long int inversions = 0;
    while (i < n && j < m) {
        if (l[i] < r[j]) {
            a[k++] = l[i++];
        } else {
			inversions += n - i;
            a[k++] = r[j++];
        }
    }
    while (i < n) {
        a[k++] = l[i++];
    }
    while (j < m) {
        a[k++] = r[j++];
    }
	return inversions;
}

long long int merge_sort(string a[], int n) {
	long long int inversions = 0;
	if (n > 1) {
		int mid = n / 2;
		string l[mid], r[n-mid];
		for(int i = 0; i < mid; i++) {
			l[i] = a[i];
		}
		for(int i = 0; i < n - mid; i++) {
			r[i] = a[i+mid];
		}
		inversions += merge_sort(l, mid);
		inversions += merge_sort(r, n - mid);
		inversions += merge(l, mid, r, n - mid, a);
	}
	return inversions;
}

int main() {

	ios::sync_with_stdio(0);
    cin.tie(0);

	int N;
	while (cin >> N) {
		string matriculas[N];
		for (int i = 0; i < N; i++) {
			cin >> matriculas[i];
		}
		cout << merge_sort(matriculas, N) << "\n";
	}

	
    return 0;
}