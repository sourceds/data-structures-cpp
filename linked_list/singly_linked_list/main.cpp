#include "s_linked_list.hpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    s_linked_list<int64_t> ll;
    for (int64_t i = 1; i < 31; ++i)
    {
        ll.insert(i);
    }
    ll.print();
    return 0;
}