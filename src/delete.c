#include <stdio.h>
#include <string.h>
#include "delete.h"
#include "utils.h"
#include "common.h"

/*
 * Deletes a user by username.
 * It clears:
 *   - username
 *   - password
 *   - totalBalance
 *   - savings
 * and marks user inactive.
 */
int delete_user(User users[], int *userCount) {
    char target[USERNAME_LEN];
    int i;

    printf("\n----------------------\n");
    printf("Delete User Account\n\n");

    read_string("Enter username to delete: ", target, USERNAME_LEN);

    for (i = 0; i < *userCount; ++i) {
        if (users[i].isActive && strcmp(users[i].username, target) == 0) {

            users[i].isActive = 0;
            users[i].password = 0;
            users[i].totalBalance = 0.0f;
            users[i].savings = 0.0f;
            users[i].username[0] = '\0';

            printf("Account '%s' deleted successfully.\n", target);
            return 1;
        }
    }

    printf("No such user found.\n");
    return 0;
}
