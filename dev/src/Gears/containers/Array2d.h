#pragma once
#include "stdafx.h"

namespace Gears
{
    template <class T>
    class Array2d : public ::Claw::RefCounter
    {
    public:
        Array2d();
        Array2d( int w, int h );
        void SetSize( int w, int h );
        std::vector<T>& operator[] ( const int x );

    private:

    private:
        size_t m_width;
        size_t m_height;

        std::vector< std::vector<T> > m_data;
    };

#include "Array2d.inl"
}

