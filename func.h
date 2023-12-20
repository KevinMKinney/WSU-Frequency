#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// size of a word that wordFreq can hold 
#ifndef wordSize
#define wordSize	100
#endif
// size of wordBank / array of wordFreq / number of unique words
#ifndef wordBankSize
#define wordBankSize	200
#endif
// size of a line in input file
#ifndef bufferSize
#define bufferSize	200
#endif

#ifndef wordFreqStruct
#define wordFreqStruct
struct wordFreq {
	// declaring struct that constains a string and int
	char word[wordSize];
	int freq;
};
#endif

// declaring array of the wordFreq struct
struct wordFreq wordBank[wordBankSize];

// declaring functions in func.c file
#ifndef addWord
void addWord(char* tempWord);
#endif

#ifndef compareFreq
int compareFreq(const void* a, const void* b);
#endif

#ifndef compareWord
int compareWord(const void* a, const void* b);
#endif

#ifndef printMostCommonWords
void printMostCommonWords(int numberOfWords);
#endif
