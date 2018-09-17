<b>prog3_1.cpp</b><br/>
    This is a C++ file that takes in two command line arguments with the 2nd argument being a lua file. The program then executes the lua file in a lua environment. The lua-5.3.4 source folder should already be in the directory where this program will be compiled. Example compile: g++ prog3_1.cpp -o prog3_1 -I lua-5.3.4/src -L lua-5.3.4/src -l lua -l m -l dl

<b>prog3_2.lua</b><br/>
    This is a lua file that implements the InfixToPostfix function. It first takes in an user-inputted infix equation, the program then tokenizes the equation on the space-delimeter. After tokenization, the program takes that equation, converts it to postfix form, and prints it out. The program then evaluates the postfix equation and prints out the result. Example compile: ./prog3_1 prog3_2.lua

<b>prog3_3.cpp</b><br/>
    This is a C++ file that takes in two command line arguments with the 2nd argument being a lua file. The program then executes the lua file in a lua environment and loads/runs the file. The program then takes in user input, calls the InfixToPostfix function, returning and printing out the postfix formed equation, as well as the evaluation of that postfix string. The lua-5.3.4 source folder should already be in the directory where this program will be compiled. Example compile: ./prog3_3 prog3_2.lua
