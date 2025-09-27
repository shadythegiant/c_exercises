#include <stdlib.h>
#include <stdio.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

t_list *createNode(void *data) { 
	t_list *node = malloc(sizeof(t_list)); 
	if(!node) return NULL; 
	node->data = data; 
	node->next = NULL; 
	return(node);  
}

int	ft_list_size(t_list *begin_list) { 
	int len = 0; 
	while(begin_list) { 
		len++; 
		begin_list = begin_list->next; 
	}
	return(len); 
}


int main() { 
	int a = 10, b = 20, c = 30; 
	t_list *node1 = createNode(&a);
	t_list  *node2 = createNode(&b); 
	t_list *node3 = createNode(&c); 
	node1->next = node2; 
	node2->next = node3; 
	node3->next = NULL;  
	printf("%d", ft_list_size(node1)); 
}
