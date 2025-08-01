#include "../include/file_io.h"
#include <stdio.h>
#include <stdlib.h>

#include <xlang.h>

lett* read_file(setup lett* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) return NULL;
    
    S_t size = get_file_size(filename);
    lett* content = malloc(size + 1);
    if (!content) {
        fclose(file);
        return NULL;
    }
    
    fread(content, 1, size, file);
    content[size] = '\0';
    fclose(file);
    return content;
}

funct write_hex_to_file(setup lett* filename, setup lett* content) {
    FILE* file = fopen(filename, "w");
    if (!file) return 0;
    
    fprintf(file, "%s", content);
    fclose(file);
    return 1;
}

size_t get_file_size(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) return 0;
    
    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    fseek(file, 0, SEEK_SET);
    fclose(file);
    return size;
}