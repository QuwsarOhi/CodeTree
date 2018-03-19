// Aho-Corasick
// Complexity : O(n+m+z)

// n : Length of text
// m : total length of all keywords
// z : total number of occurance of word in text

#include <bits/stdc++.h>
using namespace std;

const int TOTKEY = 505;                 // Total number of keywords
const int KEYLEN = 505;                 // Size of maximum keyword

const int MAXS = TOTKEY*KEYLEN + 10;    // Max number of states in the matching machine.
                                        // Should be equal to the sum of the length of all keywords.
const int MAXC = 26;                    // Number of characters in the alphabet.

bitset<TOTKEY> out[MAXS];               // Output for each state, as a bitwise mask.

int f[MAXS];                            // Failure function
int g[MAXS][MAXC];                      // Goto function, or -1 if fail.
 
int buildMatchingMachine(const vector<string> &words, char lowestChar = 'a', char highestChar = 'z') {
    for(int i = 0; i < MAXS; ++i)
        out[i].reset();
    memset(f, -1, sizeof f);
    memset(g, -1, sizeof g);
    
    int states = 1;                                         // Initially, we just have the 0 state
    for(int i = 0; i < (int)words.size(); ++i) {
        const string &keyword = words[i];
        int currentState = 0;
        for(int j = 0; j < (int)keyword.size(); ++j) {
            int c = keyword[j] - lowestChar;
            if(g[currentState][c] == -1)                    // Allocate a new node
                g[currentState][c] = states++;
            currentState = g[currentState][c];
        }
        out[currentState].set(i);                      // There's a match of keywords[i] at node currentState.
    }

    for(int c = 0; c < MAXC; ++c)                           // State 0 should have an outgoing edge for all characters.
        if(g[0][c] == -1)
            g[0][c] = 0;
                                                                // Now, let's build the failure function
    queue<int> q;
    for(int c = 0; c <= highestChar - lowestChar; ++c)          // Iterate over every possible input
        if(g[0][c] != -1 and g[0][c] != 0) {                    // All nodes s of depth 1 have f[s] = 0
            f[g[0][c]] = 0;
            q.push(g[0][c]);
        }

    while(q.size()) {
        int state = q.front();
        q.pop();
        for(int c = 0; c <= highestChar - lowestChar; ++c) {
            if(g[state][c] != -1) {
                int failure = f[state];
                
                while(g[failure][c] == -1)
                    failure = f[failure];
                
                failure = g[failure][c];
                f[g[state][c]] = failure;
                out[g[state][c]] |= out[failure];               // Merge out values
                q.push(g[state][c]);
            }
        }
    }
 
    return states;
}


int findNextState(int currentState, char nextInput, char lowestChar = 'a') {
    int answer = currentState;
    int c = nextInput - lowestChar;
    while(g[answer][c] == -1)
        answer = f[answer];
    return g[answer][c];
}


int cnt[TOTKEY];
void Matcher(vector<string> &keywords, string &text) {
    int currentState = 0;
    memset(cnt, 0, sizeof cnt);
    
    for(int i = 0; i < (int)text.size(); ++i) {
        currentState = findNextState(currentState, text[i]);
        if(out[currentState] == 0)                              // Nothing new, let's move on to the next character.
            continue;

        for(int j = 0; j < (int)keywords.size(); ++j)
            if(out[currentState][j])                            // Matched keywords[j]
                ++cnt[j];
    }
}

string text, str;
vector<string>keywords;

// RETURN NUMBER OF MATHCES FOR EACH WORD APPEARING IN "KEYWORD" VECTOR
// INPUT STRING IS "TEXT"

int main() {
    int t, n;
    cin >> t;
    
    for(int Case = 1; Case <= t; ++Case) {
        cin >> n;
        cin >> text;
        
        while(n--) {
            cin >> str;
            keywords.push_back(str);
        }
        
        buildMatchingMachine(keywords);

        cout << "Case " << Case << ":\n";
        Matcher(keywords, text);
        for(int i = 0; i < (int)keywords.size(); ++i)
            cout << cnt[i] << "\n";
        
        keywords.clear();
    }
    
    return 0;
}

