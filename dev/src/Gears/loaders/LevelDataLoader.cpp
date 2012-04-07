#include "stdafx.h"
#include "../LevelData.h"

#include "LevelDataLoader.h"

namespace Gears
{
    LevelDataPtr LevelDataLoader::Load( const char* file )
    {
        LevelDataPtr level( new LevelData() );

        level->m_data.SetSize( 50, 50 );

        level->m_data[1][1] = 1;

        return level;
    }
}
