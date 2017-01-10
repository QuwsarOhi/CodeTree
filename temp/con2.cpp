#include<bits/stdc++.h>


using namespace std;

int main()
{
    string value = "\tthis  line conta ins     \n";
    value = regex_replace(value, regex("^\\s+"), "$1");
    value = regex_replace(value, regex("\\n+"), "$1");
    value = regex_replace(value, regex("\\s+$"), "$1");
    value = regex_replace(value, regex("^\\s+\\n+\\s+$"), "$1");
    printf("%s", value.c_str());
    printf("|");
    return 0;
}
