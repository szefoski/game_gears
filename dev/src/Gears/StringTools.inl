//
//  kStringTools.inl
//  Kodo - 2.5d graphics engine
//
//  Created by Daniel Zielas on 18/2/2012.
//  Copyright Daniel Zielas. All rights reserved.
//
#ifdef CLAW_N3DS
#include <nn/types.h>
#endif

namespace Gears
{
    inline std::wstring& StringTools::ToWString(std::wstring& output, const std::wstring& val)
    {
        return output = val;
    }

    inline std::wstring& StringTools::ToWString(std::wstring& output, int val)
    {
        char buffer[50];
        sprintf(buffer, "%i", val);
        return ToWString(output, std::string(buffer));
    }


    inline std::wstring& StringTools::ToWString(std::wstring& output, const std::string& val)
    {
        switch (g_stringToWStringConvert)
        {
        case 0:
            {
                std::wstringstream g_converter;
                g_converter.str(std::wstring());
                output.resize(val.length(),L' ');
                std::copy(val.begin(), val.end(), output.begin());
                return output;
            }
        case 1:
            output.assign(val.begin(), val.end());
            return output;
        case 2:
            {
                std::vector<wchar_t> dest(val.size());
                int i = mbstowcs(&dest[0], val.c_str(), val.size());
                output.assign(&dest[0]);
                return output;
            }
        default:
            CLAW_ASSERT(false);
            return output = std::wstring(L" _ERROR_ ");
        }
    }


    inline std::wstring StringTools::ToWString(int val)
    {
        std::wstring output;
        ToWString(output, val);
        return output;
    }

    inline std::wstring StringTools::ToWString(const std::wstring& val)
    {
        return val;
    }


    inline std::wstring StringTools::ToWString(const std::string& val)
    {
        std::wstring output;
        ToWString(output, val);
        return output;
    }


    template <typename T>
    inline std::wstring StringTools::Replace(const std::wstring& in, const std::wstring& key, const T& value)
    {
        std::wstring inOut(in);
        ReplaceRef(inOut, key, value);
        return inOut;
    }


    template <typename T>
    inline void StringTools::ReplaceRef(std::wstring& inOut, const std::wstring& key, const T& value)
    {
        ReplaceRef(inOut, key, ToWString(value));
    }


    template <>
    inline void StringTools::ReplaceRef(std::wstring& inOut, const std::wstring& key, const std::wstring& value)
    {
        switch (g_replaceTag)
        {
        case 0:
            {
                size_t pos = inOut.find(key);
                if (pos != std::wstring::npos)
                {
                    size_t size = key.size();
                    inOut.replace(pos, size, value);
                }
            }
            return;
        case 1:
            {
                std::vector<std::wstring> out;
                Split( inOut, key, out );

                inOut = out[0] + value;

                if ( out.size() >= 2 )
                {
                    inOut += out[1];
                }
            }
            return;
        default:
            CLAW_ASSERT(false);
            break;
        }
        
    }


    template <typename T1>
    inline std::wstring StringTools::Sprintf(const std::wstring& in, const T1& val_1)
    {
        std::wstring inOut(in);
        SprintfRef(inOut, val_1);
        return inOut;
    }


    template <typename T1, typename T2>
    inline std::wstring StringTools::Sprintf(const std::wstring& in, const T1& val_1, const T2& val_2)
    {
        std::wstring inOut(in);
        SprintfRef(inOut, val_1, val_2);
        return inOut;
    }


    template <typename T1, typename T2, typename T3>
    inline std::wstring StringTools::Sprintf(const std::wstring& in, const T1& val_1, const T2& val_2, const T3& val_3)
    {
        std::wstring inOut(in);
        SprintfRef(inOut, val_1, val_2, val_3);
        return inOut;
    }


    template <typename T1, typename T2, typename T3, typename T4>
    inline std::wstring StringTools::Sprintf(const std::wstring& in, const T1& val_1, const T2& val_2, const T3& val_3,
        const T4& val_4)
    {
        std::wstring inOut(in);
        SprintfRef(inOut, val_1, val_2, val_3, val_4);
        return inOut;
    }


