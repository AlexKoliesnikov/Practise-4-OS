#include <stdio.h>

int main() {
    extern char** environ;
    char** env = environ;

    while (*env != NULL) {
        printf("%s\n", *env);
        env++;
    }
    return 0;
}
