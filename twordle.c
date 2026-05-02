//Author: Kasia Syn
//Project 10 


#include <stdio.h> 
#include <stdbool.h>
//function for getting the word from the document into a 1D array FILE IO ReadDocument into wordFromDocArray HAS PROBLEMS!
//function for taking the guesses from the user and checking IF they meet requirements DONE?
//function that checks the amount of guesses and whether they got the word or not
//function for changing any entered capital letter into a lowercase ASCII TABLE +32 DONE?
//function for checking each element of the 1D Array and 2D Array 12 rows UHH IDK MAYBE?
//function for changing letters into capital or adding a caret in the 2D array 2 row
//function for printing guesses 
//void scanWord(wordFromMysteryDoc, char wordFromDocArray);
void readDocument(FILE *wordFromMysteryDoc, char *wordFromDocArray);
void userGuess(char guess[50], int guessNum);
void changeLetters(char guess[50]);
void checkAnswers(char currentGuess[6],char userGuesses[12][6], int guessNum, char wordFromDocArray[6]);
void printOut(char userGuessArray[12][6], int guessNum);
bool correctWord(char wordFromDocArray[6],char guess[50],char capGuess[50];);

int main(){
	
	FILE *wordFromMysteryDoc;
	char wordFromDocArray[6];
	char userGuesses[12][6];
	char currentGuess[50];
	char capGuess[50];
	int guessNum;
	wordFromMysteryDoc = fopen("mystery.txt", "r");
	if(wordFromMysteryDoc == NULL){
		printf("cannot open file\n");
		return 1;
	}
	
	readDocument(wordFromMysteryDoc, wordFromDocArray);
	fclose(wordFromMysteryDoc);
	for(guessNum = 1; guessNum <= 6; guessNum++){
		userGuess(currentGuess, guessNum);
		changeLetters(currentGuess);
		if(correctWord(wordFromDocArray, currentGuess,capGuess)){
			printf("================================\n");
			printf("\t\t%s\n",capGuess);
			
				if(guessNum == 1){
					printf("\tYou won in 1 guess!\n");
					printf("\t\tGOATED!\n");
				}
				if(guessNum >= 2 && guessNum <= 5){
					printf("\tYou won in %d guesses!\n", guessNum);
					printf("\t\tAmazing!\n");
				}
				if(guessNum == 6){
					printf("\tYou won in %d guesses!\n", guessNum);
					printf("\t\tNice!\n");
				}
			
			return 0;
		}
		checkAnswers(currentGuess,userGuesses, guessNum, wordFromDocArray);
		printOut(userGuesses, guessNum);
		
		
	}
	printf("You lost, better luck next time!\n");
	
	

	return 0;
}


void readDocument(FILE *wordFromMysteryDoc, char *wordFromDocArray){
	fscanf(wordFromMysteryDoc, "%s", wordFromDocArray);
	
}


void changeLetters(char guess[50]){
	int index;
	for(index = 0; index < 5; index++){
		if(guess[index] >= 'A' && guess[index] <= 'Z'){
			guess[index] = guess[index] + 32;
		}
	}
}


void userGuess(char guess[50], int guessNum){
	int index;
	bool notFive, notAlpha;
	if(guessNum <= 5){
		printf("GUESS %d! Enter your guess: ", guessNum);
		scanf("%49s", guess);
	}
	else{
		printf("FINAL GUESS : ");
		scanf("%49s", guess);
	}
	
	do{
		notAlpha = false;
		notFive = false;
		for(index = 0; index < 6; index++){
			if((!(guess[index] >= 'A' && guess[index] <='Z') && !(guess[index] >= 'a' && guess[index] <='z')) && guess[index] != '\0' ){
				notAlpha = true;
			}
			if(index >= 5 && guess[index] != '\0' && guess[index] != ' '){
				notFive = true;
			}
			if(guess[index] == '\0' && index < 5){
				notFive = true;
			}
			
		}
		if(notAlpha || notFive){
			if(notAlpha){
				printf("Your guess must contain only letters.");
			}
			if(notFive){
				printf("Your guess must be 5 letters long.");
			}
			printf("\nPlease try again:");
			scanf("%49s", guess);
		}
		
	}while(notAlpha || notFive);
}

void checkAnswers(char currentGuess[6],char userGuesses[12][6], int guessNum, char wordFromDocArray[6]){
	int guessIndex, wordIndex;
	char correctLetters[5];
	char carotLetters[5];
	
	int carotInputIndex = 0, correctInputIndex = 0;
	int checkIndex;
	bool inCheck, carotPlaced = false;
	for(checkIndex = 0; checkIndex < 5 ; checkIndex++){
		correctLetters[checkIndex] = '\0';
		carotLetters[checkIndex] = '\0';
	}
	for(guessIndex = 0; guessIndex < 5; guessIndex ++){
		
		if(currentGuess[guessIndex] == wordFromDocArray[guessIndex]){
			correctLetters[correctInputIndex] = currentGuess[guessIndex];
			correctInputIndex++;
			userGuesses[(guessNum-1)*2][guessIndex] = currentGuess[guessIndex] - 32;
		}else{
			userGuesses[(guessNum-1)*2][guessIndex] = currentGuess[guessIndex];
		}
	}
	for(guessIndex = 0; guessIndex < 5 ; guessIndex++){
		for(wordIndex = 0; wordIndex < 5 ; wordIndex++){
			if(wordIndex != guessIndex && currentGuess[guessIndex] == wordFromDocArray[wordIndex]){
				inCheck = false;
				for(checkIndex = 0; checkIndex < 5 && !inCheck; checkIndex++){
					if(currentGuess[guessIndex] == carotLetters[checkIndex] || currentGuess[guessIndex] == correctLetters[checkIndex]){
						inCheck = true;
					}
				}
				if(!inCheck){
					carotPlaced = true;
					userGuesses[(guessNum*2)-1][guessIndex] = '^';
					carotLetters[carotInputIndex] = currentGuess[guessIndex];
					carotInputIndex++;
				}
			}
		}
		if(!carotPlaced){
			userGuesses[(guessNum*2)-1][guessIndex] = ' ';
		}
		carotPlaced = false;
	}
	
}


void printOut(char userGuessArray[12][6], int guessNum){
	printf("================================\n");
	for(int index = 0 ; index < guessNum; index++){
		printf("%s\n",userGuessArray[(index)*2]);
		printf("%s\n",userGuessArray[(index*2)+1]);
	}
	
}
bool correctWord(char wordFromDocArray[6],char guess[50], char capGuess[50]){
	bool matching = true;
	for(int guessIndex = 0; guessIndex < 5 && matching; guessIndex ++){
		
		if(guess[guessIndex] != wordFromDocArray[guessIndex]){
			return false;
		}else{			
			capGuess[guessIndex] = guess[guessIndex] - 32;
		}
	}
	return true;
}











