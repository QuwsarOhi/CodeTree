#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll seg_sum[500], sum[500], same_col[500], color[100010], indi_sum[100010];
int block;

void update(int ql, int qr, int n, int x) {
	int idx, r;
	for(int l = ql; l <= qr; ) {
		idx = l/block;
		r = min(l+block-1, qr);

		if(idx*block == l and l+block-1 <= qr) {
			if(same_col[idx]) {
				seg_sum[idx] += abs(same_col[idx] - x)*(r - l + 1);
				sum[idx] += abs(same_col[idx] - x);
			}
			else {
				for(int j = l; j <= r; ++j) {
					seg_sum[idx] += abs(color[j] - x);
					indi_sum[j] += abs(color[j] - x);
					color[j] = x;
				}
			}
			same_col[idx] = x;
			l = r+1;
		}
		else {
			if(same_col[idx]) {
				for(int j = l; j <= r; ++j)
					color[j] = same_col[idx];
				same_col[idx] = 0;
			}
			for(int j = l; j <= r; ++j) {
				seg_sum[idx] += abs(color[j] - x);
				indi_sum[j] += abs(color[j] - x);
				color[j] = x;
			}
			l = r+1;
		}
	}
}

ll query(int ql, int qr, int n) {
	ll ret = 0;
	int idx, r;
	for(int l = ql; l <= qr; ) {
		idx = l/block;
		r = min(l+block-1, qr);

		if(idx*block == l and l+block-1 <= qr) {
			ret += seg_sum[idx];
			l = r+1;
		}
		else {
			for(int j = l; j <= r; ++j)
				ret += sum[idx] + indi_sum[j];
			l = r+1;
		}
	}
	return ret;
}

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	int n, m, l, r, typ, x;
	cin >> n >> m;

	for(int i = 0; i < n; ++i)
		color[i] = i+1;
	block = sqrt(n) + 1;

	while(m--) {
		cin >> typ >> l >> r;

		if(typ == 1) {
			cin >> x;
			update(--l, --r, n, x);
		}
		else
			cout << query(--l, --r, n) << "\n";
	}
	return 0;
}