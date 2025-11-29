#ifndef UTILS_H
#define UTILS_H

int read_int(const char *prompt);
float read_float(const char *prompt);
void read_string(const char *prompt, char *buffer, int length);
void clear_input_buffer(void);
void wait_for_enter(void);

#endif /* UTILS_H */
