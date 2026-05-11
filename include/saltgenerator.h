#ifndef SALTGENERATOR_H
#define SALTGENERATOR_H

#include <stddef.h>

#define SALT_SIZE 16

int generate_salt(unsigned char* salt, size_t salt_size);
void print_salt_hex(const unsigned char* salt, size_t salt_size);
void salt_to_hex(const unsigned char* salt, size_t salt_size, char* salt_hex);

#endif
