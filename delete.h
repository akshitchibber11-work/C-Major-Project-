#ifndef DELETE_H
#define DELETE_H

#include "common.h"

/*
 * Deletes a user by username.
 * Parameters:
 *   users      - array of User structures
 *   userCount  - pointer to total registered users
 *
 * Returns:
 *   1 -> user deleted successfully
 *   0 -> user not found
 */
int delete_user(User users[], int *userCount);

#endif
