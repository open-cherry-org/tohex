#ifndef UTILS_H
#define UTILS_H

#include <xlang.h>

lett* allocate_string(S_t length);
void sanitize_input(lett* input);
funct validate_filename(setup lett* filename);

#endif