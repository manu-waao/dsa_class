#include <stdio.h>
#include <string.h>

void main(){
    char string[50];
    printf("Enter a string : \n");
    fgets(string, sizeof(string), stdin);

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] >= 'A' && string[i] <= 'Z') {
            string[i] += 'a' - 'A'; 
        }
    }
    printf("The string is : %s", string);
}