#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"

/*
 * Clear the buffer
 * */
void clear_buffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

/*
 * Change the \n character with \0
 * */
void remove_line(char *user_input) {
    size_t len = strlen(user_input);

    if (len > 0 && user_input[len - 1] == '\n') {
        user_input[len - 1] = '\0';
    } else {
        clear_buffer();
    }
}

/*
 * Function check if the text is empty & return '/0'
 * */
int is_empty_input(const char *text) { 
    return text[0] == '\0'; 
}

/* 
 * This function take user input and return the number if user input is number
 * */
int integer_convertor(int minimum_number, int maximum_number) {
    char buffer[BUFFER_LIMIT];

    while (true) {

        printf("Enter choice: ");
        // Checks if reading from the keyboard failed or if the user signaled
        // EOF (Ctrl+D)
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Input error.\n");
            continue;
        }

        // Detect truncated input
        if (buffer[strlen(buffer) - 1] != '\n') {
            clear_buffer();
        }

        char *endptr;
        long value = strtol(buffer, &endptr, 10);

        // Checks if the string was empty or started with letters (no numbers
        // were found at all)
        if (endptr == buffer) {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        while (*endptr == ' ' || *endptr == '\t') {
            endptr++;
        }

        // Checks if there is "trailing garbage" (letters or symbols) after the
        // number
        if (*endptr != '\n' && *endptr != '\0') {
            printf("Invalid input. Please enter only a number.\n");
            continue;
        }

        // Checks if the successfully parsed number fits within your specific
        // boundaries
        if (value < minimum_number || value > maximum_number) {
            printf("Please enter a number between %d and %d.\n", minimum_number,
                   maximum_number);
            continue;
        }

        return (int)value;
    }
}

