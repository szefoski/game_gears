#include "stdafx.h"
#include "Ingame.h"

#include "Gears/Application.hpp"

namespace Gears
{

    GearsApplication::GearsApplication()
    {
    }

    GearsApplication::~GearsApplication()
    {
    }

    void GearsApplication::OnStartup()
    {
        m_ingame.Reset( new Ingame() );
        StringTools::Initialize();
    }

    void GearsApplication::OnShutdown()
    {
    }

    void GearsApplication::OnUpdate( const Claw::Real& dt )
    {
        m_ingame->OnUpdate( dt );
    }

    void GearsApplication::OnRender( Claw::Surface* target )
    {
        m_ingame->OnRender( target );
    }

    void GearsApplication::OnKeyPress( Claw::KeyCode code )
    {
    }

    void GearsApplication::OnKeyRelease( Claw::KeyCode code )
    {
    }

    void GearsApplication::OnTouchDown( int x, int y, int button )
    {
    }

    void GearsApplication::OnTouchUp( int x, int y, int button )
    {
    }

    void GearsApplication::OnTouchMove( int x, int y, int button )
    {
    }
}

CLAW_DEFINE_APPLICATION( new Gears::GearsApplication, "Gears" );
