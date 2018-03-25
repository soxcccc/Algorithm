/* file: a1p2_2.c */
#include<stdio.h>
#include<stdlib.h>
 
struct LinkedList {
    int value;
    struct LinkedList *next;
};
 
typedef struct LinkedList LinkedList;
LinkedList *reverse(LinkedList *head, int len);
 
int main() {
    /* read the input and create the list */
    int n, i;
	LinkedList *head = (LinkedList *) malloc(sizeof(LinkedList));
    LinkedList *cur, *p;
    scanf("%d", &n);
    cur = head;
    
    i = n;
    while(i--) {
        cur->next = (LinkedList *) malloc(sizeof(LinkedList));
        cur = cur->next;
        scanf("%d", &(cur->value));
        cur->next = NULL;
    }
    
    /* delete the placeholder at head */
    cur = head;
    head = head->next;
    free(cur);
    
    /* reverse the list */
    head = reverse(head, n);
    
    /* print the result */
    for(cur = head; cur != NULL; cur = cur->next) {
        printf("%d ", cur->value);
    }
    printf("\n");
    
    /* free the list nodes */
    for(cur = head; cur != NULL; free(p)) {
        p = cur;
        cur = cur->next;
    }
    head = NULL;
    
    return 0;
}
 

LinkedList *reverse(LinkedList *head, int len) {
	LinkedList *p, *cur, *nHead = (LinkedList *)malloc(sizeof(LinkedList));
	nHead->next = NULL;
	for(cur = head, p = cur->next; cur; ) {
		cur->next = nHead->next;
		nHead->next = cur;
		cur = p;
		if (p!=NULL) p = cur->next;
	}
	cur = nHead;
	nHead = nHead->next;
	free(cur);
	free(p);
	return nHead;
}
