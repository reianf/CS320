<b>prog2_1.hpp</b><br/>
    This is the header file for the prog2_1 C++ file.

<b>prog2_1.cpp</b><br/>
    This is a C++ file that has the Tokenize and GetTokens functions. The Tokenize function checks to see if each string is a valid token. Valid tokens are push, pop, add, sub, mul, div, mod, skip, save, get and any valid integer. If not a valid token, then the function throws an "Unexpected Token" error on whichever line it is read from. The GetTokens function throws an error if there's no tokens in the queue. If there are tokens, the function puts the first token in a vector<string>, deletes that token from the queue, and then returns that token.

<b>prog2_2.cpp</b><br/>
    This is a driver program that uses prog2_1.hpp and prog2_1.cpp. The program reads in a file line by line and tokenizes it on the space character. Checks to see if the line is a valid token and if not, then prints out an "Unexpected token" error on the line it is read from. If the token is valid, then the program replaces the space character with a commma and prints that token out.
    
<b>prog2_3.hpp</b><br/>
    This is the header file for the prog2_3 C++ file.
    
<b>prog2_3.cpp</b><br/>
    This is a C++ file that has the Parse function. This function checks to see if the string is valid and returns true if it is and if not, the function returns false. The valid tokens are pop, add, sub, mul, div, mod, and skip, on a single line. Other valid tokens are push, save, and get, but only if they have a second integer token on the same line. Any other input is invalid.

<b>prog2_4.cpp</b><br/>
    This is a driver program that uses all the above files. This program reads in a file line by line, tokenizes it, and then parses it. If there is a tokenization error, then the program prints out an "Unexpected token" error on that line. The program then checks to see if there is a parsing error and prints out an "Parse error" error on that line. If all lines are valid, the program prints all lines with commas seperating the tokens.

