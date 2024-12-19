#include <stdio.h>
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

