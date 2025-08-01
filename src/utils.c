#include "../include/utils.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <xlang.h>

lett* allocate_string(S_t length) {
    return malloc(length + 1);
}

void sanitize_input(lett* input) {
    if (!input) return;
    
    for (char* p = input; *p; p++) {
        if (!isprint(*p) && !isspace(*p)) {
            *p = ' ';
        }
    }
}

funct validate_filename(setup lett* filename) {
    if (!filename) return 0;
    return strlen(filename) > 0;
}