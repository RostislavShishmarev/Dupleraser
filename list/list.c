#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../const/const.h"
#include "list.h"

List init_list() {
	List list = {NULL, NULL};
	return list;
}

ErrorCode add_item(List* list, char letter) {
	Item* item = (Item*)malloc(sizeof(Item));

	if (item == NULL) {
		return ERR_MEM;
	}

	(*item).letter = letter;
	(*item).next = NULL;

	if ((*list).head == NULL) {
		(*list).head = item;
	} else {
		(*((*list).tail)).next = item;
	}
	(*list).tail = item;
	
	return ERR_OK;
}

void print_list(const List list) {
	Item *current = list.head;
	
	printf("\"");
	while (current != NULL) {
		printf("%c", (*current).letter);
		current = (*current).next;
	}
	printf("\"\n");

	return;
}

void free_list(const List list) {
	Item *current = list.head;
	
	while (current != NULL) {
		Item *next = (*current).next;
		free(current);
		current = next;
	}
	
	return;
}

void free_lists_array(List* lists_array, size_t size) {
	for (size_t i = 0; i < size; i++) {
		free_list(lists_array[i]);
	}

	free(lists_array);

	return;
}

ErrorCode erase_repeated(List* list) {
	char letter = CHAR_END;
	char last_letter = CHAR_END;
	
	int is_space = 0;
	int last_is_space = 0;

	char string[2] = {CHAR_END, CHAR_END};
	
	Item zero_item = {CHAR_END, (*list).head};

	Item *prev = &zero_item;
	Item *current = (*list).head;
	Item *next = NULL;

	while (current != NULL) {
		letter = (*current).letter;
		next = (*current).next;

		string[0] = letter;

		is_space = strspn(string, SEPS);

		if (is_space == 0) {
			if (last_is_space != 0 && (*prev).letter != CHAR_END) {
				// Current not space, last is space

				Item *space = malloc(sizeof(Item));

				if (space == NULL) {
					fprintf(stderr, ERRMEM_MSG);
					return ERR_MEM;
				}

				(*space).letter = CHAR_SPACE;
				(*space).next = current;

				(*prev).next = space;

				prev = current;

			} else {
				if (letter == last_letter) {
					// Current not space, last not space, c == l
					
					(*prev).next = next;
					free(current);
				} else {
					// Current not space, last not space, c != l

					prev = current;
				}
			}

		} else {
			// Current is space

			(*prev).next = next;
			free(current);
		}

		current = next;
		last_letter = letter;
		last_is_space = is_space;
	}

	(*list).head = zero_item.next;
	(*list).tail = prev;

	return ERR_OK;
}

