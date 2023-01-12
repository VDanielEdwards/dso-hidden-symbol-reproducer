#include <system_error>

namespace Detail
{
    enum struct Errc
    {
        BadLuck = 1,
        VeryBadLuck = 2,
    };

    std::error_code make_error_code(Errc errc);

    std::error_code ReallyDoSomething();
}

namespace std
{
    template <>
    struct is_error_code_enum<Detail::Errc> : true_type {};
}

// vim: set et sw=4 sts=4:
