#include "func.h"

void addWord(char* tempWord) {
	// iterates through wordBank (array of wordFreq)
	for (int i = 0; i < wordBankSize; i++) {
		// if there is no word in the wordFreq
		if (!strcmp(wordBank[i].word, "")) {
			// set that wordFreq to the word and increase freq (to 1)
			strcpy(wordBank[i].word, tempWord);
			wordBank[i].freq++;
			break;
		}
		// if word already is in the wordBank
		else if (!strcmp(wordBank[i].word, tempWord)) {
			// increase frequency value
			wordBank[i].freq++;
			break;
		}
	}
}


int compareFreq(const void* a, const void* b) {
	// c is the freq of pointer a
    struct wordFreq *first = (void *)a; 
    const int c = first->freq;
    // d is the freq of pointer b
    struct wordFreq *second = (void *)b;
	const int d = second->freq;

	// logic which determines order
	if (c > d) {
		return -1;
	}
	if (c < d) {
		return 1;
	}
	return 0;
}

int compareWord(const void* a, const void* b) {	
	// c is the freq of pointer a
    struct wordFreq *first = (void *)a; 
    const int c = first->freq;
    // d is the freq of pointer b
    struct wordFreq *second = (void *)b;
	const int d = second->freq;
    // e is the word of pointer a
    const char* e = first->word;
    // f is the word of pointer b
	const char* f = second->word;
	
	// logic which determines order
	if (c == d) {
		return strcmp(e, f);
	} else {
		if (c > d) {
			return -1;
		}
		if (c < d) {
			return 1;
		}
		return 0;
	}
}


void printMostCommonWords(int numberOfWords) {
	// effWordSize is here just so qsort doesn't have to go through empty wordFreqs
	int effWordSize = 0;
	for (int i = 0; i < wordBankSize; i++) {
		if (wordBank[i].freq != 0) {
			effWordSize++;
		}
	}
	// this qsort orders struct based on freq
	qsort(wordBank, effWordSize, wordSize + sizeof(int), compareFreq);
	// this qsort orders struct alphabetically in their freq
	qsort(wordBank, effWordSize, wordSize + sizeof(int), compareWord);
	// print the words and freqs
	for (int i = 0; i < numberOfWords; i++) {
		printf("%d %s\n", wordBank[i].freq, wordBank[i].word);
	}
}
