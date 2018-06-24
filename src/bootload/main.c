#include "defines.h"
#include "serial.h"
#include "lib.h"

int main(void)
{
    static unsigned char str[13] = "Hello World!\n";
    serial_init(SERIAL_DEFAULT_DEVICE);

    puts(str);

    while(1)
        ;
    return 0;
}
