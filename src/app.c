#include <stdio.h> 
#include <stdbool.h>

#include "saltgenerator.h"
#include "password.h"
#include "input.h"
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
                printf("Hash password\n");
                char password[MAXIMUM_PASSWORD];
                unsigned char salt[SALT_SIZE];
                // salt is 16 bytes then the hex will be 16 bytes x 2 hex (chars = 32 chars) + 1 (for '\0')
                char salt_hex[(SALT_SIZE * 2) + 1]; 

                if (get_password_from_user(password) != 0) break;
                if (generate_salt(salt, SALT_SIZE) != 0) break;

                salt_to_hex(salt, SALT_SIZE, salt_hex);

                printf("Password: %s\n", password);
                printf("Salt hex: %s\n", salt_hex);
                printf("Password+Salt hex is: %s%s\n", password, salt_hex);
                //print_salt_hex(salt, SALT_SIZE);
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

