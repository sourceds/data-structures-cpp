#include <iostream>
#include <algorithm>

#ifndef D_LINKED_LIST
#define D_LINKED_LIST

typedef int32_t length_t;

template <typename T>
class Node
{
private:
    T data;
    Node<T>* prev;
    Node<T>* next;
public:
    Node()
    {

    }
    Node(T _data)
    {
        data = _data;
    }
    Node(T _data, Node<T>* _prev, Node<T>* _next)
    {
        data = _data;
        prev = _prev;
        next = _next;
    }
    ~Node()
    {

    }
    void set_data(T _data)
    {
        data = _data;
        return;
    }
    void set_prev(Node<T>* _prev)
    {
        prev = _prev;
        return;
    }
    void set_next(Node<T>* _next)
    {
        next = _next;
        return;
    }
    T get_data()
    {
        return data;
    }
    Node<T>* get_prev()
    {
        return prev;
    }
    Node<T>* get_next()
    {
        return next;
    }
};

// WIP

template <typename T>
class d_linked_list
{
private:
    Node<T>* head;
    Node<T>* tail;
    length_t len = 0;
public:
    d_linked_list()
    {
        head = new Node<T>(0, nullptr, nullptr); //sentinel node (head)
        tail = new Node<T>(0, nullptr, nullptr); //sentinel node (tail)
        len = 0;
    }
    d_linked_list(T data)
    {
        Node<T>* new_node = new Node<T>;
        head = new Node<T>(0, nullptr, new_node);
        tail = new Node<T>(0, new_node, nullptr);
        new_node->set_prev(head);
        new_node->set_next(tail);
        len = 1;
    }
    ~d_linked_list()
    {
        Node<T>* iter = head->get_next();
        while (iter != tail)
        {
            iter = iter->get_next();
            delete iter->get_prev();
        }
        delete head;
        delete tail;
    }
    void insert(T data)
    {
        if (len == 0)
        {
            Node<T>* new_node = new Node<T>(data, head, tail);
            head->set_next(new_node);
            tail->set_prev(new_node);
            len++;
        }
        else
        {
            Node<T>* new_node = new Node<T>(data, tail->get_prev(), tail);
            tail->get_prev()->set_next(new_node);
            tail->set_prev(new_node);
        }
    }
    /*
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
    */
    void print()
    {
        Node<T>* iter = head->get_next();
        while (iter != tail)
        {
            std::cout << iter->get_data() << " ";
            iter = iter->get_next();
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
    /*
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
    */
};

#endif


