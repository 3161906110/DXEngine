#include "runtime/core/meta/meta_example.h"

namespace MGame
{
    void metaExample()
    {
        Test1 test1_in;
        test1_in.m_int  = 12;
        test1_in.m_char = 'g';
        int i           = 1;
        test1_in.m_int_vector.emplace_back(&i);

    }
} 
