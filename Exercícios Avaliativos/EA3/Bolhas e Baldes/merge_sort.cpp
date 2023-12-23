// Merge Sort Algorithm: https://www.programiz.com/dsa/merge-sort

#include <iostream>

#define MAXN 100001

using namespace std;

int P[MAXN], i, j, k;

long long int merge(int arr[], int p, int q, int r) {

    long long int swaps = 0;

    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (i = 0; i < n1; i++) L[i] = arr[p + i];
    for (j = 0; j < n2; j++) M[j] = arr[q + 1 + j];

    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = M[j++];
            // se o topo da direita é menor que o topo da esquerda
            swaps += n1 - i; // Incrementa o número de inversões
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = M[j++];
    }

    return swaps;
}

long long int merge_sort(int arr[], int left, int right) {
    long long int swaps = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        swaps += merge_sort(arr, left, mid);
        swaps += merge_sort(arr, mid + 1, right);
        swaps += merge(arr, left, mid, right);
    }
    return swaps;
}

int main() {

	ios::sync_with_stdio(0);
    cin.tie(0);
	
	int N, X;

	while(1) {
		cin >> N;
		if (N == 0) break;

		for (i = 0; i < N; i++) {
			cin >> X;
			P[i] = X;
		}

        long long int swaps = merge_sort(P, 0, N-1);

		cout << ((swaps % 2 == 0)?"Carlos\n":"Marcelo\n");
	}

	return 0;
}
