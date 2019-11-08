// SPOJ
// BEADS - Glass Beads
// Suffix Array

#include <bits/stdc++.h>
#define MAX 200100
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int o[2][MAX], t[2][MAX];
int idxToRank[MAX], rankToIdx[MAX], A[MAX], B[MAX], C[MAX], D[MAX];
void SuffixArray(char str[], int len, int maxAscii = 256) {     // use ~ as a distinguishing charachter
    int x = 0;
    memset(A, 0, sizeof A);
    memset(C, 0, sizeof C);
    memset(D, 0, sizeof D);
    memset(o, 0, sizeof o);
    memset(t, 0, sizeof t);

    for(int i = 0; i < len; ++i) A[(str[i]-'a')] = 1;
    for(int i = 1; i < maxAscii; ++i) A[i] += A[i-1];
    for(int i = 0; i < len; ++i) o[0][i] = A[(int)(str[i]-'a')];
 
    for (int j = 0, jj = 1, k = 0; jj < len && k < len; ++j, jj <<= 1) {
        memset(A, 0, sizeof A);
        memset(B, 0, sizeof B);
        for(int i = 0; i < len; ++i) {
            ++A[ t[0][i] = o[x][i] ];
            ++B[ t[1][i] = (i+jj<len) ? o[x][i+jj] : 0 ];
        }
        for(int i = 1; i <= len; ++i) {
            A[i] += A[i-1];
            B[i] += B[i-1];
        }
        for(int i = len-1; i >= 0; --i)
            C[--B[t[1][i]]] = i;
        for(int i = len-1; i >= 0; --i)
            D[--A[t[0][C[i]]]] = C[i];
        x^=1;
        o[x][D[0]] = k = 1;
        for(int i = 1; i < len; ++i)
            o[x][D[i]]= (k += (t[0][D[i]] != t[0][D[i-1]] || t[1][D[i]] != t[1][D[i-1]]));
    }
    for(int i = 0; i < len; i++) {
        idxToRank[i] = o[x][i]-1;
        rankToIdx[o[x][i]-1] = i;
	}
}

char s[MAX];

int main() {
	int t;
	scanf("%d", &t);

	while(t--) {
		scanf("%s", s);
		int len = strlen(s);

		for(int i = len, j = 0; j < len; ++i, ++j)
			s[i] = s[j];
		
		int dlen = 2*len;
		s[dlen++] = '~';
		SuffixArray(s, dlen);

		//for(int i = 0; i < dlen; ++i)
		//	printf("%3d %3d %3d   %s\n", i, dlen-rankToIdx[i], rankToIdx[i], s+rankToIdx[i]);

		int minRank = dlen;
		for(int idx = 0; idx < len; ++idx) {
			int rank = idxToRank[idx];
			minRank = min(minRank, rank);
		}

		printf("%d\n", rankToIdx[minRank]+1);
	}
	return 0;
}