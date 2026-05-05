#include <stdio.h> 

#include "input.h"
#include "app.h"


int run_app(void) {
    printf("Welcome to SaltForge-C\n");
    printf("1. Hash password\n");
    printf("2. Verify password\n");
    printf("3. Exit\n");
    
    // Use switch(), case, defult for choices
    get_password_from_user();

    return 0;
}

