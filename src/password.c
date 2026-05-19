#include <stdio.h>
#include <string.h>

#include "saltgenerator.h"
#include "password.h"
#include "storage.h"
#include "input.h"
#include "hash.h"



/**
 * @brief Performs password verification by comparing user input against stored credentials.
 *
 * This function handles the entire authentication workflow: it loads the stored salt and hash,
 * prompts the user for their password, concatenates the input with the salt, and hashes the result. 
 * Finally, it compares the freshly generated hash with the stored hash to verify the password.
 *
 * @return int Status code of the operational workflow.
 * @retval 0  Success: The verification process completed (regardless of whether the password matched).
 * @retval 1  Failure: Process aborted due to file read errors, user input failure, or hashing failure.
 */
int verify_password(void) {
    char input_password[MAXIMUM_PASSWORD];
    char stored_salt_hex[(SALT_SIZE * 2) + 1];
    char stored_hash[SHA256_HEX_SIZE];

    char password_with_salt[MAXIMUM_PASSWORD + (SALT_SIZE * 2) + 1];
    char new_hash[SHA256_HEX_SIZE];

    if (load_hash(
            stored_salt_hex,
            sizeof(stored_salt_hex),
            stored_hash,
            sizeof(stored_hash)
        ) != 0) {
        return 1;
    }

    if (get_password_from_user(input_password) != 0) {
        return 1;
    }

    snprintf(
        password_with_salt,
        sizeof(password_with_salt),
        "%s%s",
        input_password,
        stored_salt_hex
    );

    if (!sha256_hex(
            (const unsigned char*)password_with_salt,
            strlen(password_with_salt),
            new_hash,
            sizeof(new_hash)
        )) {
        return 1;
    }

    if (strcmp(new_hash, stored_hash) == 0) {
        printf("Password correct.\n");
    } else {
        printf("Password incorrect.\n");
    }

    return 0;
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
int get_password_from_user(char* password) {
    // char password[MAXIMUM_PASSWORD];
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

/* 
 * "This is multi purpose function; It use all function to get one result"
 * This function will process the password.
 * It hash the password and make a salt, then combine the hash with salt. 
 * At the end it save it
 * */

int process_the_password(char* password) {
    unsigned char salt[SALT_SIZE]; 
    char salt_hex[(SALT_SIZE * 2) + 1];  // salt is 16 bytes then the hex will be 16 bytes x 2 hex (chars = 32 chars) + 1 (for '\0')
    char password_with_salt[(MAXIMUM_PASSWORD + (SALT_SIZE * 2) + 1)];
    char hash[SHA256_HEX_SIZE];

    if (get_password_from_user(password) != 0) return 1;
    if (generate_salt(salt, SALT_SIZE) != 0) return 1;

    salt_to_hex(salt, SALT_SIZE, salt_hex);

    snprintf(
            password_with_salt,
            sizeof(password_with_salt),
            "%s%s",
            password,
            salt_hex
            );


    if (!sha256_hex(
                (const unsigned char*)password,
                strlen(password),
                hash,
                sizeof(hash)
                )) {
        printf("Hashing failed.\n");
        return 1;
    }

    printf("Hash: %s\n", hash);

    save_hash(salt_hex, hash);

    return 0;
}