    template <typename T1, typename T2, typename T3, typename T4, typename T5>
    inline std::wstring StringTools::Sprintf(const std::wstring& in, const T1& val_1, const T2& val_2, const T3& val_3,
        const T4& val_4, const T5& val_5)
    {
        std::wstring inOut(in);
        SprintfRef(inOut, val_1, val_2, val_3, val_4, val_5);
        return inOut;
    }


    template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    inline std::wstring StringTools::Sprintf(const std::wstring& in, const T1& val_1, const T2& val_2, const T3& val_3,
        const T4& val_4, const T5& val_5, const T6& val_6)
    {
        std::wstring inOut(in);
        SprintfRef(inOut, val_1, val_2, val_3, val_4, val_5, val_6);
        return inOut;
    }


    template <typename T1>
    inline void StringTools::SprintfRef(std::wstring& inOut, const T1& val_1)
    {
        static std::wstring key1(L"@1@");
        ReplaceRef(inOut, key1, val_1);
    }


    template <typename T1, typename T2>
    inline void StringTools::SprintfRef(std::wstring& inOut, const T1& val_1, const T2& val_2)
    {
        static std::wstring key2(L"@2@");

        SprintfRef(inOut, val_1);
        ReplaceRef(inOut, key2, val_2);
    }


    template <typename T1, typename T2, typename T3>
    inline void StringTools::SprintfRef(std::wstring& inOut, const T1& val_1, const T2& val_2, const T3& val_3)
    {
        static std::wstring key3(L"@3@");

        SprintfRef(inOut, val_1, val_2);
        ReplaceRef(inOut, key3, val_3);
    }


    template <typename T1, typename T2, typename T3, typename T4>
    inline void StringTools::SprintfRef(std::wstring& inOut, const T1& val_1, const T2& val_2, const T3& val_3,
        const T4& val_4)
    {
        static std::wstring key4(L"@4@");

        SprintfRef(inOut, val_1, val_2, val_3);
        ReplaceRef(inOut, key4, val_4);
    }


    template <typename T1, typename T2, typename T3, typename T4, typename T5>
    inline void StringTools::SprintfRef(std::wstring& inOut, const T1& val_1, const T2& val_2, const T3& val_3,
        const T4& val_4, const T5& val_5)
    {
        static std::wstring key5(L"@5@");

        SprintfRef(inOut, val_1, val_2, val_3, val_4);
        ReplaceRef(inOut, key5, val_5);
    }


    template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    inline void StringTools::SprintfRef(std::wstring& inOut, const T1& val_1, const T2& val_2, const T3& val_3,
        const T4& val_4, const T5& val_5, const T6& val_6)
    {
        static std::wstring key6(L"@6@");

        SprintfRef(inOut, val_1, val_2, val_3, val_4, val_5);
        ReplaceRef(inOut, key6, val_6);
    }


    inline void StringTools::Split(const std::wstring& str, char c, std::vector<std::wstring>& out)
    {
        out.clear();
        size_t begin =0;
        size_t end = 0;

        while ((end = str.find(c, begin)) != std::wstring::npos )
        {
            out.push_back( str.substr(begin,end - begin) );
            begin = end+1;
        }

        if (begin<str.size())
        {
            out.push_back( str.substr(begin, str.size()-begin) );
        }
    }


    inline void StringTools::Split(const std::wstring& str, wchar_t c, std::vector<std::wstring>& out)
    {
        out.clear();
        size_t begin =0;
        size_t end = 0;

        while ((end = str.find(c, begin)) != std::wstring::npos )
        {
            out.push_back( str.substr(begin,end - begin) );
            begin = end+1;
        }

        if (begin<str.size())
        {
            out.push_back( str.substr(begin, str.size()-begin) );
        }
    }


    inline void StringTools::Split(const std::wstring& str, const std::wstring& c, std::vector<std::wstring>& out)
    {
        out.clear();
        size_t begin =0;
        size_t end = 0;

        while ((end = str.find(c, begin)) != std::wstring::npos )
        {
            out.push_back( str.substr(begin,end - begin) );
            begin = end+c.size();
        }

        if (begin<str.size())
        {
            out.push_back( str.substr(begin, str.size()-begin) );
        }
    }
}
