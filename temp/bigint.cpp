#include <bits/stdc++.h>
const int k = 16;
const int N = 1e5;
const int ZERO = 0; // ZERO + x = x + ZERO = x (for any x)

long long table[N][k + 1]; // k + 1 because we need to access table[r][k]
int Arr[N];

int main()
{
    int n, L, R, q;
    for(int i = 0; i < 15; ++i)
		Arr[i] = i+1;
    n = 15;
    //cin >> n; // array size
    //for(int i = 0; i < n; i++)
        //cin >> Arr[i];

    // build Sparse Table
    for(int i = 0; i < n; i++)
        table[i][0] = Arr[i];
    for(int j = 1; j <= k; j++) {
        for(int i = 0; i <= n - (1 << j); i++)
            table[i][j] = table[i][j - 1] + table[i + (1 << (j - 1))][j - 1];
    }
    
    for(int i = 0; i < 20; ++i) {
		for(int j = 0; j < 10; ++j)
			printf("%3d", Arr[i]);
		printf("\n");
	}

    /*cin >> q; // number of queries
    for(int i = 0; i < q; i++) {
        cin >> L >> R; // boundaries of next query, 0-indexed
        long long answer = ZERO;
        for(int j = k; j >= 0; j--) {
            if(L + (1 << j) - 1 <= R) {
                answer = answer + table[L][j];
                L += 1 << j; // instead of having L', we increment L directly
            }
        }
        cout << answer << endl;
    }*/
    return 0;
}
