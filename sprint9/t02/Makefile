all: obj MINILIBMX create

FLAGS = -Wall -Wextra -Werror -Wpedantic

obj:
	mkdir obj
MINILIBMX: mx_printchar.o mx_printint.o mx_printstr.o mx_strcpy.o mx_strlen.o mx_strcmp.o mx_isdigit.o mx_isspace.o mx_atoi.o
	


mx_printchar.o: ./src/mx_printchar.c
	clang $(FLAGS) -c ./src/mx_printchar.c ./inc/header.h

mx_atoi.o: ./src/mx_atoi.c
	clang $(FLAGS) -c ./src/mx_atoi.c

mx_isdigit.o: ./src/mx_isdigit.c
	clang $(FLAGS) -c ./src/mx_isdigit.c

mx_isspace.o: ./src/mx_isspace.c
	clang $(FLAGS) -c ./src/mx_isspace.c

mx_printint.o: ./src/mx_printint.c
	clang $(FLAGS) -c ./src/mx_printint.c
	
mx_printstr.o: ./src/mx_printstr.c
	clang $(FLAGS) -c ./src/mx_printstr.c

mx_strcmp.o: ./src/mx_strcmp.c
	clang $(FLAGS) -c ./src/mx_strcmp.c
	
mx_strcpy.o: ./src/mx_strcpy.c
	clang $(FLAGS) -c ./src/mx_strcpy.c

mx_strlen.o: ./src/mx_strlen.c
	clang $(FLAGS) -c ./src/mx_strlen.c


create:
	ar rcs minilibmx.a mx_printchar.o mx_printint.o mx_printstr.o mx_strcpy.o mx_strlen.o 		mx_strcmp.o mx_isdigit.o mx_isspace.o mx_atoi.o
	ranlib minilibmx.a
	mv mx_printchar.o obj
	mv mx_printint.o obj
	mv mx_printstr.o obj
	mv mx_strcpy.o obj
	mv mx_strlen.o obj
	mv mx_strcmp.o obj
	mv mx_isdigit.o obj
	mv mx_isspace.o obj
	mv mx_atoi.o obj
	
uninstall :
	rm -rf obj
	rm minilibmx.a
clean :
	rm -rf obj

reinstall:
	make clean
	make all
	

