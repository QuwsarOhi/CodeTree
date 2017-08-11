#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int n, r, intersects, b[30], t, c = 1;
    vector<int>ans;
    map<pair<int, int>, long>mp;
    long max_sum, a[30], val;
    while(scanf("%d %d", &n, &r) && (n || r)) {
        for(int i = 0; i < n; i++)
            scanf("%ld", &a[i]);             //zero base index
        scanf("%d", &intersects);
        for(int i = 0; i < intersects; i++) {
            scanf("%d", &t);
            for(int j = 0; j < t; j++)
                scanf("%d", &b[j]);         //one base index
            scanf("%ld", &val);
            //sort(b, b+t);
            for(int j = 0; j < t; j++)
                for(int k = j+1; k < t; k++)
                    mp[make_pair(b[j]-1, b[k]-1)] += val;
        }
        vector<bool>v(n);
        fill(v.begin(), v.begin()+r, true);
        max_sum = 0;
        do {
            //for(int i = 0; i < n; i++)
                //cout << v[i] << " ";
            //printf("\n");
            vector<int>vt;
            long sum = 0;
            for(int i = 0; i < n; i++)
                if(v[i]) {
                    vt.push_back(i);
                    sum+=a[i];
                }
            //printf("total sum %ld\n", sum);
            for(int i = 0; i < r; i++)
            for(int j = i+1; j < r; j++) {
                    if(mp[make_pair(vt[i], vt[j])])
                        printf("%d %d conflicts Subtracting %d\n", vt[i]+1, vt[j]+1, mp[make_pair(vt[i], vt[j])]);
                    sum -= mp[make_pair(vt[i], vt[j])];
            }
            for(int i = 0; i < r; i++)
                printf("%d ", vt[i]+1);
            printf("\n");
            printf("sum %ld\n", sum);
            if(sum > max_sum) {
                ans = vt;
                max_sum = sum;
            }
        }while(prev_permutation(v.begin(), v.end()));
        printf("Case Number  %d\n", c++);
        printf("Number of Customers: %ld\n", max_sum);
        printf("Locations recommended:");
        for(int i = 0; i < r; i++)
            printf(" %d", ans[i]+1);
        printf("\n\n");
        mp.clear();
    }
    return 0;
}
