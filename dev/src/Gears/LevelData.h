#pragma once

#include "containers/Array2d.h"

namespace Gears
{
    class LevelData : public ::Claw::RefCounter
    {
    public:
        int width;
        int height;

        Array2d<int> m_data;
    };

    typedef ::Claw::SmartPtr< LevelData > LevelDataPtr;
}

