// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

//

typedef struct s_list
{
void *content;
struct s_list *next;
} t_list;
//

t_list *ft_lstnew(void *content) { 
    t_list *node = malloc(sizeof(t_list));
    if(!node)
        return NULL; 
    node->content = content; 
    node->next = NULL;
    return(node); 
} 

t_list ft_lstlast(t_list *lst) { 
    t_list *last = lst; 
    if(!lst)
        return NULL; 
    while(last->next) 
    { 
        last = last->next; 
    } 
    return (last); 
} 

void ft_lstadd_front(t_list **lst, t_list *new) {  
    if(lst != NULL && new != NULL) { 
        new->next = *lst;
        *lst = new; 
    } 
} 
int ft_lstsize(t_list *lst)  {  
    int len = 0; 
    t_list *temp = lst; 
    while(temp) { 
        len++; 
        temp = temp->next; 
    } 
    return (len); 
} 

void ft_lstadd_back(t_list **lst, t_list *new) { 
    if(!lst || !new)
        return NULL; 
    if(*lst)
        ft_lstlast(*lst)->next = new; 
    else
        *lst = new; 
    
} 
void ft_lstdelone(t_list *lst, void (*del)(void
*)) { 
    if(lst != NULL) { 
        (*del)lst->content; 
        free(lst); 
    }
} 

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *)) { 
    t_list *head; 
    t_list *tmp; 
    void  *data; 
    if(!lst || !f || !del)
        return NULL; 
    head = NULL; 
    while(lst) { 
        data = (*f)(lst->content); 
        tmp = ft_lstnew(data); 
        if(tmp == NULL) { 
            del(data);
            ft_lstclear(&head, del);
            return NULL; 
        } 
        ft_lstadd_back(&head, tmp); 
        
    } 
    return (head); 
} 

int main() {
    // Write C code here
    printf("Try programiz.pro");

    return 0;
}
