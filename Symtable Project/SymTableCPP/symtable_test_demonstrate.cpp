#include "symtable_link.cpp"

int main()
{
    printf("\n\nUnit Testing the functions\n");
    printf("===========================\n\n");
    printf("Function : SymTable_new(),SymTable_getLength()\n");
    printf("-------------------------\n\n");
    //creating sample objects
    SymTable obj = SymTable();
    SymTable_t node1 = obj.SymTable_new();
    void* t1 = malloc(sizeof(int));
    *(int*)t1 = 1;
    node1->SymTable_setV(t1);
    node1->SymTable_setK("node 1");

    SymTable obj1 = SymTable();
    SymTable_t node2 = obj1.SymTable_new();
    void* t2 = malloc(sizeof(int));
    *(int*)t2 = 1;
    node2->SymTable_setV(t2);
    node2->SymTable_setK("node 2");
    
    SymTable obj2 = SymTable();
    SymTable_t node3 = obj2.SymTable_new();
    void* t3 = malloc(sizeof(int));
    *(int*)t3 = 1;
    node2->SymTable_setV(t3);
    node2->SymTable_setK("node 3");

    SymTable_t empty_node;
    //node1->next = node2;
    //node2->next = node3;

    //SymTable::Print_Symtable(node1);
    printf("\nLength from node1   : %d\n",obj.SymTable_getLength(node1));
    printf("Length from node2   : %d\n",obj.SymTable_getLength(node2));
    printf("Length from node3   : %d\n",obj.SymTable_getLength(node3));
    //printf("Length of empty     : %d\n",SymTable_getLength(empty_node)); //Aborting from assertion

    printf("\n\nFunction : SymTable_map()\n");
    printf("-------------------------\n\n");

    void (*print_map)(const char *k , const void *v,const void *extra);
    print_map = funct_apply;
    obj.SymTable_map(node1,print_map,"dummy");
    printf("\n\nFunction : SymTable_free()\n");
    printf("-------------------------\n\n");
    obj.SymTable_free(node3);
    //node2->next = NULL;
    //assert(node3 ->next!= NULL);        //Assertion failed as it is deleted
    obj.SymTable_map(node1,print_map,"dummy");

    printf("\n\nFunction : SymTable_contains()\n");
    printf("-------------------------\n");
    int result = obj.SymTable_contains(node1,"node 1");
    result = obj.SymTable_contains(node1,"node 3");

    printf("\n\nFunction : SymTable_put()\n");
    printf("-------------------------\n");
    void* void_t = malloc(sizeof(int));
    *(int*)void_t = 4;
    result = obj.SymTable_put(node1,"node 4",void_t);
    void_t = malloc(sizeof(int));
    *(int*)void_t = 5;
    result = obj.SymTable_put(node1,"node 5",void_t);
    void_t = malloc(sizeof(int));
    *(int*)void_t = 6;
    result = obj.SymTable_put(node1,"node 6",void_t);
    obj.SymTable_map(node1,print_map,"dummy");

    printf("\n\nFunction : SymTable_get()\n");
    printf("-------------------------\n");
    void_t = obj.SymTable_get(node1,"node 3");
    printf("\nOUT  2\n%p\n",void_t);
    //void_t = SymTable_get(node1,"node 3");
    //assert(void_t == NULL);                   //Assertion is invoked for NULL value
    printf("\nValue got : %d for key node 2",*(int*)void_t);
    printf("\n\nFunction : SymTable_remove(node1,\"node 5 \")\n");
    printf("-------------------------\n");
    printf("Before calling SymTable_remove()\n");
    obj.SymTable_map(node1,print_map,"dummy");
    void_t = obj.SymTable_remove(node1,"node 5");
    printf("\nValue recieved  : %d \n",*(int*)void_t);
    printf("After calling SymTable_remove()\n");
    obj.SymTable_map(node1,print_map,"dummy");

    printf("\n\nFunction : SymTable_replace(node1,\"node 4\",14)\n");
    printf("----------------------------\n");
    *(int*)void_t = 14;
    obj.SymTable_replace(node1,"node 4",void_t);
    printf("After calling SymTable_replace()\n");
    obj.SymTable_map(node1,print_map,"dummy");

    return 0;
}

