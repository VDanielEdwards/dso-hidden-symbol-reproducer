#include "dso.hpp"
#include "detail.hpp"

#include <iostream>

namespace Namespace
{
    void DoSomething()
    {
        auto error_code = Detail::ReallyDoSomething();
        std::cout << "Error " << error_code << " from " << error_code.category().name() << '\n';
    }
}

// vim: set et sw=4 sts=4:
