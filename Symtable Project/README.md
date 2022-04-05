# SymTable

SymTable is a main data structure created and maintained by compilers in order to keep track of the semantics of variables

- Scope and Binding information about names
- Information about instances like classes,names,objects,etc

#Interfaces Available

- SymTable_t SymTable_new (void);
- void SymTable_free(SymTable_t oSymTable);
- int SymTable_getLength(SymTable_t oSymTable);
- int SymTable_put(SymTable_t oSymTable,const char *pcKey,const void *pvValue);
- void *SymTable_replace(SymTable_t oSymTable,const char *pcKey,const void *pvValue);
- int SymTable_contains (SymTable_t oSymTable,const char *pcKey);
- void *SymTable_get (SymTable_t oSymTable, const char *pcKey);
- void *SymTable_remove (SymTable_t oSymTable,const char *pcKey);
- void SymTable_map (SymTable_t oSymTable,
- void (*pfApply) (const char *pcKey,const void *pvValue,const void *pvExtra),const void *pvExtra);
