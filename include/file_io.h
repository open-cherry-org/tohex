#ifndef FILE_IO_H
#define FILE_IO_H

#include <xlang.h>
#include <stddef.h>

lett* read_file(const char* filename);
funct write_hex_to_file(const char* filename, const char* content);
S_t get_file_size(const char* filename);

#endif