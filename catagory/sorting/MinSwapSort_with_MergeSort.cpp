// UVa
// 10810 - Ultra-QuickSort

// Maximum Number of sorts can be (N*(N-1))/2

#include <bits/stdc++.h>
using namespace std;

long long cnt, v[500100];

void MergeSort(long long arr[], int l, int mid, int r) {
    int lftArrSize = mid-l+1;
    int rhtArrSize = r-mid;
    int lftArr[lftArrSize+2], rhtArr[rhtArrSize+2];

    for(int i = l, j = 0; i <= mid; ++i, ++j)
        lftArr[j] = arr[i];
    
    for(int i = mid+1, j = 0; i <= r; ++i, ++j)
        rhtArr[j] = arr[i];
    
    lftArr[lftArrSize] = rhtArr[rhtArrSize] = 1e9;      // INF value in both array (Basic merge sort algo)
    
    int lPos = 0, rPos = 0;
    
    for(int i = l; i <= r; ++i) {
        if(lftArr[lPos] <= rhtArr[rPos])
            arr[i] = lftArr[lPos++];
        else {
            arr[i] = rhtArr[rPos++];
            cnt += lftArrSize - lPos;                   // Modified Line
        }
    }
}

void Divide(long long arr[], int l, int r) {
    if(l == r || l > r)
        return;
    
    int mid = (l+r)>>1;
    
    Divide(arr, l, mid);
    Divide(arr, mid+1, r);
    
    MergeSort(arr, l, mid, r);
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
     
    int n;
    while(scanf("%d", &n) && n != 0) {
        for(int i = 0; i < n; ++i)
            scanf("%lld", &v[i]);
        
        cnt = 0;
        Divide(v, 0, n-1);
        printf("%lld\n", cnt);
    }
    return 0;
}
