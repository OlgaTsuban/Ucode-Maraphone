all: obj MINILIBMX create_lib

CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic


obj:
	mkdir obj
	
MINILIBMX: object.o

object.o:
	$(CC) $(CFLAGS) -c src/*.c inc/*.h

create_lib:
	ar rcs minilibmx.a *.o
	ranlib minilibmx.a
	mv *.o obj

uninstall:
	rm -rf obj
	rm minilibmx.a

clean:
	rm -rf obj

reinstall:
	make uninstall
	make all

