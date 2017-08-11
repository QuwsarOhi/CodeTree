// LightOJ
// 1179 - Josephus Problem


// lets number the persons as 0, 1, 2, 3, 4, ... n-1
// when there is 1 person, we can say that 0'th person would survive for any value of k
// for 2 people, the survived person would be ((person who survived when there was 2-1 person) + k) % 2     note : here 2 == n
// so on...

// + k is because, we were removing the k'th person from the list
// % n is because, the + k will leave the range, as the range is circular, modulo is required

#include <bits/stdc++.h>
using namespace std;


int recurse(int n, int k) {
	if(n == 1)
		return 0;
		
	return (recurse(n-1, k)+k) % n;
}


int main() {
	int t, n, k;
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d %d", &n, &k);
		printf("Case %d: %d\n", Case, recurse(n, k)+1);
	}
	return 0;
}
