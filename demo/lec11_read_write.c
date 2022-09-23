#include <unistd.h>
#include <string.h>

void main() {
    char input[100];
    memset(input, 0, 100);

    read (0, input, 100);
    write(1, input, 100);
}
