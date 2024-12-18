#include <stdlib.h>

#include "../const/const.h"
#include "list.h"

List init_list() {
	List list = {NULL};
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
		Item* current_item = (*list).head;
		while ((*current_item).next != NULL) {
			current_item = (*current_item).next;
		}
		(*current_item).next = item;
	}
	return ERR_OK;
}



