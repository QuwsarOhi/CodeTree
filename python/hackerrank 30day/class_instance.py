#!/usr/bin/env python3

class Person:
    # initialAge = 0
    def __init__(self,initialAge):
        if(initialAge < 0):
            print("Age is not valid, setting age to 0.")
            self.initialAge = 0
        else:
            self.initialAge = initialAge
        # Add some more code to run some checks on initialAge
    def amIOld(self):
        # Do some computations in here and print out the correct statement to the console
        if self.initialAge < 13:
            print("You are young.")
        elif self.initialAge >= 13 and self.initialAge < 18:
            print("You are a teenager.")
        else:
            print("You are old.")
        
    def yearPasses(self):
        self.initialAge += 1
        # Increment the age of the person in here      

# Creating object and testing

t = int(input())
for i in range(0, t):
	age = int(input())
	p = Person(age)
	p.amIOld()
	for j in range(0, 3):
		p.yearPasses()
	p.amIOld()
	print("")

