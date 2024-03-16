#pragma once

#include "IManageable.hpp"

namespace kf
{
    class IGuiComponent : public IManageable
    {
    public:
        virtual ~IGuiComponent() = default;
    };
}