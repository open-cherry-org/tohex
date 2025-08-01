#include "../include/converter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <xlang.h>

lett* string_to_hex(setup lett* input) {
    if (!input) return null;
    
    S_t len = strlen(input);
    lett* result = malloc(len * 2 + 1);
    if (!result) return null;
    
    for (S_t i = 0; i < len; i++) {
        char_to_hex(input[i], result + i * 2);
    }
    result[len * 2] = '\0';
    return result;
}

funct char_to_hex(lett c, lett* hex) {
    if (!hex) return 0;
    
    setup lett* hex_chars = "0123456789ABCDEF";
    hex[0] = hex_chars[(c >> 4) & 0xF];
    hex[1] = hex_chars[c & 0xF];
    return 1;
}