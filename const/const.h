#ifndef CONST_H
#define CONST_H

#define ERRMEM_MSG "\n\nMemory error, abort program\n\n"

typedef enum {
	ERR_OK = 0,
	ERR_MEM = 1,
	ERR_ARGS = 2,
	ERR_IO = 3,
	ERR_SKIP = 4,
} ErrorCode;

#endif

