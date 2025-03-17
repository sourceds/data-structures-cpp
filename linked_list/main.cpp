#include "linked_list.hpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    LinkedList<string> ll;
    string str;
    for (int64_t i = 1; i < 7; ++i)
    {
        cin >> str;
        ll.insert(str);
    }
    ll.print();
    ll.remove(3);
    ll.print();
    return 0;
}