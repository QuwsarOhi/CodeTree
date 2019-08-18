#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#define pii pair<int, int>
using namespace std;
typedef long long ll;

const int N = 100005;
int n, x, opt[N], cur;
bool u[N];
queue<int> Q;
stack<int> S;
deque<int> D;
priority_queue< pii > H;
int main() {
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) {
		scanf("%d", &x); opt[i] = x;
		if (x) {
			H.push(make_pair(x, i));
		}
		else {
			if (!H.empty()) {u[H.top().second] = true; H.pop();}
			if (!H.empty()) {u[H.top().second] = true; H.pop();}
			if (!H.empty()) {u[H.top().second] = true; H.pop();}
			while (!H.empty()) H.pop();
		}
	}
	cur = 0;
	for (int i=1; i<=n; ++i) {
		x = opt[i];
		if (x) {
			if (u[i]) {
				if (cur == 0) {Q.push(x); puts("pushQueue");} else
				if (cur == 1) {S.push(x); puts("pushStack");} else
				if (cur == 2) {D.push_front(x); puts("pushFront");}
				cur = (cur + 1) % 3;
			} else {
				D.push_back(x);
				puts("pushBack");
			}
		}
		else {
			int k = 0;
			if (!Q.empty()) ++k;
			if (!S.empty()) ++k;
			if (!D.empty()) ++k;
			printf("%d", k);
			if (!Q.empty()) {Q.pop(); printf(" popQueue");}
			if (!S.empty()) {S.pop(); printf(" popStack");}
			if (!D.empty()) {D.pop_front(); printf(" popFront");}
			puts("");
			while (!Q.empty()) Q.pop();
			while (!S.empty()) S.pop();
			D.clear();
			cur = 0;
		}
	}
	return 0;
}