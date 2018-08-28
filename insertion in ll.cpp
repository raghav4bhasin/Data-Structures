
#include<iostream>
using namespace std;
class ll{
    struct node
    {
        int value;
        struct node *next;
    };
    struct node *start;
    struct node *ptr;
    struct node *save;
    struct node *copy_;
public:
    ll()
    {
        start=NULL;
    }
    void create_ll()
    {
        int num;
        struct node *new_node;
        cout<<"enter number"<<endl;
        cin>>num;
        while(num!=-1)
        {
            if(start==NULL){
            new_node=new node;
            new_node->value=num;
            new_node->next=start;
            start=new_node;
            save=new_node;
            }
            else{
            new_node=new node;
            new_node->value=num;
            new_node->next=NULL;       // OR -- new_node->next=save->next;
            save->next=new_node;
            save=new_node;
            }
            cin>>num;
        }
    }
    void show()
    {
        ptr=start;
        cout<<"link list ->"<<endl;
        while(ptr!=NULL)
        {
            cout<<ptr->value<<"  address= "<<ptr<<endl;
            ptr=ptr->next;
        }
    }
    void insert_beg(int num)
    {
        struct node *new_node;
       new_node= new node;
       new_node->value=num;
       new_node->next=start;
       start=new_node;
    }
    void insert_end(int num)
    {
        struct node *new_node;
        new_node=new node;
        new_node->value=num;
        new_node->next=save->next;
        save->next=new_node;
        save=new_node;
    }
    void insert_after(int given,int num)
    {
        struct node *new_node;
        ptr=start;
        while(ptr!=NULL)
        {
            if(ptr->value==given)
                break;
            ptr=ptr->next;
        }
        new_node=new node;
        new_node->value=num;
        new_node->next=ptr->next;
        ptr->next=new_node;
    }
    void insert_before(int given,int num)
    {
        struct node *new_node;
        ptr=start;
        while(ptr!=NULL)
        {
            if(ptr->value==given)
                break;
                copy_=ptr;
            ptr=ptr->next;
        }
        new_node=new node;
        new_node->value=num;
        new_node->next=copy_->next;
        copy_->next=new_node;
    }
    void insert_sort(int num)
    {
        int flag;
        struct node *new_node;
        copy_ = NULL;
        ptr=start;
        while(ptr!=NULL)
        {
            if(ptr->value>num)
            {
                break;
            }
                copy_= ptr;
                ptr=ptr->next;
            }


            if(ptr==NULL)
            {
                insert_end(num);
            }
            else if(copy_== NULL)
            {

                insert_beg(num);
            }
            else{
                new_node= new node;
                new_node->value=num;
                new_node->next=copy_->next;
                copy_->next = new_node;


            }

        }

};
int main()
{
    int ch;
    ll obj;
    cout<<"enter 1 to create link list"<<endl;
    cin>>ch;
    switch(ch){
    case 1:
         obj.create_ll();
         obj.show();
         break;
            }
    int ch1;
    cout<<"enter 1 to insert at beginning"<<endl;
    cout<<"enter 2 to insert at end"<<endl;
    cout<<"enter 3 to insert after the given element"<<endl;
    cout<<"enter 4 to insert before the given element"<<endl;
    cout<<"enter 5 to insert in a sorted list"<<endl;
    cin>>ch1;
    switch(ch1){
    case 1:
        obj.insert_beg(12);
        cout<<"after inserting"<<endl;
        obj.show();
        break;
    case 2:
        obj.insert_end(13);
        cout<<"after inserting"<<endl;
        obj.show();
    case 3:
        int x;
        cout<<"enter the no after which element is to be inserted"<<endl;
        cin>>x;
        obj.insert_after(x,14);
        cout<<"after inserting"<<endl;
        obj.show();
    case 4:
        int y;
        cout<<"enter the no before which element is to be inserted"<<endl;
        cin>>y;
        obj.insert_before(y,15);
        cout<<"after inserting"<<endl;
        obj.show();
    case 5:
        obj.insert_sort(1);
        cout<<"after inserting"<<endl;
        obj.show();
    }
}

