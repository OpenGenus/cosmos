/*
** created by Flavian Feugueur
** flavian.feugueur@epitech.eu
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list linked_list_t;

struct linked_list {
	char *data;
	linked_list_t *next;
};

linked_list_t *add_node(linked_list_t *ll, char *data)
{
	if (!ll) {
		if (!(ll = malloc(sizeof(linked_list_t))))
			exit(-1);
		ll->data = data;
		ll->next = NULL;
	}
	else {
		linked_list_t *new_node = malloc(sizeof(linked_list_t));
		if (!new_node)
			exit(-1);
		new_node->data = data;
		new_node->next = NULL;
		if (ll->next)
			ll->next->next = new_node;
		else
			ll->next = new_node;
	}
	return ll;
}

linked_list_t *make_circular(linked_list_t *ll)
{
	linked_list_t *tmp = ll;

	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ll;
	return ll;
}

void print_list(linked_list_t *ll, int nb_item)
{
	int i = 0;

	while (i < nb_item) {
		printf("%s\n", ll->data);
		ll = ll->next;
		i++;
	}
}

int main(int argc, char *argv[])
{
	linked_list_t *ll = NULL;
	int i = 1;

	if (argc < 2)
		fprintf(stderr, "USAGE:\n\t%s [\"opt1\", \"opt2\" ...]", argv[0]);
	while (argv[i] != NULL)
		ll = add_node(ll, argv[i++]);
	ll = make_circular(ll);
	print_list(ll, argc - 1);
	return 0;
}