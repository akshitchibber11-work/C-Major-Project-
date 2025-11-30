#include <stdio.h>
#include <string.h>
#include "utils.h"

/*
 * Clears any extra characters left in the input buffer.
 * This prevents scanf() issues when switching between
 * numeric and string inputs.
 */
void clear_input_buffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        /* Just throw away the leftover characters */
    }
}

/*
 * Reads an integer from the user.
 * Keeps asking until a valid integer is entered.
 */
int read_int(const char *prompt) {
    int value;
    int result;

    while (1) {
        printf("%s", prompt);
        result = scanf("%d", &value);

        if (result == 1) {
            clear_input_buffer();  /* remove trailing input */
            return value;          /* success */
        } else {
            printf("Invalid input. Please enter a number.\n");
            clear_input_buffer();  /* clean wrong input */
        }
    }
}

/*
 * Reads a floating-point number from the user.
 * Continues prompting until a valid value is entered.
 */
float read_float(const char *prompt) {
    float value;
    int result;

    while (1) {
        printf("%s", prompt);
        result = scanf("%f", &value);

        if (result == 1) {
            clear_input_buffer();
            return value;
        } else {
            printf("Invalid amount. Please try again.\n");
            clear_input_buffer();
        }
    }
}

/*
 * Reads a string safely into a buffer.
 * Removes the newline character at the end, if present.
 */
void read_string(const char *prompt, char *buffer, int length) {
    printf("%s", prompt);

    if (fgets(buffer, length, stdin) != NULL) {
        size_t len = strlen(buffer);

        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0'; /* replace newline with null terminator */
        }
    } else {
        buffer[0] = '\0'; /* fallback if input fails */
    }
}

/*
 * Pauses the screen until the user presses ENTER.
 * Useful to let the user read messages.
 */
void wait_for_enter(void) {
    printf("Press ENTER to continue...");
    int ch = getchar();

    if (ch != '\n' && ch != EOF) {
        clear_input_buffer(); /* ensure buffer is clean */
    }
}
