#include<iostream>
using namespace std;

class Binary_S_Tree
{
    struct BST
    {
        int info;
        struct BST *left;
        struct BST *right;
    };
    struct BST *root = NULL;
    struct BST *check;
    struct BST *new_node;
    int num;

public:
    void create_BST()
    {
        int count = 1;
        cout << " " << endl;
        cout << "Enter elements:- " << endl;
        cout << "\tElement " << count << ": ";
        cin >> num;

        while(num != -1)
        {
            new_node = new BST;
            new_node ->info = num;
            new_node ->left = NULL;
            new_node ->right = NULL;

            if(root == NULL)
            {
                root = new_node;

            }
            else
            {
                check = root;
                while(1)
                {
                    if(check ->info < num)
                    {
                        if(check ->right == NULL)
                        {
                            check ->right = new_node;
                            break;
                        }
                        else
                        {
                            check = check ->right;
                        }
                    }
                    else
                    {
                        if(check ->left == NULL)
                        {
                            check ->left = new_node;
                            break;

                        }
                        else
                        {
                            check = check ->left;
                        }
                    }
                }
            }
            count++;
            cout << "\tElement " << count << ": ";
            cin >> num;
        }

    }
};


int main()
{
    int flag = 0;
    Binary_S_Tree obj;

    do
    {
        int opt;
        cout << "Enter 1 to Create a BINARY SEARCH TREE." << endl;
        cout << "Enter 0 to exit." << endl;
        cout << "\tEnter option: ";
        cin >> opt;
        cout << " " << endl;
        switch(opt)
        {
            case (1): obj.create_BST();
                break;
            case (0): flag = 1;
                break;
            default: cout << "\tERROR!! Invalid Input." << endl;
                break;

        }

    }while(flag == 0);
}
