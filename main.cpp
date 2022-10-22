#include "Header.h"
#include <vector>

using namespace std;

void insertAfter(vector<int>& v, int firstValue, int secondValue)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == firstValue)
        {
            v.insert(v.begin() + i + 1, secondValue);
        }
    }
}

Node::Node()
{
    number = 0;
    counter = 0;
    nxt = NULL;
}

Node::Node(int number)
{
    nxt = NULL;
    this->number = number;
    this->counter = 1;
}

Node::Node(int number, int counter)
{
    nxt = NULL;
    this->number = number;
    this->counter = counter;
}

LinkedList::LinkedList()
{
    head = tail = NULL;
}

void LinkedList::insert(int number, int counter)
{
    if (head == NULL)
    {
        head = tail = new Node(number, counter);
    }
    else
    {
        tail->nxt = new Node(number, counter);
        tail = tail->nxt;
    }
}

void LinkedList::print()
{
    Node* cur_node = head;

    while (cur_node != NULL)
    {
        cout << "(" << cur_node->number << ", " << cur_node->counter << ")" << endl;

        cur_node = cur_node->nxt;
    }

    cout << endl;
}

int LinkedList::getSum()
{
    int sum = 0;
    Node* cur_node = head;

    while (cur_node != NULL)
    {
        sum += cur_node->number;

        cur_node = cur_node->nxt;
    }

    return sum;
}

void LinkedList::remove(int x)
{
    if (head->number == x)
    {
        Node* tmp = head;
        head = head->nxt;
        delete tmp;
        return;
    }

    Node* cur_node = head;

    while (cur_node != NULL)
    {
        if (cur_node->nxt->number == x)
        {
            break;
        }
        else
        {
            cur_node = cur_node->nxt;
        }
    }

    Node* deletedNode = cur_node->nxt;

    Node* nxtNode = deletedNode->nxt;

    if (deletedNode == tail)
    {
        tail = cur_node;
    }

    delete deletedNode;

    cur_node->nxt = nxtNode;

    return;
}

LinkedList convertIntoLinkedList(vector<int> v)
{
    LinkedList list = LinkedList();

    int n = v.size();
    vector<bool> vis(1000, false);

    for (int i = 0; i < n; i++)
    {
        if (vis[v[i]] == true)
        {
            continue;
        }

        int counter = 0;

        for (int j = 0; j < n; j++)
        {
            if (v[i] == v[j])
            {
                counter++;
            }
        }

        list.insert(v[i], counter);
        vis[v[i]] = true;
    }

    return list;
}

int main()
{
    int n;
    cout << "Enter vector size : ";
    cin >> n;
    vector<int> v(n);

    cout << "Enter number of vector : ";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int firstValue, secondValue;
    cout << "Enter First Value : ";
    cin >> firstValue;

    cout << "Enter Second Value : ";
    cin >> secondValue;

    insertAfter(v, firstValue, secondValue);

    cout << "Vector after insertion : ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << endl;

    cout << "-------------------------------" << endl;
    cout << endl;

    // creat linked list
    LinkedList l = LinkedList();

    // Insert numbers into list (all occurrences = 1) (each element in list appears once)

    l.insert(2, 1);
    l.insert(5, 1);
    l.insert(7, 1);

    // print the linked list
    cout << "Current linked list" << endl;
    l.print();

    // get sum of number in the linked list
    cout << "Sum of number in linked list = " << l.getSum() << endl;
    cout << endl;

    // remove node contains number 7 from the linked list
    l.remove(7);

    // insert number 20 with 5 occurrences
    l.insert(20, 5);

    // print the number inside the linked list
    cout << "Current linked list" << endl;
    l.print();

    // get a linked list from a vector
    LinkedList list = convertIntoLinkedList({ 1, 4, 5, 4, 5, 1, 5 });

    // print the number inside the linked list
    cout << "Current linked list" << endl;
    list.print();

    return 0;
}