#include <stdio.h>

#include "storage.h"

/* 
 * Save salt and hash with salt in a file. 
 * */
int save(char* salt, char* hash_with_salt) {
    FILE* fileptr;
    fileptr = fopen("dataStorage/hashes.txt", "a"); // I use a instead of w to add hashes not to over write it again.
    
    if (fileptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(fileptr, "%s\n%s\n", salt, hash_with_salt);
    fclose(fileptr);
    printf("Hash saved!\n");
    return 0;
}

/* This function will just read data from data in dataStorage (Use "r" to read) */
int read_Data() {
    return 0;
}
