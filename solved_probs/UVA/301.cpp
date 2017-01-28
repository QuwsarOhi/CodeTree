//UVa
//301 - Transportation
#include<bits/stdc++.h>
using namespace std;

int capacity, city, orders, start_station[30], end_station[30], station_passanger[30], station_income[30], max_earning, earning, cnt;
bitset<30>used;
unsigned int temp_passanger[30];

inline bool can_be_used(int pos)
{
    for(register int i = start_station[pos]; i < end_station[pos]; i++)
        if(temp_passanger[i] + station_passanger[pos] > capacity)
            return 0;
    for(int i = start_station[pos]; i < end_station[pos]; i++)
        temp_passanger[i] += station_passanger[pos];
    return 1;
}

inline void backtrack(int pos)
{
    for(register int i = pos; i < orders; i++) {
        if(!used[i])
            if(can_be_used(i)) {
                used[i] = 1;
                earning += station_income[i];
                max_earning = max(max_earning, earning);
                backtrack(i+1);
                used[i] = 0;
                earning -= station_income[i];
                for(int j = start_station[i]; j < end_station[i]; j++)
                    temp_passanger[j] -= station_passanger[i];
            }
    }
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    while(scanf("%d %d %d", &capacity, &city, &orders) && (capacity || city || orders)) {
        for(register int i = 0; i < orders; i++) {
            scanf("%d %d %d", &start_station[i], &end_station[i], &station_passanger[i]);
            station_income[i] = (end_station[i] - start_station[i]) * station_passanger[i];
        }
        used.reset();
        memset(temp_passanger, 0, sizeof(temp_passanger));
        max_earning = 0;
        backtrack(0);
        printf("%d\n", max_earning);
    }
    return 0;
}
