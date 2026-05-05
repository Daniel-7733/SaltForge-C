#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "input.h"
#include "app.h"


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
void remove_line(char* user_input) {
    size_t len = strlen(user_input);

    if (len > 0 && user_input[len - 1] == '\n') {
        user_input[len - 1] = '\0';
    } else {
        clear_buffer();
    }
}


/* 
 * This Function won't let the password be longer than the limit or samller then 1
 * Use strlen() for password_size
 * */
int validate_password(int password_size, int password_limit) {
    if (password_size >= password_limit || password_size <= 0) {
        printf("Password can't be 0 or more than %d character", password_limit-1);
        return 1;
    }
    return 0;
}


/* 
 * Ask user password & return it
 * */
char* ask_password(char* user_password, int password_limit) {
    printf("Enter password: ");
    fgets(user_password, password_limit, stdin); 
    remove_line(user_password);
    return user_password;
}


/*
 * A place that user give the password. Function will remove \n & clean the buffer. In Addition, it will control the size of password.
 * */
int get_password_from_user(void) {
    char password[MAXIMUM_PASSWORD];

    ask_password(password, MAXIMUM_PASSWORD);
    printf("Your password is \"%s\"\n", password);

    return 0;
}


