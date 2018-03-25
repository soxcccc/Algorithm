#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
    struct node *next; 
	// keep in mind: 'struct' must be included when declaring struct variable
};

typedef struct node Node;
Node *initList();
Node *merge(Node *head1, Node *head2);

int main()
{
	Node *a1, *a2, *a3, *cur;
	a1 = initList();
	a2 = initList();
	a3 = merge(a1, a2);
	for(cur = a3; cur != NULL; cur = cur->next) {
        printf("%d ", cur->data);
    }
    printf("\n");

	return 0;
}

Node *initList()
{
	// creat list by creating a series of nodes
	int i;
	Node *head = (Node *) malloc(sizeof(Node));
	Node *cur, *p;
	scanf("%d", &i);
	cur = head;
	while(i--) {
		cur->next = (Node *) malloc(sizeof(Node));
		cur = cur->next;
		scanf("%d", &(cur->data));
		cur->next = NULL;
	}
	cur = head;
	head = head->next;
	free(cur);
	return head;
}

Node *merge(Node *a, Node *b)
{
	// merge two sorted series
	Node *head = (Node *) malloc(sizeof(Node)), *cur;
	cur = head;
	while(a&&b)
	{
		if (a->data<b->data)
		{
			cur->next = a;
			cur = a;
			a = a->next;
		}
		else
		{
			cur->next = b;
			cur = b;
			b = b->next;
		}
	}
	(!a) ? (cur->next = b):(cur->next = a);
	cur = head;
	head = head->next;
	free(cur);
	return head;
}