#ifndef LIST_H
#define LIST_H

#include "../const/const.h"

typedef struct Item {
	char letter;
	struct Item* next;
} Item;

typedef struct List {
	Item* head;
	Item* tail;
} List;

List init_list();
ErrorCode add_item(List*, char);
void print_list(const List);
void free_list(const List);
void free_lists_array(List*, size_t);

#endif

