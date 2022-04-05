//Incoperating gtest case for all the functions defined 
#include "symtable_link.cpp"
#include <typeinfo>

#include <gtest/gtest.h>

using namespace std;

class SymTableTest : public ::testing::Test
{

    protected : 
        SymTable_t singleNode,listNodes;
        SymTable obj = SymTable();
        void SetUp() override
        {
            singleNode = obj.SymTable_new();
            void* t;
            t = operator new(sizeof(int));
            *(int*)t = 1;
            singleNode->SymTable_setK("Single Node 1");
            singleNode->SymTable_setV(t);

            listNodes  = obj.SymTable_new();
            //Node 1
            t = operator new(sizeof(int));
            *(int*)t = 1;
            listNodes->SymTable_setK("List Node 1");
            listNodes->SymTable_setV(t);

            //Node 2
            t = operator new(sizeof(int));
            *(int*)t = 2;
            listNodes->SymTable_put(listNodes,"List Node 2",t);

            //Node 3
            t = operator new(sizeof(int));
            *(int*)t = 3;
            listNodes->SymTable_put(listNodes,"List Node 3",t);

            //Node 4
            t = operator new(sizeof(int));
            *(int*)t = 4;
            listNodes->SymTable_put(listNodes,"List Node 4",t);

            //Node 5
            t = operator new(sizeof(int));
            *(int*)t = 5;
            listNodes->SymTable_put(listNodes,"List Node 5",t);
            
        }
};

TEST_F(SymTableTest,ExpectedExceution)
{
    EXPECT_EQ(obj.SymTable_getLength(listNodes),5);
    EXPECT_EQ(obj.SymTable_getLength(listNodes->SymTable_getN()),4);
    EXPECT_EQ(obj.SymTable_getLength(singleNode),1);

    EXPECT_EQ(obj.SymTable_contains(singleNode,"Single Node 1"),1);
    EXPECT_EQ(obj.SymTable_contains(listNodes,"List Node 5"),1);
    EXPECT_EQ(obj.SymTable_contains(listNodes,"Not there"),0);
    EXPECT_NE(obj.SymTable_contains(listNodes,"List Node 5"),4);

    void *t = operator new(sizeof(int));
    *(int*)t = 6;
    EXPECT_EQ(obj.SymTable_put(listNodes,"List Node 6",t),1);
    t = operator new(sizeof(int));
    *(int*)t = 3;
    EXPECT_EQ(obj.SymTable_put(listNodes,"List Node 3",t),0); //already exists

    EXPECT_EQ(obj.SymTable_get(singleNode,"Dummy"),nullptr);
    EXPECT_EQ(obj.SymTable_get(singleNode,"List Node 2"),nullptr);
    
    t = obj.SymTable_get(listNodes,"List Node 2");
    EXPECT_EQ(*(int*)t,2);
    EXPECT_EQ(obj.SymTable_get(listNodes,"dummy"),nullptr);
    EXPECT_EQ(obj.SymTable_get(singleNode,"List Node 2"),nullptr);

    t = obj.SymTable_remove(listNodes,"List Node 5");
    EXPECT_EQ(*(int*)t,5);
    EXPECT_EQ(obj.SymTable_remove(singleNode,"List Node 5"),nullptr);
    
    t = operator new(sizeof(int));
    *(int*)t = 11;
    t = obj.SymTable_replace(listNodes,"List Node 1",t);
    EXPECT_EQ(*(int*)t,1);
    free(t);

    t = operator new(sizeof(int));
    *(int*)t = 11;
    EXPECT_EQ(obj.SymTable_replace(listNodes,"dummy",t),nullptr);
    free(t);
}

TEST_F(SymTableTest, NullParamters)
{
    ASSERT_DEATH(obj.SymTable_getLength(NULL),"Assertion Death");
    ASSERT_DEATH(obj.SymTable_getLength(singleNode->SymTable_getN()),"Assertion Death");

    ASSERT_DEATH(obj.SymTable_map(NULL,NULL,NULL),"Assertion Death"); 

    ASSERT_DEATH(obj.SymTable_contains(NULL,NULL),"Assertion Death");
    ASSERT_DEATH(obj.SymTable_contains(NULL,"dummy"),"Assertion Death"); 
    ASSERT_DEATH(obj.SymTable_contains(singleNode->SymTable_getN(),"dummy"),"Assertion Death"); 
    ASSERT_DEATH(obj.SymTable_contains(singleNode->SymTable_getN(),NULL),"Assertion Death"); 
    
    ASSERT_DEATH(obj.SymTable_put(singleNode->SymTable_getN(),NULL,NULL),"Assertion Death");
    ASSERT_DEATH(obj.SymTable_put(listNodes->SymTable_getN(),NULL,NULL),"Assertion Death");
    ASSERT_DEATH(obj.SymTable_put(NULL,"List Node 4",NULL),"Assertion Death");
    void *t = operator new(sizeof(int));
    *(int*)t = 6;
    ASSERT_DEATH(obj.SymTable_put(NULL,"List Node 4",t),"Assertion Death");
    free(t);
     
    ASSERT_DEATH(obj.SymTable_get(NULL,NULL),"Assertion Death");
    ASSERT_DEATH(obj.SymTable_get(singleNode,NULL),"Assertion Death");

    ASSERT_DEATH(obj.SymTable_remove(NULL,NULL),"Assertion Death");
    ASSERT_DEATH(obj.SymTable_remove(listNodes,NULL),"Assertion Death");

    ASSERT_DEATH(obj.SymTable_replace(NULL,NULL,NULL),"Assertion Death");
    ASSERT_DEATH(obj.SymTable_replace(listNodes,NULL,NULL),"Assertion Death");
    ASSERT_DEATH(obj.SymTable_replace(listNodes,"List Node 1",NULL),"Assertion Death");

}

int main(int argc, char **argv) {

    //PRINT THE LINKED LISTS

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

//Compiling and running 
//cmake CMakeLists.txt
//make
//./runTests