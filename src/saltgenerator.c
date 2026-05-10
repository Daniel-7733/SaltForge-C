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

/* This is just for debug; It just print the generated salt */
int display_salt(void) {
    unsigned char salt[SALT_SIZE];

    if (generate_salt(salt, SALT_SIZE) != 0) {
        return 1;
    }

    printf("Salt: ");
    print_salt_hex(salt, SALT_SIZE);

    return 0;
}
