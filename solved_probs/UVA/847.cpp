// UVa
// 847 - A Multiplication Game
// Dynamic Programming, Pattern Finding, Game Theory

#include <bits/stdc++.h>
using namespace std;

map<int, bool>dp;
long long lim;

// Everyone searches for optimal position, from which position the opponent has no option of winning

bool canWin(long long n, bool person) {					// Returns who wins, 0 (stan), 1 (Ollie)
	for(long long i = 2; i <= 9; ++i) {
		long long tmp = n*i;
		if(dp.find(tmp) != dp.end() && dp[tmp] == person)
			return person;
		if(tmp >= lim) {
			dp[tmp] = person;
			return person;								// Winning position
		}
		if(canWin(tmp, !person) == person) {			// Let the second person play, if he looses
			dp[tmp] = person;
			return person;								// Then this person wins
		}
	}												
	
	// This line only runs when the second person always wins
	return !person;										// So, this person doesn't win
}

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);

	while(scanf("%lld", &lim) == 1) {
		if(canWin(1, 0) == 0)
			printf("Stan wins.\n");
		else
			printf("Ollie wins.\n");
		dp.clear();
	}
	return 0;
}
