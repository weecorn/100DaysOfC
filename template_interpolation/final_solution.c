#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TEMPLATE 256
#define MAX_KEY 50
#define MAX_VALUE 50
#define MAX_PAIRS 10

typedef struct {
    char key[MAX_KEY];
    char value[MAX_VALUE];
} KeyValuePair;

void replacePlaceholders(char *template, KeyValuePair *pairs, int pairCount, char *output, int outputSize) {
    char *start = template;
    char *placeholderStart;
    output[0] = '\0'; // Clear the output string

    while ((placeholderStart = strchr(start, '{')) != NULL) {
        strncat(output, start, placeholderStart - start); // Copy text before placeholder
        char *placeholderEnd = strchr(placeholderStart, '}');
        if (placeholderEnd == NULL) {
            // No closing brace; copy the rest and exit
            strncat(output, placeholderStart, outputSize - strlen(output) - 1);
            break;
        }

        // Extract placeholder key
        char key[MAX_KEY];
        size_t keyLength = placeholderEnd - placeholderStart - 1;
        strncpy(key, placeholderStart + 1, keyLength);
        key[keyLength] = '\0';

        // Find replacement value
        const char *replacement = "";
        for (int i = 0; i < pairCount; i++) {
            if (strcmp(pairs[i].key, key) == 0) {
                replacement = pairs[i].value;
                break;
            }
        }

        // Append replacement to output
        strncat(output, replacement, outputSize - strlen(output) - 1);

        // Move start pointer past the placeholder
        start = placeholderEnd + 1;
    }

    // Copy the remaining part of the template
    strncat(output, start, outputSize - strlen(output) - 1);
}

int main() {
    char template[MAX_TEMPLATE];
    KeyValuePair pairs[MAX_PAIRS];
    int pairCount;

    // Input template string
    printf("Enter the template string (max %d characters):\n", MAX_TEMPLATE - 1);
    fgets(template, MAX_TEMPLATE, stdin);
    template[strcspn(template, "\n")] = '\0'; // Remove trailing newline

    // Input key-value pairs
    printf("Enter the number of key-value pairs (max %d): ", MAX_PAIRS);
    scanf("%d", &pairCount);
    getchar(); // Consume newline character left by scanf

    if (pairCount > MAX_PAIRS) pairCount = MAX_PAIRS;

    for (int i = 0; i < pairCount; i++) {
        printf("Enter key %d: ", i + 1);
        fgets(pairs[i].key, MAX_KEY, stdin);
        pairs[i].key[strcspn(pairs[i].key, "\n")] = '\0'; // Remove newline

        printf("Enter value for '%s': ", pairs[i].key);
        fgets(pairs[i].value, MAX_VALUE, stdin);
        pairs[i].value[strcspn(pairs[i].value, "\n")] = '\0'; // Remove newline
    }

    // Perform interpolation
    char output[MAX_TEMPLATE];
    replacePlaceholders(template, pairs, pairCount, output, MAX_TEMPLATE);

    // Print the final result
    printf("\nInterpolated String:\n%s\n", output);

    return 0;
}
