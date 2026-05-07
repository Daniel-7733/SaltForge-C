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
 * This Function won't let the password be longer than the limit or samller then
 * 1 Use strlen() for password_size
 * */
int validate_password(int password_size, int password_limit) {
    if (password_size >= password_limit || password_size <= 0) {
        printf("Password can't be 0 or more than %d character", password_limit - 1);
        return 1;
    }
    return 0;
}

/*
 * Function check if the text is empty & return '/0'
 * */
int is_empty_input(const char *text) { 
    return text[0] == '\0'; 
}

/*
 * Ask user password & return it
 * */
void ask_password(char *user_password, int password_limit) {
    printf("Enter password: ");

    if (fgets(user_password, password_limit, stdin) == NULL) {
        user_password[0] = '\0';
        return;
    }
    remove_line(user_password);
}

/*
 * Ask the user to write the confirm password
 * */
void ask_confirm_password(char *confirm_password, int password_limit) {
    printf("Confirm password: ");

    if (fgets(confirm_password, password_limit, stdin) == NULL) {
        confirm_password[0] = '\0';
        return;
    }
    remove_line(confirm_password);
}

/*
 * Try to match the user password with the confirm one
 * */
int password_match(const char *password, const char *confirm_password) {
    return strcmp(password, confirm_password) == 0;
}

/*
 * A place that user give the password. Function will remove \n & clean the
 * buffer. In Addition, it will control the size of password.
 * */
int get_password_from_user(void) {
    char password[MAXIMUM_PASSWORD];
    char confirm_password[MAXIMUM_PASSWORD];

    ask_password(password, MAXIMUM_PASSWORD);

    if (is_empty_input(password)) {
        printf("Password can't be empty.\n");
        return 1;
    }

    ask_confirm_password(confirm_password, MAXIMUM_PASSWORD);

    if (!password_match(password, confirm_password)) {
        printf("Password do not match.\n");
        return 1;
    }

    printf("Password accepted.\n");

    return 0;
}

int integer_convertor(int buffer_limit, int minimum_number, int maximum_number) {
    char buffer[buffer_limit];
    printf("Enter choice: ");

    while (true) {

        // Checks if reading from the keyboard failed or if the user signaled
        // EOF (Ctrl+D)
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Input error.\n");
            continue;
        }

        char *endptr;
        long value = strtol(buffer, &endptr, 10);

        // Checks if the string was empty or started with letters (no numbers
        // were found at all)
        if (endptr == buffer) {
            printf("Invalid input. Please enter a number.\n");
            clear_buffer();
            continue;
        }

        while (*endptr == ' ' || *endptr == '\t') {
            endptr++;
        }

        // Checks if there is "trailing garbage" (letters or symbols) after the
        // number
        if (*endptr != '\n' && *endptr != '\0') {
            printf("Invalid input. Please enter only a number.\n");
            clear_buffer();
            continue;
        }

        // Checks if the successfully parsed number fits within your specific
        // boundaries
        if (value < minimum_number || value > maximum_number) {
            printf("Please enter a number between %d and %d.\n", minimum_number,
                   maximum_number);
            clear_buffer();
            continue;
        }

        return (int)value;
    }
}
