#include "symtable_link.c"

void main()
{
    printf("\n\nUnit Testing the functions\n");
    printf("===========================\n\n");
    printf("Function : SymTable_new(),SymTable_getLength()\n");
    printf("-------------------------\n\n");
    //creating sample objects
    SymTable_t node1 = SymTable_new();
    node1->value = malloc(sizeof(int));
    *(int*)node1->value = 1;
    node1->k = "node 1";

    SymTable_t node2 = SymTable_new();
    node2->value = malloc(sizeof(int));
    *(int*)node2->value = 2;
    node2->k = "node 2";

    SymTable_t node3 = SymTable_new();
    node3->value = malloc(sizeof(int));
    *(int*)node3->value = 3;
    node3->k = "node 3";

    SymTable_t empty_node;
    node1->next = node2;
    node2->next = node3;

    Print_Symtable(node1);
    printf("\nLength from node1   : %d\n",SymTable_getLength(node1));
    printf("Length from node2   : %d\n",SymTable_getLength(node2));
    printf("Length from node3   : %d\n",SymTable_getLength(node3));
    //printf("Length of empty     : %d\n",SymTable_getLength(empty_node)); //Aborting from assertion

    printf("\n\nFunction : SymTable_map()\n");
    printf("-------------------------\n\n");

    void (*print_map)(const char *k , const void *v,const void *extra);
    print_map = funct_apply;

    SymTable_map(node1,print_map,"dummy");

    printf("\n\nFunction : SymTable_free()\n");
    printf("-------------------------\n\n");
    SymTable_free(node3);
    node2->next = NULL;
    //assert(node3 ->next!= NULL);        //Assertion failed as it is deleted
    SymTable_map(node1,print_map,"dummy");

    printf("\n\nFunction : SymTable_contains()\n");
    printf("-------------------------\n");
    int result = SymTable_contains(node1,"node 1");
    printf("Result for \"node 1\": %d\n",result);
    result = SymTable_contains(node1,"node 3");
    printf("Result for \"node 3\": %d\n",result);

    printf("\n\nFunction : SymTable_put()\n");
    printf("-------------------------\n");
    void* void_t = malloc(sizeof(int));
    *(int*)void_t = 4;
    result = SymTable_put(node1,"node 4",void_t);
    void_t = malloc(sizeof(int));
    *(int*)void_t = 5;
    result = SymTable_put(node1,"node 5",void_t);
    void_t = malloc(sizeof(int));
    *(int*)void_t = 6;
    result = SymTable_put(node1,"node 6",void_t);
    SymTable_map(node1,print_map,"dummy");

    printf("\n\nFunction : SymTable_get()\n");
    printf("-------------------------\n");
    void_t = SymTable_get(node1,"node 2");
    //void_t = SymTable_get(node1,"node 3");
    //assert(void_t == NULL);                   //Assertion is invoked for NULL value
    printf("\nValue got : %d for key node 2",*(int*)void_t);

    printf("\n\nFunction : SymTable_remove(node1,\"node 5 \")\n");
    printf("-------------------------\n");
    printf("Before calling SymTable_remove()\n");
    SymTable_map(node1,print_map,"dummy");
    void_t = SymTable_remove(node1,"node 5");
    printf("\nValue recieved  : %d \n",*(int*)void_t);
    printf("After calling SymTable_remove()\n");
    SymTable_map(node1,print_map,"dummy");

    printf("\n\nFunction : SymTable_replace(node1,\"node 4\",14)\n");
    printf("----------------------------\n");
    *(int*)void_t = 14;
    SymTable_replace(node1,"node 4",void_t);
    printf("After calling SymTable_replace()\n");
    SymTable_map(node1,print_map,"dummy");
}

