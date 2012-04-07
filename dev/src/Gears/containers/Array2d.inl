
    template <class T>
    Array2d<T>::Array2d()
    {
        SetSize( 0, 0 );
    }


    template <class T>
    Array2d<T>::Array2d( int w, int h )
    {
        SetSize( w, h );
    }


    template <class T>
    void Array2d<T>::SetSize( int w, int h )
    {
        m_width = w;
        m_height = h;
        m_data.resize(w);

        for ( int x = 0; x < w; x++ )
        {
            m_data[x].resize(w);
        }
    }


    template <class T>
    std::vector<T>& Array2d<T>::operator[] ( const int x )
    {
        return m_data[x];
    }

