#include "func.h"

int main() {
	// initialize the structs
	for (int i = 0; i < wordBankSize; i++) {
		strcpy(wordBank[i].word, "");
		wordBank[i].freq = 0;
	}
	// declaring variables:
	// (buffer = sting of a line in input file)
	char buffer[bufferSize];
	// (tempWord = string that will insert into struct)
	char tempWord[wordSize];
	// (c = a char in buffer that concatinates to tempWord)
	char c;
	// initialize tempWord
	strcpy(tempWord, "");
	
	// iterates through each line of input file
	while (fgets(buffer, bufferSize, stdin) != NULL) {
		// prints content of file
		printf("%s", buffer);
	    for (int i = 0; i < strlen(buffer); i++) {
	        c = buffer[i];
	        // if "zzzzz" is seen in the file, then stop going through it
		    if (strcmp(tempWord, "zzzzz") == 0) {
		    	break;
		    }	
		    // if c is the end of a word
			if ((c == ' ')  || (c == '\n')) {
				addWord(tempWord); 
				strcpy(tempWord, "");
			} else {
				// otherwise, c is not at the end of the word
				strncat(tempWord, &c, 1);
			}
		}
	}
	// all the word are in the stuct, time to print them
	printf("\n======\n");
	printMostCommonWords(5);
	return 0;
}

