#include <stdio.h>
#include <string.h>

#include "password.h"
#include "input.h"

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
