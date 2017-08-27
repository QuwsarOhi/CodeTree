// CodeForces
// D. Driving Test
// http://codeforces.com/contest/845/problem/D
// Data Structure, Greedy, Simulation

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, overtakeSign = 0, cnt = 0, x, speed = 0;
	stack<int>speedLim;
	scanf("%d", &n);
	
	while(n--) {
		scanf("%d", &x);
		
		if(x == 1) {
			scanf("%d", &speed);
		}
		else if(x == 2) {
			cnt += overtakeSign;
			overtakeSign = 0;
		}
		else if(x == 3) {
			scanf("%d", &x);
			speedLim.push(x);
		}
		else if(x == 4) {
			overtakeSign = 0;
		}
		else if(x == 5) {
			while(!speedLim.empty())
				speedLim.pop();
		}
		else if(x == 6) {
			overtakeSign++;
		}
		
		while(!speedLim.empty() && speedLim.top() < speed) {
			speedLim.pop();
			++cnt;
		}
	}
	
	printf("%d", cnt);
	return 0;
}
		
