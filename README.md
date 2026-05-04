# SaltForge-C

SaltForge-C is a beginner-friendly C project for learning how password hashing works using C, SHA-256-style hashing concepts, and salt.

This project is mainly for learning:

- multi-file C project structure
- header files and source files
- safe input handling
- password validation
- salt generation
- hashing concepts
- Makefile usage
- Git and GitHub workflow

## Project Status

Currently in early development.

### Completed

- Basic project structure
- Multi-file C setup
- `main.c` calling application logic

### In Progress

- Safe password input handling
- Menu system
- Password confirmation

### Planned

- Salt generation
- Hash function integration
- Password verification
- Save hashed passwords safely
- Improve error handling
- Add tests

## Folder Structure
```
SaltForge-C/
├── include/
│   ├── app.h
│   └── input.h
├── src/
│   ├── app.c
│   ├── input.c
│   └── main.c
├── Makefile
├── README.md
└── .gitignore
```

## Build

To compile the project:

    make

## Run

To compile and run:

    make run

## Clean

To remove the compiled program:

    make clean

## Learning Goals

This project is not only about creating a password hashing tool.

It is also about learning how real C projects are organized.

The main learning goals are:

1. Understand multi-file C programs
2. Learn safe input handling
3. Learn how passwords should not be stored directly
4. Understand salt and hashing
5. Practice clean GitHub project structure

## Notes

This project is for educational purposes.

It should not be used as a real production password manager or security system.

## Author

Daniel Kazemian
