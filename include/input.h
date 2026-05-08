#ifndef INPUT_H
#define INPUT_H

#define MAXIMUM_PASSWORD 128
#define BUFFER_LIMIT 64 // choose one for number input 32 bytes or 64 bytes 

void clear_buffer(void);
void remove_line(char* user_input);
int validate_password(int password_size, int password_limit);
int is_empty_input(const char* text);
void ask_password(char* user_password, int password_limit);
void ask_confirm_password(char* confirm_password, int password_limit); 
int password_match(const char* password, const char* confirm_password); 
int get_password_from_user(void);
int integer_convertor(int minimum_number, int maximum_number);

#endif
