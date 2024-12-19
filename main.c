#include <stdio.h>
#include <stdlib.h>

#include "const/const.h"
#include "list/list.h"
#include "list/io.h"

int main() {
	// Init variables
	
	ErrorCode code;
	
	List* lists_array = NULL;
	size_t size = 0;

	// Input data 
	
	printf("Type strings:\n\n");

	code = input_lists_array(&lists_array, &size);

	if (code != ERR_OK) {
		return 1;
	}

	// Output data before process

	printf("\n\nInput strings:\n\n");
	
	output_lists_array(lists_array, size);

	// Process data
	

	// Output data after process

	printf("\n\nResult strings:\n\n");
	
	output_lists_array(lists_array, size);
	
	// Free data

	free_lists_array(lists_array, size);

	return 0;
}

