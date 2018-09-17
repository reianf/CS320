#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include"prog1_2.h"

//function that removes spaces from string and counts tokens per stdin
void Tokenize(char* input, int* token) {
	int i,j,k,length = strlen(input);
	char *output=input;
	for (i = 0, j = 0; i< length; i++,j++)
	{
		if (input[i]!=' ') {
			output[j]=input[i];	
			if (input[i+1] == ' ') (*token)++;
		}
		else {
			j--;
		}
	}
	if (input[length-2] != ' ') (*token)++;
	output[j-1]=0;
}

int main(int argc, char* argv[]) {
	printf("Assignment #1-3, Reian Festejo, rfestejo@sdsu.edu\n");
	if(argc != 2) {
		printf("\nThis program expects a single commmand line argument.\n\n");
		return 0;
	}    
	STACK *stack = MakeStack(256);
	int tokens = 0;
	char *n = argv[1];
	int number = strtol(n,NULL, 10);
	int numlen = strlen(argv[1]);
	while(number != 0) {
		char *str = (char *) malloc(sizeof(char)*256);
		printf("> ");
		fgets(str, 256, stdin); 
		Tokenize(str, &tokens);
		if(tokens < 3) {
			if(strlen(str) == 3 && strcmp(str, "pop") == 0) { // pop
				printf("%d\n", Pop(stack));
			} else if(strncmp(str, "push", 4) == 0) { //push
				if(tokens != 1) { //if str is not eg. push2
					str = str + 4;
					char *remainPtr;
					long num = strtol(str, &remainPtr, 10); // convert number to int
					Push(stack, num);
				}
			}
		}
		tokens = 0;
		number--; 
	}
	return 0;
}