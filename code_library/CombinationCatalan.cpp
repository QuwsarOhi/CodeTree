// Combination
// Complexity O(k)

long long C(int n, int k) { 
    long long c = 1;
    if(k > n - k)
        k = n-k;
    for(int i = 0; i < k; i++) {
        c *= (n-i);
        c /= (i+1);
    }
    return c;
}

long long catalan(int n) {    // Cat(n) = C(2*n, n)/(n+1);
    long long c = C(2*n, n);
    return c/(n+1);
}
