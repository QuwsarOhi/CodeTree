// LightOJ
// 1214 - Large Division

// Divide like we do division in pen and paper


#include <bits/stdc++.h>
using namespace std;


int main() {
	
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t, l;
	long long d, carry;
	char s[210];
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%s %lld", s, &d);
		l = strlen(s);
		if(d < 0)
			d *= -1;
		carry = 0;
		for(int i = 0; i < l; ++i) {
			if(i == 0 && s[i] == '-')
				continue;
			carry = (carry * 10) + (s[i] - '0');
			if(carry >= d)
				carry %= d;
		}
		
		if(carry >= d)
			carry %= d;
			
		if(carry == 0)
			printf("Case %d: divisible\n", Case);
		else
			printf("Case %d: not divisible\n", Case);
	}
	return 0;
}
