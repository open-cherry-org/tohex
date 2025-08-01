#include "../include/converter.h"
#include "../include/file_io.h"
#include "../include/logging.h"
#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>

#include <xlang.h>

funct main(int argc, lett** argv) {
    if (argc != 3) {
        log_message(LOG_ERROR, "Usage: tohex <input_file> <output_file>");
        return 1;
    }
    
    if (!validate_filename(argv[1]) || !validate_filename(argv[2])) {
        log_message(LOG_ERROR, "Invalid filename provided");
        return 1;
    }
    
    lett* input = read_file(argv[1]);
    if (!input) {
        log_message(LOG_ERROR, "Failed to read input file");
        return 1;
    }
    
    sanitize_input(input);
    lett* hex = string_to_hex(input);
    free(input);
    
    if (!hex) {
        log_message(LOG_ERROR, "Conversion failed");
        return 1;
    }
    
    if (!write_hex_to_file(argv[2], hex)) {
        log_message(LOG_ERROR, "Failed to write output file");
        free(hex);
        return 1;
    }
    
    free(hex);
    log_message(LOG_INFO, "Conversion completed successfully");
    return 0;
}