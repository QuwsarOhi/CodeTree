//UVa
//416 - LED Test
#include<bits/stdc++.h>
using namespace std;

int n, number[15], led[15];
char a[20];
bool found;

void num_gen()
{
    memset(number, 0, sizeof(number));
    //zero
    for(register int i = 0; i < 6; i++)
        number[0] |= (1 << i);
    //one
    number[1] |= (1 << 1);
    number[1] |= (1 << 2);
    //two
    number[2] |= (1 << 0);
    number[2] |= (1 << 1);
    number[2] |= (1 << 6);
    number[2] |= (1 << 4);
    number[2] |= (1 << 3);
    //three
    for(register int i = 0; i < 4; i++)
        number[3] |= (1 << i);
    number[3] |= (1 << 6);
    //four
    number[4] |= (1 << 1);
    number[4] |= (1 << 2);
    number[4] |= (1 << 5);
    number[4] |= (1 << 6);
    //five
    number[5] |= (1 << 0);
    number[5] |= (1 << 5);
    number[5] |= (1 << 6);
    number[5] |= (1 << 2);
    number[5] |= (1 << 3);
    //six
    for(register int i = 2; i < 7; i++)
        number[6] |= (1 << i);
    number[6] |= (1 << 0);
    //seven
    for(int i = 0; i < 3; i++)
        number[7] |= (1 << i);
    //eight
    for(int i = 0; i < 7; i++)
        number[8] |= (1 << i);
    //nine
    for(register int i = 0; i < 4; i++)
        number[9] |= (1 << i);
    number[9] |= (1 << 5);
    number[9] |= (1 << 6);
}

void is_match(int number_pos, int led_pos, int burnout)
{
    if(led_pos >= n) {
        found = 1;
        return;
    }
    //lights turned on originally in a number must be equal or greater than the led light we get from input
    //and burnout light must coincide(if any) with the led light
    //so if any light is burned out but we still find it lighted in led, then led[led_pos] & burnout would be one
    if((__builtin_popcount(number[number_pos]) >= __builtin_popcount(led[led_pos])) && !(led[led_pos] & burnout)) {
        int MissMatch = number[number_pos] ^ led[led_pos];
        //the lights turned off in number must be off in the led
        if(!((number[number_pos] ^ led[led_pos]) & led[led_pos]))
            //adding extra burnouts if there is any, and proceeding
            is_match(number_pos-1, led_pos+1, MissMatch | burnout);
    }
    return;
}

int main()
{
    num_gen();
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    while(scanf("%d", &n) && n) {
        memset(led, 0, sizeof(led));
        for(register int i = 0; i < n; i++) {
            scanf("%s", a);
            for(register int j = 0; j < 7; j++)
                if(a[j] == 'Y')
                    led[i] |= (1 << j);
        }
        found = 0;
        for(register int i = 9; i - n + 1 >= 0 && !found; i--)
            is_match(i, 0, 0);
        if(found)
            printf("MATCH\n");
        else
            printf("MISMATCH\n");
    }
    return 0;
}
