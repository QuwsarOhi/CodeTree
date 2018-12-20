#include <bits/stdc++.h>
#define isON(xx, jj)    (xx & (1 << jj))
#define ON(xx, jj)      (xx | (1 << jj))
#define INF             0x3f3f3f3f
using namespace std;


int recur(int pos, int mask0, int mask1) {
    if(mask0 == (1 << S)-1 and mask1 == (1 << S)-1)
        return 0;
    if(pos == N)
        return INF;

    int ret = recur(pos+1, mask0, mask1);

    for(auto it : sub[pos]) {
        // check
    }
}

int main() {
    int S, N, M, x;

    while(1) {
        cin >> S >> M >> N;

        if(S == 0) break;

        for(int i = 0; i < M; ++i) {
            cin.ignore();
            getline(cin, s);
            ss.clear();
            ss << s;

            ss >> x;
            totCost += x;

            while(ss >> x) {
                x--;
                if(not isON(mask0, x))
                    ON(mask0, x);
                else
                    ON(mask1, x);
            }
        }

        for(int i = 0; i < N; ++i) {
            getline(cin, s);
            ss.clear();
            ss << s;
            ss >> cst[i];

            sub[i].clear();
            while(ss >> x)
                sub[i].push_back(x-1);
        }


    }
}

/*
#include<bits/stdc++.h>
using namespace std;

#define MAX 1000000

bool isPrime[MAX];
int totalPrime, primes[MAX];

void sieve(int N) {
    for(int i = 0; i < MAX; ++i)
        isPrime[i] = 1;

    isPrime[0] = isPrime[1] = 0;
    totalPrime = 0;

    for(int i = 2; i <= N; i++) {      // change lim to N, if all primes in range N is needed
        if(isPrime[i] == 1) {
            primes[totalPrime++] = i;

            for(int j = i*i; j <= N; j+= i)
                isPrime[j] = 0;
        }
    }
}

int main() {
    int num;
    scanf("%d",&num);

    sieve(num);

    for(int i = 0; i < totalPrime; ++i)
        printf("%d ", primes[i]);

    return 0;
}*/