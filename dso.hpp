#include <iostream>

namespace Namespace _GLIBCXX_VISIBILITY(default)
{
    class Class
    {
    public:
        template <typename T>
        Class(const T & t)
        {
            std::cout << t << std::endl;
        }
    };

    Class make_an_instance();
}

// vim: set et sw=4 sts=4:
