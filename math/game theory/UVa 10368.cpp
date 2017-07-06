// UVa
// 10368 - Euclid's Game
// Game Theory, Math
#include <bits/stdc++.h>
using namespace std;

bool canWin(bool person, long long a, long long b) {		// person : { 0(stan), 1(ollie) }
	if(b == 0)												// if b == 0, then the opposite one wins!
		return !person;
	if(int(a/b) != 1)					// if this person has more choice, then 
		return person;					// he's sure winning the game! check decission tree for any move (ex: 7, 2)
	return canWin(!person, b, a%b);		// go for the next round
}

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	long long n, m;
	while(scanf("%lld %lld", &n, &m)) {
		if(n == 0 && m == 0)
			break;
		if(n < m)
			swap(n, m);
		if(!canWin(0, n, m))
			printf("Stan wins\n");
		else
			printf("Ollie wins\n");
	}
	return 0;
}
