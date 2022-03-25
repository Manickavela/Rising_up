#include <iostream>

using namespace std;

template <class T>
class BTreeNode
{
    private :
        T data;
    protected :
        /*T get_value()
        {
            return data;
        }*/
        void set_left(BTreeNode *left_val)
        {
            left = left_val;
        }
        void set_right(BTreeNode *right_val)
        {
            right = right_val;
        }
    public :
        BTreeNode *left,*right;
        BTreeNode()
        {
            data = T();
            left = NULL;
            right = NULL;
        }
        BTreeNode(T val)
        {
            data = val;
            left = NULL;
            right = NULL;
        }
        BTreeNode& createBTreeNode(T val)
        {
            BTreeNode tmp = new BTreeNode(val);
            return &tmp;
        }
        T get_value()
        {
            return data;
        }
        void print()
        {
            cout<<data<<endl;
        }
};

class BinaryTree : protected BTreeNode<int>
{
    private:
        BTreeNode* root;
    protected :
    public:
        BTreeNode* get_root()
        {
            return root;
        }
        BinaryTree()
        {
            root = NULL;
        }
        BinaryTree(int a)
        {
            root = new BTreeNode(a);
        }
        int height(BTreeNode* node = NULL)
        {
            if(node == NULL)
                return 0;
            else
            {
                int lheight = height(node->left);
                int rheight = height(node->right);
                if(lheight > rheight)
                    return lheight + 1;
                else
                    return rheight + 1;
            }
        }
        void CurrentLevel(BTreeNode *&node,int level)
        {
            cout<<"Came level : "<<level<<endl;
            if(node == NULL)
                return;
            if (level == 1)
                cout<<node->get_value()<<endl;
            else if (level > 1) 
            {
                CurrentLevel(root->left, level-1);
                CurrentLevel(root->right, level-1);
            }
        }
        void LevelOrder(BTreeNode* root) 
        {
            int h = height(root);
            int i;
            for (i = 1; i <= h; i++)
                CurrentLevel(root, i);
        }
        void insertNode(const int val,BTreeNode *&node)
        {
            if(node == NULL)
            {
                node = new BTreeNode(val);
            }
            else
            {
                if(val < (node->get_value()))
                    insertNode(val,node->left);
                else
                    insertNode(val,node->right);
            }
        }
        void printTree(BTreeNode *&node)
        {
            if(node != NULL)
            {
                printTree(node->left);
                cout<<" "<<node->get_value()<<endl;
                printTree(node->right);
            }
        }
};

int main()
{
    BinaryTree *btree = new BinaryTree(7);
    BTreeNode<int>* my = btree->get_root();
    
    btree->insertNode(5,my);
    btree->insertNode(3,my);
    btree->insertNode(10,my);
    btree->insertNode(6,my);

    //cout<<btree->height(btree->get_root())<<endl;
    cout<<"Current value "<<endl;
    btree->CurrentLevel(my,2);
    btree->printTree(my);
    
}