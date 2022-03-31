#include "symtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <omp.h>


void Print_Symtable(SymTable_t t)
{
    printf("%p\n",t->k);
    printf("%d\n",*(int*)t->value);
    printf("%p\n",t->next);
}

SymTable_t SymTable_new (void)
{
    //SymTable_t t = (Value_t)malloc(sizeof(Value));


    SymTable_t t = (SymTable_t)malloc(sizeof(struct SymTable));
    if(t == NULL)
        return NULL;
    t->next = NULL;

    t->value = malloc(sizeof(int));
    //t -> value = (int)malloc(sizeof(int));
    if(t->value == NULL)
        return NULL;
    return t;
}

void SymTable_free(SymTable_t oSymTable)
{
    assert(oSymTable != NULL);
    free(oSymTable->value);
    free(oSymTable);
}

int SymTable_getLength(SymTable_t oSymTable)
{
    assert(oSymTable != NULL);
    int count=0;
    
    while(oSymTable != NULL)
    {
        oSymTable = oSymTable->next;
        count++;
    }
    return count;
}

void funct_apply(const char *k ,const void *v,const void *extra)
{
    assert(k != NULL);
    assert(v != NULL);
    assert(extra != NULL);
    printf("Key : %s, Value : %d\n",k,*(int*)v);
}

void SymTable_map (SymTable_t oSymTable,
        void (*pfApply) (const char *pcKey,const void *pvValue,const void *pvExtra),const void *pvExtra)
{
    assert(oSymTable != NULL);
    //assert(pfApply != NULL);


    SymTable_t temp = oSymTable;
    while(temp != NULL)
    {
        pfApply(temp->k,temp->value,pvExtra);
        temp = temp -> next;
    }
}

int SymTable_contains (SymTable_t oSymTable,const char *pcKey)
{
    assert(oSymTable != NULL);
    assert(pcKey != NULL);
    
    while(oSymTable != NULL)
    {
        if(oSymTable->k == pcKey)
        {
            return 1;
        }
        oSymTable = oSymTable->next;
    }
    return 0;
}

int SymTable_put(SymTable_t oSymTable,const char *pcKey,const void *pvValue)
{
    //if(SymTable_contains(oSymTable,pcKey) == 0)
    assert(oSymTable != NULL);
    assert(pcKey != NULL);
    assert(pvValue != NULL);
    
    while(oSymTable->next != NULL)
    {
        //printf("Key ");
        if(oSymTable->k == pcKey)
        {
            printf("Key value already exists in the Symbol Table");
            return 0;
        }
        oSymTable = oSymTable->next;
    }
    if(oSymTable->k == pcKey)
    {
        printf("Key value already exists in the Symbol Table");
        return 0;
    }
    SymTable_t t = SymTable_new();
    if(t == NULL)
    {
        return 0;
    }
    t->k = pcKey;
    *(int*)t->value = *(int*)pvValue;
    oSymTable->next = t;
    return 1;
    //*(int*)t->value = 1;
    
}
void *SymTable_get (SymTable_t oSymTable, const char *pcKey)
{
    assert(oSymTable != NULL);
    assert(pcKey != NULL);
    
    while(oSymTable != NULL)
    {
        if(oSymTable->k == pcKey)
        {
            return oSymTable->value;
        }
        oSymTable = oSymTable->next;
    }
    return NULL;
}

void *SymTable_remove (SymTable_t oSymTable,const char *pcKey)
{
    assert(oSymTable != NULL);
    assert(pcKey != NULL);
    
    if(oSymTable->k == pcKey)
    {
        SymTable_t temp = oSymTable;
        void* t = oSymTable->value;
        oSymTable = oSymTable->next;
        free(oSymTable);
        return t;
    }
    while(oSymTable->next != NULL)
    {
        if(oSymTable->next->k == pcKey)
        {
            SymTable_t to_remove = oSymTable->next;
            void* t = to_remove->value;
            oSymTable->next = to_remove->next;
            free(to_remove);
            return t;
        }
        oSymTable = oSymTable->next;
    }
    return NULL;
}

void *SymTable_replace (SymTable_t oSymTable,const char *pcKey,const void *pvValue)
{
    assert(oSymTable != NULL);
    assert(pcKey != NULL);
    assert(pvValue != NULL);
    while(oSymTable != NULL)
    {
        if(oSymTable->k == pcKey)
        {
            void* t = oSymTable->value;
            oSymTable->value = pvValue;
            return t;
        }
        oSymTable = oSymTable->next;
    }
    return NULL;
}
/*
void main()
{
    SymTable_t node1 = SymTable_new();
    node1->value = malloc(sizeof(int));
    *(int*)node1->value = 1;
    node1->k = "node 1";

    SymTable_t node2 = SymTable_new();
    node2->value = malloc(sizeof(int));
    *(int*)node2->value = 2;
    node2->k = "node 2";
    
    node1->next = node2;

    Print_Symtable(node1);
    printf("\nSize at node1 : %d\n",SymTable_getLength(node1));
    printf("Size at node2 : %d\n",SymTable_getLength(node2));

    printf("Map Function call\n");

    void (*print_map)(const char *k , const void *v,const void *extra);
    print_map = funct_apply;

    SymTable_map(node1,print_map,"c");
    printf("Contains : %d\n",SymTable_contains(node1,"node "));

}*?





//Reference code

    //SymTable_t temp = (SymTable_t)malloc(sizeof(Symtable));
    /*
    SymTable_t temp = SymTable_new();
    temp->opaque_val = (Value_t)malloc(sizeof(Value));
    temp->opaque_val->val = 5;*/


/*
typedef struct SymTable
{
    char* k;
    int value;
    SymTable_t next;
} Symtable;
*/