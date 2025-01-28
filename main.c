#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define maxwordlength 50
#define maxtries 6
struct wordwithhint {
    char word[maxwordlength];
    char hint[maxwordlength];
};
void displayword(const char word[], const bool guessed[]);
void drawhangman( int tries);

int main() {
srand(time( NULL));
    struct wordwithhint wordlist[]={
{"geeksforgeeks","Competer coding"},
        {"elephant","A large mammal with a trunk"},
        {"pizza","A populer italian food"},
        {"beach","Sand shore by the sea"},
    };
int wordindex = rand() % 4;
    const char* secretword = wordlist[wordindex].word;
    const char* hint = wordlist[wordindex].hint;
    int wordlenght = strlen(secretword);
    char guessedword[maxwordlength] = {0};
    bool guessedletters[26] = {false};
    printf("Welcome to Hangman!\n");
    printf("Hint :%s\n",hint);
    int tries = 0;
    while ( tries < maxtries) {
        printf("\n");
        displayword(guessedword,guessedword);
        drawhangman(tries);
        char guess;
        printf("Enter a letter: ");
        scanf("%c",&guess);
        guess=tolower(guess);
        if (guessedletters[guess - 'a']) {
            printf("You have a guessed that latter Try again.");
            continue;
        }
        guessedletters[guess - 'a'] = true;
        bool found = false;
        for (int i=0; i<wordlenght; i++) {
            if (secretword[i] == guess) {
                found = true;
                    guessedword[i] = guess;
            }
        }
        if (found) {
            printf("Good guess!!\n");

        }
        else {
            printf("Sorry the latter %c is not in the true word\n",guess);
            tries++;
        }
        if (strcmp(secretword,guessedword)==0) {
            printf("Congratulations! You've guessed the secret word : %s\n",secretword);
            break;
        }

    }
    if (tries > maxtries) {
        printf("Sorry you've run out of tries the word was : %s\n",secretword);
    }


    return 0;
}
void displayword(const char word[], const bool guessed[]) {
    printf("Word : ");
    for (int i =0; word[i]!='\0'; i++) {
        if (guessed[word[i]-'a']) {
            printf("%c",word[i]);
        }
        else {
            printf("_ ");
        }
    }
    printf("\n");
}
void drawhangman (int tries) {
    const char* hangmantries[] = { "     _________",    "    |         |",
                                   "    |         O",   "    |        /|\\",
                                   "    |        / \\", "    |" };
    printf("\n");
    for (int i =0; i < tries; i++) {
        printf("%s\n",hangmantries[i]);
    }
}