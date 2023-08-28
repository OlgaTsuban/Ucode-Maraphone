#include <string.h>
#include <unistd.h>

void mx_write_knock_knock(void) {
    write(1,"Follow the white rabbit.\nKnock, knock, Neo.", strlen("\nFollow the white rabbit.\nKnock, knock, Neo."));
}

