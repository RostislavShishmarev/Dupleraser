#ifndef CONST_H
#define CONST_H

#define LIST_BUFSIZ 10

#define CHAR_NEWLINE '\n'
#define CHAR_END '\0'
#define CHAR_SPACE ' '

#define ERRMEM_MSG "\n\nMemory error, abort program\n\n"

#define SEPS " \t"

typedef enum {
	ERR_OK = 0,
	ERR_MEM = 1,
	ERR_ARGS = 2,
	ERR_IO = 3,
	ERR_SKIP = 4,
} ErrorCode;

#endif

