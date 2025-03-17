#include <iostream>

#ifndef LINKED_LIST
#define LINKED_LIST
typedef int32_t length_t;

template <typename T>
class Node
{
private:
    T data;
    Node<T>* link;
public:
    Node()
    {

    }
    Node(T _data)
    {
        data = _data;
    }
    Node(T _data, Node<T>* _link)
    {
        data = _data;
        link = _link;
    }
    ~Node()
    {

    }
    void set_data(T _data)
    {
        data = _data;
        return;
    }
    void set_link(Node<T>* _link)
    {
        link = _link;
        return;
    }
    T get_data()
    {
        return data;
    }
    Node<T>* get_link()
    {
        return link;
    }
};

template <typename T>
class LinkedList
{
private:
    Node<T>* head;
    length_t len = 0;
public:
    LinkedList()
    {
        head = new Node<T>;
        len = 0;
    }
    LinkedList(T data)
    {
        head = new Node<T>(data, NULL);
        len = 1;
    }
    ~LinkedList()
    {
        Node<T>* iter = head;
        Node<T>* temp;
        while (iter != NULL)
        {
            temp = iter;
            iter = iter->get_link();
            delete temp;
        }
    }
    void insert(T data)
    {
        if (len == 0)
        {
            head->set_data(data);
            len++;
        }
        else
        {
            //iterate
            Node<T>* iter = head;
            while (iter->get_link() != NULL)
            {
                iter = iter->get_link();
            }
            Node<T>* new_node = new Node<T>(data, NULL);
            iter->set_link(new_node);
            len++;
        }
    }
    void remove(length_t index)
    {
        if (index < 0)
        {
            return;
        }
        if (index >= len)
        {
            return;
        }

        if (index == 0)
        {
            Node<T>* temp = head;
            head = temp->get_link();
            delete temp;
            return;
        }

        Node<T>* iter = head;
        Node<T>* prev = head;
        for (int i = 0; i < index; ++i)
        {
            prev = iter;
            iter = iter->get_link();
        }
        prev->set_link(iter->get_link());
        delete iter;
        return;
    }
    bool find(T data)
    {
        Node<T>* iter = head;
        bool find_flag = false;
        while (iter != NULL)
        {
            if (iter->get_data() == data)
            {
                find_flag = true;
                break;
            }
            iter = iter->get_link();
        }
        return find_flag;
    }
    void print()
    {
        Node<T>* iter = head;
        while (iter != NULL)
        {
            std::cout << iter->get_data() << " ";
            iter = iter->get_link();
        }
        std::cout << std::endl;
    }
    length_t length()
    {
        return len;
    }
    length_t size()
    {
        return len;
    }
    T* array()
    {
        T* arr = new T[sizeof(T)*len];
        Node<T>* iter = head;
        for (int i = 0; i < len; ++i)
        {
            arr[i] = iter->get_data();
            iter = iter->get_link();
        }
        return arr;
    }
};

#endif

