struct matrix {
    matrix() { memset(mat, 0, sizeof(mat)); }
    long long mat[MAXN][MAXN];
};
matrix mul(matrix a, matrix b, int p, int q, int r) {		// O(n^3) :: r1, c1, c2  [c1 = r2]
    matrix ans;
    for(int i = 0; i < p; ++i)
        for(int j = 0; j < r; ++j) {
            ans.mat[i][j] = 0;
            for(int k = 0; k < q; ++k)
                ans.mat[i][j] = (ans.mat[i][j]%MOD + (a.mat[i][k]%MOD * b.mat[k][j]%MOD)%MOD)%MOD;
        }
    return ans;
}
matrix matPow(matrix base, ll p, int s) {               // O(logN), s : size of square matrix
    if(p == 1) return base;
    if(p & 1)  return mul(base, matPow(base, p-1, s), s, s, s);
    matrix tmp = matPow(base, p/2, s);
    return mul(tmp, tmp, s, s, s);
}
