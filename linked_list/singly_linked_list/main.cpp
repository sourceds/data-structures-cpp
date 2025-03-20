#include "singly_linked_list.hpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    LinkedList<string> ll;
    string str;
    for (int64_t i = 1; i < 5; ++i)
    {
        cin >> str;
        ll.insert(str);
    }
    ll.print();
    return 0;
}