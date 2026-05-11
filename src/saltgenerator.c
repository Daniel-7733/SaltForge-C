#include <stdio.h>
#include <stddef.h>
#include <sys/random.h>

#include "saltgenerator.h"

/* generate the salt code */
int generate_salt(unsigned char* salt, size_t salt_size) {
    if (getrandom(salt, salt_size, 0) == -1) {
        perror("getrandom");
        return 1;
    }

    return 0;
}

/* print the salt generated */
void print_salt_hex(const unsigned char* salt, size_t salt_size) {
    for (size_t i = 0; i < salt_size; i++) {
        printf("%02x", salt[i]);
    }

    printf("\n");
}

/* The salt generated */
void salt_to_hex(const unsigned char* salt, size_t salt_size, char* salt_hex) {
    for (size_t i = 0; i < salt_size; i++) {
        sprintf(salt_hex + (i * 2), "%02x", salt[i]); 
    }

    salt_hex[salt_size * 2] = '\0';
}

