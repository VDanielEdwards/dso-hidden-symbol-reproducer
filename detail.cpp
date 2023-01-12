#include "detail.hpp"

#include <string>
#include <system_error>

namespace Detail
{
    namespace
    {
        struct ErrcCategory : public std::error_category
        {
            const char * name() const noexcept override { return "ErrcCategory"; }
            std::string message(int ev) const override { return "Errc(" + std::to_string(ev) + ")"; }
        };

        const std::error_category & GetErrcCategory()
        {
            static ErrcCategory errc_category;
            return errc_category;
        }
    }

    std::error_code make_error_code(const Errc errc)
    {
        return std::error_code(static_cast<int>(errc), GetErrcCategory());
    }

    std::error_code ReallyDoSomething()
    {
        return Errc::VeryBadLuck;
    }
}

// vim: set et sw=4 sts=4:
