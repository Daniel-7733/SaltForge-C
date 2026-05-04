#include <stdio.h>
#include <stdlib.h>

#include "input.h"
#include "app.h"

int run_app(void) {
    printf("Welcome to SaltForge-C\n");
    printf("1. Hash password\n");
    printf("2. Verify password\n");
    printf("3. Exit\n");

    char* password = malloc(MAXIMUM_PASSWORD);
    if (password == NULL) return 1;
    printf("Memory has reserved %d bytes\n", MAXIMUM_PASSWORD);

    ask_password(password, MAXIMUM_PASSWORD);
    remove_line(password);
    printf("Your password is \" %s\"\n", password);

    free(password);
    printf("Memory has been freed.\n");

    return 0;
}

