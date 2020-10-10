#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;

template<typename T>
class Stack
{
    /*Realization of stack that can store all primitive
      types of data, i'm not strongly familiar with templates
      so any changes must be taking into consederation.

      Insertion and deletion - at beginning.To make each operation O(1),
      but when we insert and delete at the end, time complexity will be O(n).

      Implementation using linked list!
      */
     

private:
    struct node
    {
        T data;
        struct node* next_node;
    }*topN;
public:
    Stack() {topN = NULL;}
    void push(T itemToPush);
    bool isEmpty(void);
    void pop(void);
    void distroyStack(struct node *topN)
    {
        if (topN != NULL)
        {
            distroyStack(topN->next_node);
            free(topN);
            topN = nullptr;
        }
    }
    T top(void);

    ~Stack()
    {
        if (topN)
        {
            distroyStack(topN);
            topN = nullptr;
        }
    }
};

template<typename T>
void Stack<T>::push(T itemToPush)
{
    //Push element to stack O(1).
    struct node*tempP = (struct node*)malloc(sizeof(struct node));
    tempP->data = itemToPush;
    tempP->next_node = topN;
    topN = tempP;
}

template<typename T>
bool Stack<T>::isEmpty()
{
    //return true if empty, otherwise - false.
    if(!topN) return  true;
    return false;
}

template<typename T>
void Stack<T>::pop()
{
    if(isEmpty()) return; //means that stack is empty
    else
    {
        //if not empty, pop the first node.
        struct node* tempP;
        tempP = topN;
        topN = tempP->next_node;
        free(tempP);
        //return  data; // return value that was stored in poped node.
    }
}

template <typename T>
T Stack<T>::top()
{
    //return the data stored in the first node, as we always add elements at the beginning.]
    if(!topN)
    {
        cout << "stack underflow!\n";
        exit(1);
    }
    return topN->data;
}


int main()
{
    Stack<char> test;

    int i = 0;
    while (i < 50)
    {
        test.push('a' + i);
        ++i;
    }

    while (!test.isEmpty())
    {
        cout << test.top() << " ";
        test.pop();
    }
    cout << endl;

    Stack<int> test_2;
    i = 0;
    while (i < 20)
    {
        test_2.push(i * 2);
        ++i;
    }

    while (!test_2.isEmpty())
    {
        cout << test_2.top() << " ";
        test_2.pop();
    }
    cout << endl;
    Stack<double> test_3;
    i = 0;
    while (i < 5)
    {
        test_3.push(i * .1);
        ++i;
    }

    while (!test_3.isEmpty())
    {
        cout << test_3.top() << " ";
        test_3.pop();
    }
    cout << endl;
    
    return 0;
}
