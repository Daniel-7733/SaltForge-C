#ifndef INPUT_H
#define INPUT_H

void clear_buffer(void);
void remove_line(char* user_input);
int validate_password(int password_size, int password_limit);
char* ask_password(char* user_password, int password_limit);
int get_password_from_user(void);

#endif
