2048

This 3 programs uploaded have the same game 2048 in it. only different settings, 3*3, 4*4 and 5*5.

the code for all of the three is pretty much the same apart from the numberr of iterations and one line of code to determine the position of random 2s and 4s to appear at.


//WORKING//
the main function starts with code to have a random number generator and print out a grid with the two random numbers.
then we take in input from the user to have the functions 'moveleft','moveright','moveup' and 'movedown' based on the input recieved.
if none of the functions are called, the program continues the loop for that iteration.
if any of the functions are called,it goes on to check if there has been any difference in the past iteration and the current one.
if it is not the same, the 'add' function is called, to add a random 2 or 4 in a random non'occupied cell in the grid.
it goes on to check if the game is over by calling the 'notloser' function. _f it returns 0, the loop exits and prints the High score and exits the program._
