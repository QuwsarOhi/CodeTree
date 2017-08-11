#!usr/bin/env python3

# Base class / Parent Class

class Person:
	def __init__(self, firstName, lastName, idNumber):		# Constructor
		self.firstName = firstName
		self.lastName = lastName
		self.idNumber = idNumber
	
	def printPerson(self):									# Member function / method
		print("Name:", self.lastName + ',', self.firstName)
		print("ID:", self.idNumber)

class Student(Person):										# Child class
    #   Class Constructor
    #   Parameters:
    #   firstName - A string denoting the Person's first name.
    #   lastName - A string denoting the Person's last name.
    #   id - An integer denoting the Person's ID number.
    #   scores - An array of integers denoting the Person's test scores.
    #
    # Write your constructor here
    def __init__(self, firstName, lastName, idNumber, scores):				# Constructor of this Class
		# There are two ways to call the base / parent constructor with/without parameters
		# First way :
        Person.__init__(self, firstName, lastName, idNumber)
        
        # Second way, this is commented code, usage of super() function
        # super(Student, self).__init__(firstName, lastName, idNumber)		# Calling the constructor of base / parent class with it's parameters
        self.scores = scores												# Extra initialization for the extra parameter that the base class doesnt contain

    #   Function Name: calculate
    #   Return: A character denoting the grade.
    #
    # Write your function here
    def calculate(self):
        sum = 0
        for x in scores:
            sum += x
        avg = sum/len(scores)
        if avg >= 90 and avg <= 100:
            return 'O'
        elif avg >= 80 and avg < 90:
            return 'E'
        elif avg >= 70 and avg < 80:
            return 'A'
        elif avg >= 55 and avg < 70:
            return 'P'
        elif avg >= 40 and avg < 55:
            return 'D'
        else:
            return 'T'


# IO operations

line = input().split()
firstName = line[0]
lastName = line[1]
idNum = line[2]
numScores = int(input())	# not needed for python, as it doesnt need array allocation
scores = list(map(int, input().split()))	# getting input from splitted string list and passing them to the int function, creating a list from map object 

s = Student(firstName, lastName, idNum, scores)
s.printPerson()
print("Grade:", s.calculate())
