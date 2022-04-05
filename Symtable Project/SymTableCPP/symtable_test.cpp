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
            
            //listNodes->SymTable_setK("List Node 2");
            //listNodes->SymTable_setV(t);
        }
};


TEST_F(SymTableTest,MisMatchedParameter)
{

}

TEST_F(SymTableTest,ExpectedExceution)
{

}

TEST_F(SymTableTest, NullParamters)
{
    EXPECT_DEATH(obj.SymTable_getLength(NULL),"Assertion Death");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


//Compiling and running 
//cmake CMakeLists.txt
//make
//./runTests