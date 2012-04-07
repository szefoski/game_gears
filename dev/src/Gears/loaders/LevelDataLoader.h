#pragma once

namespace Gears
{
    class LevelDataLoader : public ::Claw::RefCounter
    {
    public:
        LevelDataPtr Load(const char* file);
    };
}

