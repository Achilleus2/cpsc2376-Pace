Bug 1: 
Line 12
Error - The condition in the for loop "i < end" will stop the loop after i has achieved the same value as end and will not add the last value.
Fix - To include the last value the condition should be inclusive of the last value. So it should be "i <= end" and it will add the last number and stop.


Bug 2:
Line 19
Error - The condition in the for loop "i <= numbers.size()" makes sure that the function goes all the way through the vector however it goes out of bounds because the size of the vector and its final position are
		separated by a number of 1. The condition makes sure that the function iterates 1 number too far.
Fix - To fix this, getting rid of the "=" sign  should solve the problem.


Bug 3:
Line 20
Error - The condition of the if statement is supposed to return true if the number is negative "numbers[i] > 0" however it returns true if the number is positve.
Fix - To make sure its check for the right value it should have a less than operator "numbers[i] < 0"


Bug 4:
Line 28
Error - The condition checks if the vector has any exsiting values and if it doesn't then it returns a 0 int value, which is misleading if the vector is empty. 0 is a number and is great than other existing 
		numbers making it a value maxvalue.
Fix - Changing the return value by throwing an exception and adding an explanation explaining the vector has not values would solve this problem.


Bug 5:
Line 30
Error - The condition in the for loop "i <= numbers.size()" makes sure that the function goes all the way through the vector however it goes out of bounds because the size of the vector and its final position are
		separated by a number of 1. The condition makes sure that the function iterates 1 number too far. 
Fix - To fix this, getting rid of the "=" sign  should solve the problem.


Bug 6: 
Line 31
Error - The [] operator access the value in the vector at that position without check if that position already exists. 
Fix - The issue has already be resolved because the for loop was fixed so it didn't iterate out of bounds. I will still change it to .at() to be safe.