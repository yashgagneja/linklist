
LOGIN
SIGNUP
SUBMIT
Search here...
C++ : Concatenating two linked lists in C++
May 30, 2017 C++ LINKED LIST DATA STRUCUTRE  33457
submit your article
Become an Author
Submit your Article
Download Our App.
BlogsDope App
Get it on Google Play


 
Previous:
Linked lists in C++ (Singly linked list)
Linked list traversal using while loop and recursion in C++
Make sure that you are familiar with the concepts explained in the post(s) mentioned above before proceeding further.

We will proceed further by taking the linked list we made in the previous post

#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

class linked_list
{
private:
    node *head,*tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
};

int main()
{
    linked_list a;
    a.add_node(1);
    a.add_node(2);
    return 0;
}
Concatenating or joining two linked lists is not at all a difficult task. We just need to follow some very simple steps and the steps to join two lists (say ‘a’ and ‘b’) are as follows:

Traverse over the linked list ‘a’ until the element next to the node is not NULL.
If the element next to the current element is NULL (a->next == NULL) then change the element next to it to ‘b’ (a->next = b).
That’s it. Let’s code up these steps.

.

void concatenate(struct node *a,struct node *b)
{
    if (a->next == NULL)
        a->next = b;
    else
        concatenate(a->next,b);
}
Here, we are traversing over the article using recursion as explained in the article “Linked list traversal using while loop and recursion”. We are firstly checking if the next node (a->next) is NULL or not. If it is NULL, then we are just changing its value from NULL to ‘b’ (a->next = b) and if it is not then we are calling the ‘concatenate’ function again with the next element to traverse over the list.

So, the whole code is:

#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

class linked_list
{
private:
    node *head,*tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    node* gethead()
    {
        return head;
    }

    static void display(node *head)
    {
        if(head == NULL)
        {
            cout << "NULL" << endl;
        }
        else
        {
            cout << head->data << endl;
            display(head->next);
        }
    }

    static void concatenate(node *a,node *b)
    {
        if( a != NULL && b!= NULL )
        {
            if (a->next == NULL)
                a->next = b;
            else
                concatenate(a->next,b);
        }
        else
        {
            cout << "Either a or b is NULL\n";
        }
    }
};

int main()
{
    linked_list a;
    a.add_node(1);
    a.add_node(2);
    linked_list b;
    b.add_node(3);
    b.add_node(4);
    linked_list::concatenate(a.gethead(),b.gethead());
    linked_list::display(a.gethead());
    return 0;
}
