# get_next_line.h

#### Whether for a file or standard input entry, you will always need to read content line by line. Get_Next_Line is a function that reads a file line by line.

### Running the program (From terminal)

1. git clone --recursive https://github.com/mnchabeleng/gnl.git
2. cd to project folder
3. make -C libft/ fclean && make -C libft/
   gcc -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
   gcc -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
   gcc -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft

### For testing

- #### [42FileChecker](https://github.com/jgigault/42FileChecker)
