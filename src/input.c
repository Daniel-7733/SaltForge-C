#include <stdio.h>
#include <string.h>

char* ask_password(char* user_password, int password_limit) {

    printf("Add your password: ");
    fgets(user_password, password_limit, stdin); // This one has '\n' and it needs to be remove.
    return user_password;
}

// Next Function -> remove_line
void remove_line(char* user_input) {
    size_t len = strlen(user_input);

    if (len > 0 && user_input[len - 1] == '\n') {
        user_input[len - 1] = '\0';
    }
}



