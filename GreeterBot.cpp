#A program which asks user for name input and age input, then outputs the interger length of name and age the user will be turning next

#This program says "Welcome to Python" and asks for my name.
print ("Welcome to Python!")

#Asks for user name input.
print ("Input your name to start")

#Function for input of name.
myName = input()

#Program responds to user input.
print ("It is good to meet you, " + myName)
print ("The length of your name is;")
print (len(myName))

#Asks for user age input.
print ("What is your age?")

#Function for input of age.
myAge = input()

#Program responds to user input.
print ("You will be " + str(int(myAge) + 1) + " in a year.")
