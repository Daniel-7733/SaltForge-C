#include <stdio.h> 
#include <stdbool.h>

#include "saltgenerator.h"
#include "password.h"
#include "input.h"
#include "hash.h"
#include "app.h"


int run_app(void) {
    menu();
    return 0;
}

int menu(void) {

    while (true) {

        printf("Welcome to SaltForge-C\n");
        printf("1. Hash password\n");
        printf("2. Verify password\n");
        printf("3. Exit\n");
        
        int user_choice = integer_convertor(1, 3);

        switch (user_choice) {
            case 1: {
                char password[MAXIMUM_PASSWORD];
                printf("Hash password\n");
                process_the_password(password);
                break;
                    }
            case 2:
                printf("verify password\n");
                break;
            case 3:
                printf("Good Bye.\n");
                return 1;
            default:
                printf("Invalid number! (Choose between 1-3)\n");
                break;
        }
    }
    return 0;
}

