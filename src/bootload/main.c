#include "defines.h"
#include "serial.h"
#include "lib.h"

int main(void)
{
    static unsigned char str[13] = "Hello World!\n";
    serial_init(SERIAL_DEFAULT_DEVICE);

    puts(str);

    putxval(0x10, 0);   puts("\n");
    putxval(0xffff, 0); puts("\n");

    while(1)
        ;
    return 0;
}
