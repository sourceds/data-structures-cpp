#include "d_linked_list.hpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    d_linked_list<int64_t> ll;
    for (int64_t i = 1; i < 32; ++i)
    {
        ll.insert(i);
    }
    ll.print();
    
    return 0;
}