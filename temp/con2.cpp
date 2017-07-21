#include <bits/stdc++.h>
using namespace std;


// Alice : the player who takes the last loses
// Bob : the player who takes tha last wins

bool whoWin(int x, bool person, bool flip) {		// 1 = Alice, 0 = Bob, flip == 1 : alice starts the game
	if(x == 0) {
		if(flip)
			return person;
		return !person;
	}
	
	//if(whoWin(x-1, !person, flip) == person || whoWin(x-2, !person, flip) == person)
		//return person;
	

	if(x >= 2 && whoWin(x-2, !person, flip) == person)
		return person;
	if(x >= 1 && whoWin(x-1, !person, flip) == person) {
		//printf("reached here\n");
		return person;
	}
	
	//printf("Reached last %d %d %d\n", x, (int)person, (int)flip);
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
