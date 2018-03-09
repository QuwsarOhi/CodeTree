#include <stdio.h>
#include <queue>
using namespace std;


int main() {
    int n;
    priority_queue<unsigned int>pq;
    unsigned int v;
    
    scanf("%d", &n);
    
    int i;
    for(i = 0; i < n/2+1; ++i) {
        scanf("%u", &v);
        pq.push(v);
    }
    
    for( ; i < n; ++i) {
        scanf("%u", &v);
        pq.push(v);
        pq.pop();
    }
    
    double median = pq.top();
    if(!(n&1)) {
        pq.pop();
        median += pq.top();
        median /= 2;
    }
    
    printf("%.1lf\n", median);
    return 0;
}
