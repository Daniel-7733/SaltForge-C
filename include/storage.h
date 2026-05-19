#ifndef STORAGE_H
#define STORAGE_H

int save_hash(const char* salt_hex, const char* hash);
int load_hash(char* salt_hex, int salt_size, char* hash, int hash_size);

#endif
