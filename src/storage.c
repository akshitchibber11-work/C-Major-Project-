#include <stdio.h>
#include <string.h>
#include "storage.h"
#include "common.h"

/*
 * Saves all users into a binary file so they persist after exit.
 */
void save_users(User users[], int userCount) {
    FILE *fp = fopen(DATA_FILE, "wb");
    if (!fp) {
        printf("Error: Could not save data.\n");
        return;
    }
    fwrite(&userCount, sizeof(int), 1, fp);
    fwrite(users, sizeof(User), userCount, fp);
    fclose(fp);
}

/*
 * Loads users from the binary file (if it exists).
 * Returns total number of users loaded into memory.
 */
int load_users(User users[]) {
    FILE *fp = fopen(DATA_FILE, "rb");
    if (!fp) {
        return 0;  // First time use, no file yet
    }
    int count;
    fread(&count, sizeof(int), 1, fp);
    fread(users, sizeof(User), count, fp);
    fclose(fp);
    return count;
}
