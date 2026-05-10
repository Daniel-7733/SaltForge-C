#ifndef INPUT_H
#define INPUT_H

// choose one for number input 32 bytes or 64 bytes 
#define BUFFER_LIMIT 64 

void clear_buffer(void);
void remove_line(char* user_input);
int is_empty_input(const char* text);
int integer_convertor(int minimum_number, int maximum_number);

#endif
