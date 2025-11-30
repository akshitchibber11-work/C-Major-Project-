#ifndef COMMON_H
#define COMMON_H

#define MAX_USERS 100
#define USERNAME_LEN 32

typedef struct {
    char username[USERNAME_LEN];
    int password;        /* numeric password */
    float totalBalance;  /* Total Balance */
    float savings;       /* Savings */
    int isActive;        /* 1 = record used, 0 = empty */
} User;

#endif /* COMMON_H */
