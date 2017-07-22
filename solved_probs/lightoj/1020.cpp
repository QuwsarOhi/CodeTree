// 1020 - A Childhood Game
// Math, Game Theory, Pattern

// This kind of problem can be solved with math/pattern

// There is a mathamatical proof for this problem
// In contest enviornment, it would be tough to prove this in a short time
// so I wrote a bruteforce solution (given in the comment below) and found the pattern, then
// I wrote the main code 

// Try to prove why this pattern works


#include <bits/stdc++.h>
using namespace std;


int main() {
	int t, x;
	char s[20];
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d %s", &x, s);
		printf("Case %d: ", Case);
		if(strcmp(s, "Bob") == 0) {
			if(x%3 == 0)
				printf("Alice\n");
			else
				printf("Bob\n");
		}
		else {
			//printf("Here\n");
			if((x-1)%3 == 0)
				printf("Bob\n");
			else
				printf("Alice\n");
		}
	}
	return 0;
}



/* This code was used to find the pattern


#include <bits/stdc++.h>
using namespace std;


// Alice : the player who takes the last loses
// Bob : the player who takes tha last wins

bool whoWin(int x, bool person, bool flip) {		// 1 = Alice, 0 = Bob, flip == 1 : alice starts the game, so flip the winning person
	if(x == 0) {
		if(flip)
			return person;
		return !person;
	}

	if(x >= 2 && whoWin(x-2, !person, flip) == person)
		return person;
	if(x >= 1 && whoWin(x-1, !person, flip) == person)
		return person;
	return !person;
}
		


int main() {
	int x, y;
	bool q;
	
	while(1) {
		scanf("%d %d", &x, &y);
		if(y == 1) {
			if(whoWin(x, 1, 1))
				printf("Alice\n");
			else
				printf("Bob\n");
		}
		else {
			if(whoWin(x, 0, 0) == false)
				printf("Bob\n");
			else
				printf("Alice\n");
		}
	}
	return 0;
}

*/
