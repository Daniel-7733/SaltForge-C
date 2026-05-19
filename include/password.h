#ifndef PASSWORD_H 
#define PASSWORD_H 

#define MAXIMUM_PASSWORD 128 

int verify_password(void);
int validate_password(int password_size, int password_limit); 
void ask_password(char* user_password, int password_limit); 
void ask_confirm_password(char* confirm_password, int password_limit); 
int password_match(const char* password, const char* confirm_password); 
int get_password_from_user(char* password);
int process_the_password(char* password);

#endif
