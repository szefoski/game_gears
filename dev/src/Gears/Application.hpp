#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__

#include "claw/application/Application.hpp"

namespace Gears
{

    class GearsApplication : public Claw::Application
    {
    public:
        GearsApplication();
        ~GearsApplication();

        void OnStartup();
        void OnShutdown();

        void OnUpdate( const Claw::Real& dt );
        void OnRender( Claw::Surface* target );
        void OnKeyPress( Claw::KeyCode code );
        void OnKeyRelease( Claw::KeyCode code );
        void OnTouchDown( int x, int y, int button );
        void OnTouchUp( int x, int y, int button );
        void OnTouchMove( int x, int y, int button );
    };

}

#endif
