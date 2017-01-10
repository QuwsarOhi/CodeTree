#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    //regex r("(\\+|-)?[[:digit:]]+(\\.([[:digit:]]+)?)?");
    regex r1("(\\+|-)?[[:digit:]]+\\.([[:digit:]]+)(([e|E])(\\+|-)?[[:digit:]]++)?");
    regex r2("(\\+|-)?[[:digit:]]+(([e|E])(\\+|-)?[[:digit:]]++)");
    regex parse("(\\s)?[^]+(\\s)?");
    char x[1000010];
    while(fgets(x, 1000000 ,stdin)) {
        int len = strlen(x);
        string y;
        /*bool start = 0;
        for(register int i = 0; i < len; i++) {
            if(isalpha(x[i])) start = 1;
            if(start) y+=x[i];
            if(start && isspace(x[i])) break;
        }*/
        //y = x;
        //string y = regex_replace(x, regex("^ +"), "");
        //y[y.size()-1] = '\0';
        str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
        if(x[0] == '*' && y.size() == 1) break;
        //if(regex_match(y, parse)) printf("worked\n");
        if(regex_match(y, r1) || regex_match(y, r2))
           printf("%s is legal.\n", y.c_str());
        else printf("%s is illegal.\n", y.c_str());
    }
    return 0;
}
