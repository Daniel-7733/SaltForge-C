#include <stdio.h>
#include <stdlib.h>

#include "storage.h"

/* 
 * @brief Save salt and hash with salt in a file. 
 * Note: 
 * First line is Salt
 * Second line is Hash with salt
 *
 * @param salt: need the generated salt which is hex
 * @param hash_with_salt: accept hashed password+salt
 * @return integer -> 0 if it was successful and 1 if not
 * */
int save(char* salt, char* hash_with_salt) {
    FILE* fileptr = fopen("dataStorage/hashes.txt", "a"); // I use a instead of w to add hashes not to over write it again.
    
    if (fileptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(fileptr, "%s\n%s\n", salt, hash_with_salt);
    fclose(fileptr);
    printf("Hash saved!\n");
    return 0;
}

/* 
 * This function will read data from dataStorage and it will display all the data
 * Note: 
 * First line is Salt
 * Second line is Hash with salt
 *
 * @return integer -> 0 if it was successful and 1 if not
 * */
int read_data() {
    FILE* fileptr = fopen("dataStorage/hashes.txt", "r"); 

    if (fileptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    char buffer[256]; // I'll define the number later
    while (fgets(buffer, sizeof(buffer), fileptr) != NULL) {
        printf("%s", buffer);
    }

    fclose(fileptr);

    return 0;
}
