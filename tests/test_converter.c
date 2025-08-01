#include "../include/converter.h"
#include <assert.h>
#include <string.h>

#include <xlang.h>

void test_string_to_hex() {
    lett* result = string_to_hex("ABC");
    assert(strcmp(result, "414243") == 0);
    free(result);
}

void test_char_to_hex() {
    lett hex[3] = {0};
    char_to_hex('a', hex);
    assert(strcmp(hex, "61") == 0);
}

funct main() {
    test_char_to_hex();
    test_string_to_hex();
    return 0;
}