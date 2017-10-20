// UVa
// 12108 - Extraordinarily Tired Students
#include <bits/stdc++.h>
using namespace std;

struct student{
	int a, b, p;
	bool sleep, awake;
	
	student(int A, int B, int State) {
		this->a = A;
		this->b = B;
		
		if(A >= State) {
			awake = 1, sleep = 0;
			p = A-State+2;
		}
		else {
			sleep = 1, awake = 0;
			p = A+B-State+2;
		}
	}
};

int main() {
	int n, Case = 1;
	vector<student>v;
	while(scanf("%d", &n) && n != 0) {
		int a, b, c, cnt = 0, cntP = 0, lim = 1;
		v.clear();
		for(int i = 0; i < n; ++i) {
			scanf("%d %d %d", &a, &b, &c);
			v.push_back(student(a, b, c));
			if(v[i].awake)
				cntP++;
			lim *= (a+b);
		}
		
		printf("Case %d: ", Case++);
		for(int t = 1; t <= lim+1; ++t) {
			cnt = cntP;
			for(int i = 0; i < n; ++i) {
				if(v[i].p == t) {
					if(v[i].awake) {
						if(n-cntP > cntP) { //
							v[i].awake = 0, v[i].sleep = 1;
							v[i].p += v[i].b;
							--cnt;
						}
						else {
							v[i].p += v[i].a;
						}
					}
					else {
						v[i].awake = 1, v[i].sleep = 0;
						v[i].p = t+v[i].a;
						++cnt;
					}
				}
			}
			cntP = cnt;
			
			if(cnt == n) {
				printf("%d\n", t);
				break;
			}
		}
		
		if(cnt != n) 
			printf("-1\n");
	}
	return 0;
}
