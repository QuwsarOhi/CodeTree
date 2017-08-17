// 1268 - Unlucky Strings
// Matrix Exponentiation, Automaton, KMP

// NOT ADDED YET!!
#include <bits/stdc++.h>
#define MAXN 52
using namespace std;

struct matrix {
	unsigned mat[MAXN][MAXN];
	matrix() {
		memset(mat, 0, sizeof mat);
	}
};

int t, n, m;

void matprint(matrix a, int x, int y) {
	for(int i = 0; i < x; ++i) {
		for(int j = 0; j < y; ++j)
			printf("%u ", a.mat[i][j]);
		printf("\n");
	}
	printf("\n");
}


matrix matMul(matrix a, matrix b) {
	matrix tmp;
	for(int i = 0; i < MAXN; ++i)
		for(int j = 0; j < MAXN; ++j)
			for(int k = 0; k < MAXN; ++k)
				tmp.mat[i][j] += (a.mat[i][k] * b.mat[k][j]);
	return tmp;
}


matrix matPow(matrix a, int p) {
	if(p == 1)
		return a;
	if(p & 1)
		return matMul(a, matPow(a, p-1));
	matrix tmp = matPow(a, p/2);
	return matMul(tmp, tmp);
}

matrix failFunc(string P, string Alpha) {
	matrix f;
	int P_len = P.size();
	int A_len = Alpha.size();
	
	for(int len = 0; len < P_len; ++len) {
		for(int j = 0; j < A_len; ++j) {
			string patt = P.substr(0, len) + Alpha[j];
			for(int nlen = len + 1; nlen >= 0; --nlen) {
				if(nlen == 0 || patt.substr(len+1-nlen, nlen) == P.substr(0, nlen)) {
					if(nlen != P_len)
						f.mat[len][nlen]++;
					break;
				}
			}
		}
	}
	return f;
}

int main() {
	
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
	
	cin >> t;
	string P, Alpha;
	
	for(int Case = 1; Case <= t; ++Case) {
		cin >> n;
		cin >> Alpha >> P;
		m = P.size();
		matrix ff = failFunc(P, Alpha);
		ff = matPow(ff, n);
		unsigned ans = 0;
		for(int i = 0; i < m; ++i)
			ans += ff.mat[0][i];
		cout << "Case "  << Case << ": " << ans << endl;
	}
	return 0;
}
