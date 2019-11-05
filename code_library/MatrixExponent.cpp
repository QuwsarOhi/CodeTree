/*
1. Basic Recurrence:
--------------------
f(n) = x*f(n-1) + y*f(n-2) + z*c
-------------------------------------
| x  y  z |   | f(n-1) |   |  f(n)  |
| 1  0  0 | x | f(n-2) | = | f(n-1) |
| 0  0  1 |   |    c   |   |    c   |
-------------------------------------
    T       x      f     =    ans
-------------------------------------


2. Even/Odd Seperate Function:
------------------------------
f(n) = if n is even: f(n) = x*f(n-1) -y*f(n-2) + c
               else: f(n) = z*f(n-2)
f(1) = f(2) = 1

Build  :
--------
        |x  y  z|            |0  z  0|          |1|
T_even :|1  0  0|     T_odd :|1  0  0|    f(2) :|1|
        |0  0  1|            |0  0  1|          |c|


T : T_even * T_odd

if n is odd then, f(n) :
    n = n-2
    ans = (T^(n/2)) * f(2)
else if n is odd, f(n):
    n = n-2
    ans = T_odd * (T^(n-1)/2) * f(2)

Why this works:
matrix T contains same number of even and odd function calculations
so from start point (here start point is 2 of f(2)), if there exists same number of
even and odd function calculation then calculating power of T is enough.
else we need to multiply the extra T_even or T_odd with T according to the problem

REF: http://fusharblog.com/solving-linear-recurrence-for-programming-contest/

3. Cumulative Sum:
------------------
To calculate cumulative sum, just add another extra row in base matrix T
and carry the previous sum with new function value as well

Example -> Cumulative sum of:
           f(n) = x*f(n-1) + y*f(n-2) + c
           where, f(1) = f(2) = 1;
           
Let, S(n) = is the sum of first n values

|1 x y 1|   |S(n-1)|   | S(n) |
|0 x y 1|   |f(n-1)|   | f(n) |
|0 1 0 0| X |f(n-2)| = |f(n-1)|
|0 0 0 1|   |  c   |   |   c  |
-------------------------------
    T     X  f(n-1)  =   f(n)

*/

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
MAT pow(MAT x, ll p, int sz) {                      // Power using loop
    if(p == 1) return x;
    MAT ret;
    for(int i = 0; i < sz; ++i) ret.m[i][i] = 1;    // Diagonal Matrix
    while(p > 0) {
        if(p&1) ret = mul(ret, x, sz, sz, sz);
        p = p >> 1, x = mul(x, x, sz, sz, sz);
    }
    return ret;
}
