//UVa
//325 - Identifying Legal Pascal Real Constants
#include<bits/stdc++.h>
using namespace std;

int main()
{
    regex r1("(\\+|-)?[[:digit:]]+\\.([[:digit:]]+)(([e|E])(\\+|-)?[[:digit:]]++)?");
    regex r2("(\\+|-)?[[:digit:]]+(([e|E])(\\+|-)?[[:digit:]]++)");         //as 1e-16 is also legal
    char x[1000010];
    while(fgets(x, 1000000, stdin)) {
        string y = string(x);
        y = regex_replace(y, regex("^\\s+"), "$1");     //removing front spaces
        y = regex_replace(y, regex("\\n+"), "$1");      //removing all newlines from string
        y = regex_replace(y, regex("\\s+$"), "$1");     //removing all spaces before the end of line (trailing spaces)
        if(y[0] == '*' && y.size() == 1) break;
        if(regex_match(y, r1) || regex_match(y, r2))
           printf("%s is legal.\n", y.c_str());
        else printf("%s is illegal.\n", y.c_str());
    }
    return 0;
}
