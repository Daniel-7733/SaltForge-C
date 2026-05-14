#include <stdio.h>
#include <openssl/evp.h>

#include "hash.h"

int sha256_hex(const unsigned char* data, size_t data_len, char* output, size_t output_size) {
    EVP_MD_CTX* mdctx = NULL;
    const EVP_MD* md = NULL;
    unsigned char md_value[EVP_MAX_MD_SIZE];
    unsigned int md_len = 0;

    if (output_size < SHA256_HEX_SIZE) {
        return 0;
    }

    // 1. Create a workspace context for OpenSSL
    mdctx = EVP_MD_CTX_new();
    if (mdctx == NULL) {
        return 0;
    }

    // 2. Select the SHA-256 algorithm
    md = EVP_sha256();

    // 3. Initialize the context with SHA-256
    if (EVP_DigestInit_ex(mdctx, md, NULL) != 1) {
        EVP_MD_CTX_free(mdctx);
        return 0;
    }

    // 4. Feed the input text into the hashing engine
    if (EVP_DigestUpdate(mdctx, data, data_len) != 1) {
        EVP_MD_CTX_free(mdctx);
        return 0;
    }

    // 5. Finalize the process and save raw bytes to md_value
    if (EVP_DigestFinal_ex(mdctx, md_value, &md_len) != 1) {
        EVP_MD_CTX_free(mdctx);
        return 0;
    }

    // 6. Free up the OpenSSL memory context
    EVP_MD_CTX_free(mdctx);

    // 7. Convert raw bytes into a readable Hexadecimal string
    for (unsigned int i = 0; i < md_len; i++) {
        snprintf(output + (i * 2), output_size - (i * 2), "%02x", md_value[i]);
    }

    output[md_len * 2] = '\0';

    return 1;
}
