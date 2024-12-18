typedef struct Item {
	char letter;
	struct Item* next;
} Item;

typedef struct List {
	Item* head;
} List;

