#include "symtable.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <omp.h>

using namespace std;


void SymTable::SymTable_setV(void* t)
{
    value = t;
}


void SymTable::SymTable_setK(char* t)
{
    k = t;
}

void SymTable::SymTable_setN(SymTable_t t)
{
    next = t;
}

//Creates a new node by dynamically allocating the necessary variables
//and initializes them accordingly 
SymTable* SymTable::SymTable_new (void)
{
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

//Given the node pointer it frees the alloted memory from 
//for both SymTable node and the value pointer in it
void SymTable::SymTable_free(SymTable_t oSymTable)
{
    assert(oSymTable != NULL);
    free(oSymTable->value);
    free(oSymTable);
}

//Gets the lenght of the linked list by traversing through 
//from oSymtable on 
int SymTable::SymTable_getLength(SymTable_t oSymTable)
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

//Sample function iused for testing the SymTable_map function
void funct_apply(const char *k ,const void *v,const void *extra)
{
    //printf("Key : %s, Value : %d\n",k,*(int*)v);
    cout<<"Key : "<<k<<" Value : "<<*(int*)v<<endl;
}

//SymTable_map tabes the function as parameter and
//applies it to the linked list traversing through the node
void SymTable::SymTable_map (SymTable_t oSymTable,
    void (*pfApply) (const char *pcKey,const void *pvValue,const void *pvExtra),const void *pvExtra)
{
    assert(oSymTable != NULL);
    SymTable_t temp = oSymTable;
    while(temp != NULL)
    {
        pfApply(temp->k,temp->value,pvExtra);
        temp = temp -> next;
    }
}

//Checks whether the pKey is available or not by 
//traversing through the list from oSymTable
int SymTable::SymTable_contains (SymTable_t oSymTable,const char *pcKey)
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

//Takes in all the necessary info for creating a new node 
//and appending it to the linked list 
//it maintaians that there isn't any repetition on the pKey value
int SymTable::SymTable_put(SymTable_t oSymTable,const char *pcKey,const void *pvValue)
{
    //if(SymTable_contains(oSymTable,pcKey) == 0)
    assert(oSymTable != NULL);
    assert(pcKey != NULL);
    assert(pvValue != NULL);
    
    while(oSymTable->next != NULL)
    {
        if(oSymTable->k == pcKey)
        {
            printf("Key value already exists in the Symbol Table");
            return 0;
        }
        oSymTable = oSymTable->next;
    }
    if(oSymTable->k == pcKey)
    {
        //printf("Key value already exists in the Symbol Table");
        cout<<"Key value already exists in the Symbol Table"<<endl;
        return 0;
    }
    SymTable_t t = SymTable_new();
    if(t == NULL)
    {
        return 0;
    }
    t->k = const_cast<char*>(pcKey);
    t->value = (void*)pvValue;
    //*(int*)t->value = *(int*)pvValue;
    oSymTable->next = t;
    return 1;
    
}

//Searches through the entire list with pKey
//and returns the value on finding the pKey
void *SymTable::SymTable_get (SymTable_t oSymTable, const char *pcKey)
{
    assert(oSymTable != NULL);
    assert(pcKey != NULL);
    while(oSymTable->next != NULL)
    {
        if(oSymTable->k == pcKey)
        {
            return oSymTable->value;
        }
        oSymTable = oSymTable->next;
    }
    printf("\nOUT\n");
    return NULL;
}

//Removes the node wIth the key pcKey from the linked list oSymTable
void *SymTable::SymTable_remove (SymTable_t oSymTable,const char *pcKey)
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


//Replaces the Value with pvValue at the node 
//where pcKey matches , returns NULL if it isn't available
void *SymTable::SymTable_replace (SymTable_t oSymTable,const char *pcKey,const void *pvValue)
{
    assert(oSymTable != NULL);
    assert(pcKey != NULL);
    assert(pvValue != NULL);
    while(oSymTable != NULL)
    {
        if(oSymTable->k == pcKey)
        {
            void* t = oSymTable->value;
            oSymTable->value = const_cast<void*>(pvValue);
            return t;
        }
        oSymTable = oSymTable->next;
    }
    return NULL;
}