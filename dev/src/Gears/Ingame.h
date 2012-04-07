#pragma once

namespace Gears
{
    class Ingame : public ::Claw::RefCounter
    {
    public:
        void OnUpdate( const Claw::Real& dt );
        void OnRender( Claw::Surface* target );
    };

    typedef ::Claw::SmartPtr< Ingame > IngamePtr;
}


