# SymTable

SymTable is a main data structure created and maintained by compilers in order to keep track of the semantics of variables

- Scope and Binding information about names
- Information about instances like classes,names,objects,etc

## Class SymTable 
Class SymTable binds Key and Value together along with the the next variable of SymTable pointer type to keep the linked list going.
All the data members are under private and memberfunctions are pubilc
  
  |Data Members | Data Type |
  |------------ | --------- |
  |k | Char* |
  |value | Void* |
  |next  | SymTable* | 
  
  
  
 
## Interfaces Available

Below are all the available member functions from the symtable for public access.

|Return Type| Function name | About|
|-----------| ------------- | -----|
|SymTable_t | SymTable_new (void); | Returns an SymTable node with values initialised to NULL.|
|void |SymTable_free(SymTable_t oSymTable);| Frees the alloted memory associated woth the node oSymTable. |
|int | SymTable_getLength(SymTable_t oSymTable); | Returns the length of the list of nodes , traversing foreward from oSymTable|
|int | SymTable_put(SymTable_t oSymTable,const char *pcKey,const void *pvValue); |Returns 0 if it fails to append , returns 1 if successfully appended pcKey is unique in the symtable list,fails if repeats |
|void| *SymTable_replace(SymTable_t oSymTable,const char *pcKey,const void *pvValue);| Returns the replaced old value it replaces based the the pcKey match, with the pvValue match; |
|int|SymTable_contains(SymTable_t oSymTable,const char *pcKey);|Returns 0 if node with pcKey is present in oSymTable ,1 if it isn't available.|
|void |*SymTable_get(SymTable_t oSymTable, const char *pcKey);| Returns the Value if pcKey exists in oSymTable else returns nullptr|
|void |*SymTable_remove (SymTable_t oSymTable,const char *pcKey);|Returns the pointer to Value after removing it from the oSymTable|
|void |SymTable_map(SymTable_t oSymTable,void (*pfApply) (const char *pcKey,const void *pvValue,const void *pvExtra),const void *pvExtra);| funtion pfApply is applied to the oSymTable linked list, successively over each nodes one after another.|
 
  
  ## Testing
  
  All the necessary test for the member funtions is availble in the symtable_test.cpp file
  Testing is done with Gtest Framework as it makes testing more organised,independent and .
  SymTableTest is the class defined for creating Test Fixture class. When there is multiple tests in an test suite need to share some 
  common objects or subroutines they are put into the test fixture classes.  
