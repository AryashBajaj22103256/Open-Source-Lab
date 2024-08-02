#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

void toLowerCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char paragraph[10000];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int frequency[MAX_WORDS] = {0};
    int wordCount = 0;

    printf("Enter a paragraph: ");
    fgets(paragraph, sizeof(paragraph), stdin);

    char *word = strtok(paragraph, " ,.-\n");
    while (word != NULL) {
        toLowerCase(word);
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i], word) == 0) {
                frequency[i]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[wordCount], word);
            frequency[wordCount]++;
            wordCount++;
        }
        word = strtok(NULL, " ,.-\n");
    }

    printf("\nWord Frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i], frequency[i]);
    }

    return 0;
}
