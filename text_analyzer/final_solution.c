#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[1000];
    int sentences = 0, words = 1, characters = 0, vowels[5] = {0};
    int i; // simple, but effective

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    // Remove trailing newline from fgets
    text[strcspn(text, "\n")] = 0;

    for (i = 0; text[i] != '\0'; i++) {
        characters++;

        if (text[i] == ' ' || text[i] == '\t' || text[i] == '\n') {
            words++;
        } else if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences++;
        }

        switch (tolower(text[i])) {
            case 'a': vowels[0]++; break;
            case 'e': vowels[1]++; break;
            case 'i': vowels[2]++; break;
            case 'o': vowels[3]++; break;
            case 'u': vowels[4]++; break;
        }
    }

    printf("Number of sentences: %d\n", sentences);
    printf("Number of words: %d\n", words);
    printf("Number of characters: %d\n", characters);
    printf("Vowel frequency:\n");
    printf("  a: %d\n", vowels[0]);
    printf("  e: %d\n", vowels[1]);
    printf("  i: %d\n", vowels[2]);
    printf("  o: %d\n", vowels[3]);
    printf("  u: %d\n", vowels[4]);

    return 0;
}