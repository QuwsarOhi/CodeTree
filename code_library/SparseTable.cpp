// Sparse Table
// 1D RMQ

int table[MAX][10], val[MAX], lg[MAX];								// table[MAX][log2(MAX)]
void buildSparseTableRMQ(int n) {							//  O(n Log n)
    for(ll i = 0; 1LL << i < n; i++)
        lg[1LL << i] = i;
    for(ll i = 1; i < n; i++)
        lg[i] = max(lg[i], lg[i - 1]);
	for(int i = 0; i < n; ++i)								// Val array contains Query values
		table[i][0] = i;
	for(int j = 1; (1 << j) <= n; ++j)						// 2^j
		for(int i = 0; i + (1 << j) - 1< n; ++i) {			// For every node
			if(val[table[i][j-1]] < val[table[i + (1 << (j-1))][j-1]])
				table[i][j] = table[i][j-1];
			else
				table[i][j] = table[i + (1 << (j-1))][j-1];
}}
int sparseQueryRMQ(int l, int r) {							// O(1) : Range can start from 0
	int k = lg[r - l + 1]; 								// log(2);
	return min(val[table[l][k]], val[table[r - (1 << k) + 1][k]]);
}