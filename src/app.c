#include <stdio.h> 

#include "input.h"
#include "app.h"

int run_app(void) {
    printf("Welcome to SaltForge-C\n");
    printf("1. Hash password\n");
    printf("2. Verify password\n");
    printf("3. Exit\n");
    
    int user_choice = integer_convertor(sizeof(int), 1, 3);

    // This need to rewrite & it is not the complete Idea.
    switch (user_choice) {
        case 1:
            get_password_from_user();
            printf("password is hash now.\n");
            break;
        case 2:
            printf("verify password\n");
            break;
        case 3:
            printf("Exit!\n");
            break;
        default:
            printf("Invalid number! (Choose between 1-3)\n");
            break;
    }

    return 0;
}

