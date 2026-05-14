#ifndef HASH_H
#define HASH_H

#include <stddef.h>

#define SHA256_HEX_SIZE 65 // SHA-256 output is: 32 bytes But hex representation becomes: 64 characters Because: 1 byte = 2 hex characters so the output must be 65

int sha256_hex(
    const unsigned char* data,
    size_t data_len,
    char* output,
    size_t output_size
);

#endif
