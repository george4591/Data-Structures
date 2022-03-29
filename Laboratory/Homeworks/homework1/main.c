#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void swapNames(char *name1, char *name2) {
    char *tempName = (char *) malloc(strlen(name1) + 1);
    strcpy(tempName, name1);
    strcpy(name1, name2);
    strcpy(name2, tempName);

    free(tempName);
}

void sortListOfNames(char *names[], int length)
{
    for (int it = 0; it < length; ++it) {
        for (int it2 = 0; it2 < length - it - 1; it2++) {
            if (strcmp(names[it2], names[it2 + 1]) > 0) {
                swapNames(names[it2], names[it2 + 1]);
            }
        }
    }
}

void printNames(char *names[], int length)
{
    for (int i = 0; i < length; i++) {
        printf("%s\n", names[i]);
    }
}

int main() {
    FILE *pFile = fopen("Data.txt", "r");

    char buffer[128];
    char *names[50];
    int index = 0;

    for (int i = 0; i < 50; i++) {
        names[i] = NULL;
    }

    if (pFile) {
        fscanf(pFile, "%s", buffer);
        while (!feof(pFile)) {
            names[index] = (char *) malloc(strlen(buffer) + 1);
            strcpy(names[index++], buffer);
            fscanf(pFile, "%s", buffer);
        }

        sortListOfNames(names, index);
        printNames(names, index);
    }

    return 0;
}
