#include<iostream>
#include<stack>
#include<queue>
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
    struct BST *ptr;
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
                            cout << "\t\tParent Node of " << num << " is: " << check ->info << endl;
                            break;
                        }
                        else
                        {
                            check = check ->right;
                        }
                    }
                    else if(check ->info >= num)
                    {
                        if(check ->left == NULL)
                        {
                            check ->left = new_node;
                            cout << "\t\tParent Node of " << num << " is: " << check ->info << endl;
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
        cout << "_______________**********_______________" << endl;
        line();

    }
    void line()
    {
        cout << " " << endl;
    }


    void Search_el()
    {
        int count = 0;
        int num;
        struct BST *parent;
        check = root;
        parent = NULL;
        line();
        cout << "Enter element to search: ";
        cin >> num;

        while(1)
        {
            if(check ->info == num)
            {
                if(check == root )
                {
                    cout << "Number found as the Root element." << endl;
                    break;

                }

                else
                {

                    cout << "\tParent of " << check ->info << ": " << parent ->info << endl;
                    cout << "Number found." << endl;


                    line();
                    break;

                }
            }
            else if(check ->info < num && check ->right != NULL)
            {
                parent = check;
                check = check ->right;
            }
            else if(check ->info >= num && check ->left)
            {
                parent = check;
                check = check ->left;
            }
            else
            {
                if(count > 0)
                {
                    cout << "Frequency of " << num << ": " << count << endl;
                    cout << " " << endl;
                    break;
                }
                else
                {
                    cout << "Number was NOT FOUND." << endl;
                    cout << " " << endl;
                    break;
                }
            }
        }
    }
    void max_el()
    {
        check = root;

        while(check ->right != NULL)
        {
            check = check ->right;
        }
        cout << " " << endl;
        cout << "Maximum Element: " << check ->info << endl;
        cout << " " << endl;
    }

    void min_el()
    {
        check = root;

        while(check ->left != NULL)
        {
            check = check ->left;
        }
        line();
        cout << "Minimum Element: " << check ->info << endl;
        line();
    }


    void traversal()
    {
        int i = 0;
        char op;
        while(i == 0)
        {
            cout << "Enter 'a' to print the tree in INORDER." << endl;
            cout << "Enter 'b' to print the tree in PREORDER." << endl;
            cout << "Enter 'c' to print the tree in POSTORDER." << endl;
            cout << "\tEnter option: ";
            cin >> op;
            switch(op)
            {
                case('a'): inorderstl();
                    break;
                default: cout << "\t\tERROR!! Invalid Input." << endl;
                    break;

            }
        }
        line();

    }

    void LevelOrder()
    {
        queue<BST*> myqu;

        myqu.push(root);

        cout << "Elements: ";
        ptr = myqu.front();

        while(!myqu.empty())
        {
            myqu.pop();
            cout << ptr ->info << " ";
            if(ptr ->left != NULL)
                myqu.push(ptr ->left);
            if(ptr ->right != NULL)
                myqu.push(ptr ->right);

            ptr = myqu.front();
        }
        cout << endl;
        line();
    }

    void inorderstl()
    {
        line();
        cout << "\tINORDER TRAVERSAL: ";
        stack<BST*> stk;
        ptr = root;
        do
        {
            if (ptr)
            {
                stk.push(ptr);
                ptr = ptr ->left;

            }

            else //BACKTRACKING
            {
                ptr = stk.top();
                stk.pop();
                cout << ptr ->info << " ";
                ptr = ptr ->right;
            }
        } while(!stk.empty() || ptr != NULL);

        line();
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
        cout << "Enter 2 to Search an element in BINARY SEARCH TREE." << endl;
        cout << "Enter 3 to find the maximum element." << endl;
        cout << "Enter 4 to find the minimum element." << endl;
        cout << "Enter 5 to display the tree." << endl;
        cout << "Enter 6 to Traverse the tree with Level Order Traversing." << endl;
        cout << "Enter 0 to exit." << endl;
        obj.line();
        cout << "\tEnter option: ";
        cin >> opt;
        cout << endl;
        cout << " " << endl;
        switch(opt)
        {
            case (1): obj.create_BST();
                break;
            case (2): obj.Search_el();
                break;
            case (3): obj.max_el();
                break;
            case (4): obj.min_el();
                break;
            case (5): obj.traversal();
                break;
            case (6): obj.LevelOrder();
                break;
            case (0): flag = 1;
                break;
            default: cout << "\t\tERROR!! Invalid Input." << endl;
                break;

        }
        obj.line();

    }while(flag == 0);
}
