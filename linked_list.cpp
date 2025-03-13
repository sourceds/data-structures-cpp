#include <iostream>

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
};

int main()
{
    LinkedList<char> charlist;
    charlist.insert('c');
    charlist.insert('h');
    charlist.insert('a');
    charlist.print();
    std::cout << charlist.size() << " " << charlist.length();
    return 0;
}

