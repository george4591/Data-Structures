#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

        // Sort the names
        for (int i = 0; i < index; ++i) {
            for (int j = 0; j < index - i - 1; j++) {
                // Compare first letter of each name
                if (names[j][0] > names[j + 1][0]) {
                    char *name = (char *) malloc(strlen(buffer) + 1);
                    strcpy(name, names[j]);
                    names[j] = names[j + 1];
                    names[j + 1] = name;
                }
            }
        }

        // print the names
        for (int i = 0; i < index; i++) {
            printf("%s\n", names[i]);
        }

    }

    return 0;
}
