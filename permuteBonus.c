//extra credit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//prototype functions 
void ExchangeCharacters(char str[], int i, int j);
void RecursivePermute(char str[], int k);

// call function exchange characters 
// Function to exchange characters at positions i and j in a string
void ExchangeCharacters(char str[], int i, int j) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}//end function call 

//call given function 
// Recursive function to generate permutations
void RecursivePermute(char str[], int k) {
    int j;
    
    // Basecase: Since all letters are fixed, we can ONLY print what's stored in str.
    if (k == strlen(str)) {
        printf("%s\n", str);
    } else {
        // Loop through each possible starting letter for index k, the first index for which we have a choice
        for (j = k; j < strlen(str); j++) {
            // Place the character stored in index j in location k.
            ExchangeCharacters(str, k, j);

            // Print out all of the permutations with that character just chosen above fixed.
            RecursivePermute(str, k + 1);

            // Put the original character that used to be there back in its place.
            ExchangeCharacters(str, j, k);
        }
    }
}//end function call 

//call main 
int main() {
    char inputStr[] = "abc"; // Change this string to the desired input
    RecursivePermute(inputStr, 0);
    return 0;
}//end main 
