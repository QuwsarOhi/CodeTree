#include <bits/stdc++.h>
using namespace std;

queue<int>q;
stack<int>s;
deque<int>d;

void out() {
	int sz = q.size() + s.size() + d.size();
	cout << min(sz, 3);
	if(sz == 0) {
		cout << endl;
		return;
	}

	if(s.size()) {
		cout << " popStack";
		s.pop();
	}

	if(q.size()) {
		cout << " popQueue";
		q.pop();
	}

	if(d.size()) {
		if(d.front() >= d.back())
			cout << " popFront", d.pop_front();
		else
			cout << " popBack", d.pop_back();
	}
	cout << endl;
}

int cnt = 0;
void in(int x) {
	int mx = max(max(s.size(), q.size()), d.size());

	if(s.empty() or s.size() < mx) {
		cout << "pushStack\n";
		s.push(x);
		return;
	}
	else if(q.empty() or q.size() < mx) {
		cout << "pushQueue\n";
		q.push(x);
		return;
	}
	else {
		if(d.size()) {
			if(d.front() < x)
				d.push_front(x), cout << "pushFront\n";
			else
				d.push_back(x), cout << "pushBack\n";
		}
		else
			d.push_front(x), cout << "pushFront\n";
		return;
	}
}

int main() {
	int n, x;
	cin >> n;

	for(int i = 0; i < n; ++i) {
		cin >> x;
		v.push_back({x, i});
	}

	
	
	return 0;
}