#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "storage.h"

/**
 * @brief Saves the cryptographic salt and hash to the storage file.
 *
 * This function opens the "dataStorage/hashes.txt" file in write mode, 
 * overwriting any existing data to ensure only one active record exists. 
 * It appends a newline character to each entry.
 *
 * @note File structure output:
 *       - Line 1: Hex-encoded salt
 *       - Line 2: Password hash with salt
 *
 * @param[in] salt_hex  Pointer to the null-terminated, hex-encoded salt string.
 * @param[in] hash      Pointer to the null-terminated password hash string.
 *
 * @return int Status code of the operation.
 * @retval 0  Success: Data was successfully written to the file.
 * @retval 1  Failure: File could not be opened for writing.
 */
int save_hash(const char* salt_hex, const char* hash) {
    FILE* file = fopen("dataStorage/hashes.txt", "w"); // for now I use 'w' becasue I want to have one salt and hash

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(file, "%s\n%s\n", salt_hex, hash);
    fclose(file);
    printf("Hash saved.\n");
    return 0;
}

/**
 * @brief Loads the stored cryptographic salt and hash from the storage file.
 *
 * This function opens the "dataStorage/hashes.txt" file and extracts the 
 * data line by line. It automatically strips trailing newline characters 
 * from the outputs.
 *
 * @note File structure assumptions:
 *       - Line 1: Hex-encoded salt
 *       - Line 2: Password hash with salt
 *
 * @param[out] salt_hex   Pointer to the buffer where the salt string will be stored.
 * @param[in]  salt_size  Maximum capacity of the salt_hex buffer (including null terminator).
 * @param[out] hash       Pointer to the buffer where the hash string will be stored.
 * @param[in]  hash_size  Maximum capacity of the hash buffer (including null terminator).
 *
 * @return int Status code of the operation.
 * @retval 0  Success: Both salt and hash were read and processed cleanly.
 * @retval 1  Failure: File could not be opened, or reading failed due to EOF/corruption.
 */
int load_hash(char* salt_hex, int salt_size, char* hash, int hash_size) {
    FILE* file = fopen("dataStorage/hashes.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line_buf[256];  // generous temp buffer to always capture the full line + \n

    if (fgets(line_buf, sizeof(line_buf), file) == NULL) {
        fclose(file); 
        return 1; 
    }

    line_buf[strcspn(line_buf, "\n")] = '\0';
    strncpy(salt_hex, line_buf, salt_size - 1);
    salt_hex[salt_size - 1] = '\0';

    if (fgets(line_buf, sizeof(line_buf), file) == NULL) {
        fclose(file); 
        return 1; 
    }

    line_buf[strcspn(line_buf, "\n")] = '\0';
    strncpy(hash, line_buf, hash_size - 1);
    hash[hash_size - 1] = '\0';

    fclose(file);
    return 0;
}
