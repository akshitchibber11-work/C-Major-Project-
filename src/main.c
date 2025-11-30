#include <stdio.h>
#include "auth.h"
#include "finance.h"
#include "delete.h"
#include "utils.h"
#include "common.h"

int main(void) {
    User users[MAX_USERS] = {0};   /* User database */
    int userCount = 0;             /* Total active users */
    int choice;

    while (1) {
        printf("\n----------------------\n");
        printf("Student Finance System\n\n");
        printf("1) Login\n");
        printf("2) Sign up\n");
        printf("3) Delete Account\n");
        printf("0) Exit\n");
        printf("----------------------\n");

        choice = read_int("Choose: ");

        switch (choice) {
            case 1: {
                int index = login(users, userCount);
                if (index != -1) {
                    run_finance_session(&users[index]);
                }
                wait_for_enter();
                break;
            }

            case 2:
                signup(users, &userCount);
                wait_for_enter();
                break;

            case 3:
                delete_user(users, &userCount);
                wait_for_enter();
                break;

            case 0:
                printf("Exiting program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please choose 0, 1, 2 or 3.\n");
                wait_for_enter();
                break;
        }
    }

    return 0;
}
