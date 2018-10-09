//
// Created by wei on 9/29/18.
//

#include <stdio.h>

int main(int argc, char **argv) {

    char *strs[] = {"Hello", "World", "Hello", "World", "Hello", "World", "Hello", "World", "Hello", "World", "Hello",
                    "World", "Hello", "World", "Hello", "World", "Hello", "World"};
    char **strss = strs;

    for (int i = 0; i < 2; ++i) {
        printf("%s\n", strss[i]);
    }

    return 0;
}
