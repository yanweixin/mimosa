#include <stdio.h>
#include "main.h"

const char *say_hello() {
#ifdef IS_WINDOWS
    return "Hello from Windows!";
#elif IS_LINUX
    return "Hello from Linux!";
#elif IS_MACOS
    return "Hello from macOS!";
#else
    return "Hello from an unknown system!";
#endif
}

int main(int argc, char const *argv[]) {
    printf("%s\n", say_hello());
}