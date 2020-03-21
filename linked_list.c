#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct number {
	int value;
	struct number *next;
} number;

number* add(int val) {
	number *n = malloc(sizeof(number));
	n->value = val;
	n->next = NULL;

	return n;
}

void show_list(number *start) {
	number *n = start;
	do {
		if (n == start)
			printf("[");
		if (n->next != NULL)
			printf(" %d,", n->value);
		else
			printf(" %d ", n->value);
		
		n = n->next;

		if (n == NULL)
			printf("]\n");
	} while(n != NULL);
}

int length(number *start) {
	number *n = start;
	int count = 0;
	while(n != NULL) {
		count++;
		n = n->next;
	}
}

void clear_all(number *start) {
	number *n = start;
	number *next = NULL;

	while(n != NULL) {
		next = n->next;
		printf("cleared %d on heap\n", n->value);
		free(n);
		n = next;		
		if (n == NULL) 
			printf("removed everything\n");
	}
}

// you need to give the first item of the list as an argument
void pop(number *start) {
	number *n = start;
	number *next = NULL;
	while (n != NULL) {
		next = n->next;
		if (next->next == NULL) {
			free(next);
			n->next = NULL;
			break;
		}
		n = next;
	}
}

int main() {
	int user_input;
	char user_str[10];

	number *p_num = NULL;
	number *next = NULL;
	number *start = NULL;
	
	while (1){
		printf("Enter a number:");
		scanf("%9s", user_str);
		if (!strcmp(user_str, "quit")) 
			break;
		user_input = atoi(user_str);

		next = add(user_input);
		if (start == NULL)
			start = next;
		if (p_num != NULL)
			p_num->next = next;		
		p_num = next;
		getchar();
		show_list(start);
	}
	pop(start);
	show_list(start);
	clear_all(start);
	return 0;
}
