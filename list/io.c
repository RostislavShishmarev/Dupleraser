#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../const/const.h"
#include "list.h"

ErrorCode input_lists_array(List** lists_array, size_t* size) {
	
	// Init variables
	
	List buffer[LIST_BUFSIZ] = {0};
	size_t n_elements_in_buffer = 0;
	
	List list = init_list();

	do {
		// Get char from input stream

		char letter = getchar();
		int res = (int)letter;

		if (res == EOF || n_elements_in_buffer == LIST_BUFSIZ) {
			*lists_array = (List*)realloc(*lists_array, (*size + n_elements_in_buffer) * sizeof(List));

			memcpy(*lists_array + *size, buffer, n_elements_in_buffer * sizeof(List));
			
			*size += n_elements_in_buffer;

			n_elements_in_buffer = 0;

			if (res == EOF) {
				break;
			}
		}

		// Make new list if newline

		if (letter == NEWLINE_CHAR) {
			if (list.head != NULL) {
				buffer[n_elements_in_buffer] = list;
				n_elements_in_buffer += 1;
			}

			list = init_list();

			continue;
		}

		// Add item to list

		ErrorCode code = add_item(&list, letter);

		if (code != ERR_OK) {
			fprintf(stderr, "Error during add element to list\n");
			free_lists_array(*lists_array, *size);
			return code;
		}

	} while (1);
	
	return ERR_OK;
}


void output_lists_array(const List* lists_array, size_t size) {

	for (size_t i = 0; i < size; i++) {
		print_list(lists_array[i]);
	}

	return;
}

