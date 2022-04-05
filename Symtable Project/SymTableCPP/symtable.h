

typedef class SymTable* SymTable_t;

class SymTable 
{
    private : 
        char* k;
        void* value;
        class SymTable *next;
    public : 

        //self defined helper functions
        void SymTable_setV(void* t);
        void SymTable_setK(char* t);
        void SymTable_setN(SymTable_t t);

        //functions as per SymTable requirment 
        SymTable_t SymTable_new (void);
        void SymTable_free(SymTable_t oSymTable);
        int SymTable_getLength(SymTable_t oSymTable);
        int SymTable_put(SymTable_t oSymTable,const char *pcKey,const void *pvValue);
        void *SymTable_replace(SymTable_t oSymTable,const char *pcKey,const void *pvValue);
        int SymTable_contains (SymTable_t oSymTable,const char *pcKey);
        void *SymTable_get (SymTable_t oSymTable, const char *pcKey);
        void *SymTable_remove (SymTable_t oSymTable,const char *pcKey);
        void SymTable_map (SymTable_t oSymTable,
        void (*pfApply) (const char *pcKey,const void *pvValue,const void *pvExtra),
            const void *pvExtra);

};

