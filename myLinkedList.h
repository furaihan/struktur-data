#include "iostream"
#include "node.h"
template <class T> class MyLinkedList
{
    Node<T> *ndas, *buntut;
    public:
    MyLinkedList()
    {
        ndas = NULL;
        buntut = NULL;
    }
    //encapsulation for head element
    Node<T> *First()
    {
        return ndas;
    }
    //encapsulation for tail element
    Node<T> *Last()
    {
        return buntut;
    }
    bool Empty()
    {
        return ndas == NULL;
    }
    int Count()
    {
        int counter = 0;
        return counter;
    }
    bool Contains(T item)
    {
        Node<T> *bantu = ndas;
        return false;
    }
    void AddLast(T item)
    {
        Node<T> *newNode = new Node<T>;
        newNode->data = item;
        if (Empty())
        {
            ndas = newNode;
        }
        else
        {
            buntut->next = newNode;
        }
        buntut = newNode;
        buntut->next = NULL;
    }
    void AddFirst(T item)
    {
        Node<T> *newNode = new Node<T>;
        newNode->data = item;
        if (Empty())
        {
            newNode->next = NULL;
            ndas = newNode;
            buntut = newNode;
            return;
        }
        newNode->next = ndas;
        ndas = newNode;
    }
    //insert a new node to nth position
    void Insert(T item, int n)
    {
        Node<T> *newNode = new Node<T>;
        newNode->data = item;
        newNode->next = NULL;
        if (n == 1)
        {
            newNode->next = ndas;
            ndas = newNode;
            return;
        } 
        Node<T> *temp2 = ndas;
        for (int i = 0; i < n - 2; i++)
        {
            temp2 = temp2->next;
        }
        bool isLastElement = temp2 == buntut;
        newNode->next = temp2->next;
        temp2->next = newNode;
        if (isLastElement) 
        {
            buntut = newNode;
            buntut->next = NULL;
        }
    }
    void RemoveFirst()
    {
        if (Empty())
        {
            return;
        }
        Node<T> *firstElem = ndas;
        ndas = ndas->next;
        delete firstElem;
    }
    void RemoveLast()
    {
        if (ndas == buntut)
        {
            ndas = NULL;
            buntut = NULL;
            return;
        }
        Node<T> *temp = ndas;
        Node<T> *del = buntut;
        while (temp->next != buntut)
        {
            temp = temp->next;
        }
        buntut = temp;
        buntut->next = NULL;
        delete del;
    }
    void RemoveAt(int index)
    {

    }
    void Clear()
    {
        Node<T> *bantu, * hapus;
        bantu = ndas;
        while (bantu->next != buntut)
        {
            hapus = bantu;
            bantu = bantu->next;
            delete hapus;
        }
        ndas = NULL;
        buntut = NULL;
        printf("All nodes are deleted successfully");
    }
    void PrintList()
    {
        Node<T> *bantu = ndas;
        int counter = 1;
        while (bantu != NULL)
        {
            std::cout << "Data pada node #" << counter++ << " = " << bantu->data << std::endl;
            bantu = bantu->next;
        }
        std::cout << std::endl;
    }
};