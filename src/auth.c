#include <stdio.h>
#include <string.h>
#include "auth.h"
#include "utils.h"
#include "common.h"

/*
 * Searches for a username in our user list.
 * Returns the index if found, -1 otherwise.
 */
static int find_user_by_username(User users[], int userCount, const char *username) {
    for (int i = 0; i < userCount; i++) {
        if (users[i].isActive && strcmp(users[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

/*
 * Creates a new user account.
 * Validates password match and username uniqueness.
 */
int signup(User users[], int *userCount) {
    if (*userCount >= MAX_USERS) {
        printf("No more accounts can be created. Limit reached.\n");
        return -1;
    }

    char username[USERNAME_LEN];
    int password, confirmPassword;

    printf("\n----------------------\n");
    printf("Student Finance System - Signup\n\n");

    read_string("Choose a Username: ", username, USERNAME_LEN);
    password = read_int("Create a Password (numbers only): ");
    confirmPassword = read_int("Confirm Password: ");

    if (password != confirmPassword) {
        printf("Passwords do not match. Please try again.\n");
        return -1;
    }

    if (find_user_by_username(users, *userCount, username) != -1) {
        printf("This username is already taken. Choose another.\n");
        return -1;
    }

    /* Create a new user entry */
    User *u = &users[*userCount];
    strncpy(u->username, username, USERNAME_LEN - 1);
    u->username[USERNAME_LEN - 1] = '\0';
    u->password = password;
    u->totalBalance = 0.0f;
    u->savings = 0.0f;
    u->isActive = 1;

    (*userCount)++;

    printf("Signup Successful! You can now login.\n");
    return *userCount - 1;
}

/*
 * Authenticates a user by checking username and password.
 * Returns the user index if credentials are correct.
 */
int login(User users[], int userCount) {
    char username[USERNAME_LEN];
    int password;

    printf("\n----------------------\n");
    printf("Student Finance System - Login\n\n");

    read_string("Enter Username: ", username, USERNAME_LEN);
    password = read_int("Enter Password: ");

    int index = find_user_by_username(users, userCount, username);

    if (index != -1 && users[index].password == password) {
        printf("%s! Login Successful\n", users[index].username);
        return index;
    }

    printf("Incorrect username or password. Please try again.\n");
    return -1;
}
