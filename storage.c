#ifndef STORAGE_H
#define STORAGE_H

#include "common.h"

#define DATA_FILE "data/users.dat"

/* Loads users and returns count */
int load_users(User users[]);

/* Saves users to file */
void save_users(User users[], int userCount);

#endif
