
//OLD VERSION BECAUSE I CANT SPELL WORDLE IGNORE THIS 










//Author: Kasia Syn
//Project 10 

void getWordFromFile(char givenWord [0][4], wordleFile);
#include <stdio.h>
FILE* wordleFile;
int main(){
char givenWord([0][4];
	wordleFile = fopen("mystery.txt", "r");
	if(wordleFile == NULL){
		printf("could not open file");
	}
	getWordFromFile(givenWord);
	
	
	
	fclose(wordleFile);

	return 0;
}

void getWordFromFile(char givenWord [0][4], wordleFile){
	int row, col;
	fscanf(wordlFile, "%c", wordleFile);
	for(row = 0; row <= 0; row++){
		for(col =0; col <= 0; col++){
			printf("%c", wordleFile);
		}
	}
}
































