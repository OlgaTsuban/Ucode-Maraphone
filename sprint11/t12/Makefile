name := playlist

all: $(name)

${name}:
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic src/*.c -o $(name)

clean:
	rm -f $(name)

uninstall:
	rm -f $(name)

reinstall:
	make uninstall
	make
	
