#include <stdio.h>
#include "finance.h"
#include "utils.h"
#include "common.h"

/*
 * Displays the balance screen for the logged-in user.
 * Shows username, current balance, and savings.
 * Offers options to input income, expense, or savings percentage.
 */
static void display_balance_screen(const User *user) {
    printf("\n----------------------\n");
    printf("%s - Balance Screen\n\n", user->username);
    printf("Username      : %s\n", user->username);
    printf("Total Balance : %.2f\n", user->totalBalance);
    printf("Savings       : %.2f\n\n", user->savings);
    printf("1) Input Income\n");
    printf("2) Input Expense\n");
    printf("3) Input %% for saving\n");
    printf("0) Logout / Back\n");
    printf("----------------------\n");
}

/*
 * Runs the financial dashboard for a logged-in user.
 * Each option updates the user's balance in real time.
 */
void run_finance_session(User *user) {
    int choice;

    while (1) {
        display_balance_screen(user);
        choice = read_int("Enter your choice: ");

        switch (choice) {
            case 1: {
                /* Income: Total Balance increases by entered amount */
                float income = read_float("Enter Income amount: ");
                if (income < 0) {
                    printf("Income cannot be negative.\n");
                } else {
                    user->totalBalance += income;
                    printf("Income added successfully.\n");
                }
                wait_for_enter();
                break;
            }

            case 2: {
                /* Expense: Total Balance decreases by entered amount */
                float expense = read_float("Enter Expense amount: ");
                if (expense < 0) {
                    printf("Expense cannot be negative.\n");
                } else if (expense > user->totalBalance) {
                    printf("Transaction failed. Not enough balance.\n");
                } else {
                    user->totalBalance -= expense;
                    printf("Expense recorded successfully.\n");
                }
                wait_for_enter();
                break;
            }

            case 3: {
                /*
                 * Saving percent:
                 * Move a percentage of the current Total Balance into Savings.
                 * Example:
                 *   Balance = 2000, percent = 10
                 *   savedAmount = 200
                 *   New Balance = 1800
                 *   Savings = oldSavings + 200
                 */
                float percent = read_float("Enter saving percent (e.g. 10 for 10%%): ");
                if (percent < 0 || percent > 100) {
                    printf("Percent must be between 0 and 100.\n");
                } else {
                    float savedAmount = (percent / 100.0f) * user->totalBalance;
                    user->totalBalance -= savedAmount;   /* money moved out of main balance */
                    user->savings     += savedAmount;   /* and into savings */
                    printf("Savings updated. %.2f moved to savings.\n", savedAmount);
                }
                wait_for_enter();
                break;
            }

            case 0:
                /* Go back to Home Screen */
                return;

            default:
                printf("Invalid option. Please select 0, 1, 2 or 3.\n");
                wait_for_enter();
                break;
        }
    }
}
