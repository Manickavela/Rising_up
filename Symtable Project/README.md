# SymTable

SymTable is a main data structure created and maintained by compilers in order to keep track of the semantics of variables

- Scope and Binding information about names
- Information about instances like classes,names,objects,etc

## class SymTable 
  Binds Key and Value together.
  k        : Char*
  value    : Void* 
  next     : SymTable*  

## Interfaces Available

- SymTable_t SymTable_new (void);
  Returns an SymTable node with values initialised to NULL.
  
- void SymTable_free(SymTable_t oSymTable);
  Frees the alloted memory associated woth the node oSymTable
  
- int SymTable_getLength(SymTable_t oSymTable);
  Returns the length of the list of nodes , traversing foreward from oSymTable
  
- int SymTable_put(SymTable_t oSymTable,const char *pcKey,const void *pvValue);
  Returns 0 if it fails to append , returns 1 if successfully appended
  pcKey is unique in the symtable list,fails if repeats
  
  
- void *SymTable_replace(SymTable_t oSymTable,const char *pcKey,const void *pvValue);
  Returns the replaced old value
  It replaces based the the pcKey match, with the pvValue match; 
  
- int SymTable_contains (SymTable_t oSymTable,const char *pcKey);'
  Returns 0 if node with pcKey is present in oSymTable ,
          1 if it isn't available.
  
- void *SymTable_get (SymTable_t oSymTable, const char *pcKey);
  Returns the Value if pcKey exists in oSymTable else returns nullptr
  
- void *SymTable_remove (SymTable_t oSymTable,const char *pcKey);
  Retruns the pointer to Value after removing it from the oSymTable
  
- void SymTable_map (SymTable_t oSymTable,void (*pfApply) (const char *pcKey,const void *pvValue,const void *pvExtra),const void *pvExtra);
  funtion pfApply is applied to the oSymTable linked list, successively over each nodes one after another.
