/*
Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.
*/

// { Driver Code Starts
#include <iostream>
#include <stdio.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node *head1, struct Node *head2);

Node *inputList(int size)
{
    if (size == 0)
        return NULL;

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

/* Driver program to test above function*/
int main()
{
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node *head1 = inputList(n1);
        Node *head2 = inputList(n2);
        Node *common = inputList(n3);

        Node *temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node *head1, Node *head2)
{
    // Your Code Here
    Node *p = head1;
    Node *q = head2;

    if (p == NULL || q == NULL)
        return -1;

    int size1 = 0;
    while (p != NULL)
    {
        size1++;
        p = p->next;
    }

    int size2 = 0;
    while (q != NULL)
    {
        size2++;
        q = q->next;
    }

    p = head1;
    q = head2;
    int diff = abs(size1 - size2);

    if (size1 > size2)
    {
        while (diff > 0)
        {
            p = p->next;
            diff--;
        }
    }
    else if (size2 > size1)
    {
        while (diff > 0)
        {
            q = q->next;
            diff--;
        }
    }

    while (p->next != q->next && p->next && q->next)
    {
        p = p->next;
        q = q->next;
    }

    if (p->next == NULL || q->next == NULL)
        return -1;
    else if (p->next == q->next)
        return q->next->data;
}
