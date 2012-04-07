//
//  kStringTools.h
//  Kodo - 2.5d graphics engine
//
//  Created by Daniel Zielas on 18/2/2012.
//  Copyright Daniel Zielas. All rights reserved.
//


#ifndef KODO_STRING_UTILS
#define KODO_STRING_UTILS

#include <sstream>
#include <string>
#include <iostream>

namespace Gears
{
    class StringTools
    {
    public:

        static void Initialize();

        static std::wstring& ToWString(std::wstring& output,  const std::wstring& val);
        static std::wstring& ToWString(std::wstring& output, int val);
        static std::wstring& ToWString(std::wstring& output, const std::string& val);

        static std::wstring ToWString(const std::wstring& val);
        static std::wstring ToWString(int val);
        static std::wstring ToWString(const std::string& val);

        template <typename T>
        static std::wstring Replace(const std::wstring& in, const std::wstring& key, const T& value);

        template <typename T>
        static void ReplaceRef(std::wstring& inOut, const std::wstring& key, const T& value);

        template <typename T1>
        static std::wstring Sprintf(const std::wstring& in, const T1& val_1);

        template <typename T1, typename T2>
        static std::wstring Sprintf(const std::wstring& in, const T1& val_1, const T2& val_2);

        template <typename T1, typename T2, typename T3>
        static std::wstring Sprintf(const std::wstring& in, const T1& val_1, const T2& val_2, const T3& val_3);

        template <typename T1, typename T2, typename T3, typename T4>
        static std::wstring Sprintf(const std::wstring& in, const T1& val_1, const T2& val_2, const T3& val_3,
            const T4& val_4);

        template <typename T1, typename T2, typename T3, typename T4, typename T5>
        static std::wstring Sprintf(const std::wstring& in, const T1& val_1, const T2& val_2, const T3& val_3,
             const T4& val_4, const T5& val_5);

        template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
        static std::wstring Sprintf(const std::wstring& in, const T1& val_1, const T2& val_2, const T3& val_3,
            const T4& val_4, const T5& val_5, const T6& val_6);

        template <typename T1>
        static void SprintfRef(std::wstring& inOut, const T1& val_1);

        template <typename T1, typename T2>
        static void SprintfRef(std::wstring& inOut, const T1& val_1, const T2& val_2);

        template <typename T1, typename T2, typename T3>
        static void SprintfRef(std::wstring& inOut, const T1& val_1, const T2& val_2, const T3& val_3);

        template <typename T1, typename T2, typename T3, typename T4>
        static void SprintfRef(std::wstring& inOut, const T1& val_1, const T2& val_2, const T3& val_3,
            const T4& val_4);

        template <typename T1, typename T2, typename T3, typename T4, typename T5>
        static void SprintfRef(std::wstring& inOut, const T1& val_1, const T2& val_2, const T3& val_3,
            const T4& val_4, const T5& val_5);

        template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
        static void SprintfRef(std::wstring& inOut, const T1& val_1, const T2& val_2, const T3& val_3,
            const T4& val_4, const T5& val_5, const T6& val_6);

        static void Split(const std::wstring& str, char c, std::vector<std::wstring>& out);
        static void Split(const std::wstring& str, wchar_t c, std::vector<std::wstring>& out);
        static void Split(const std::wstring& str, const std::wstring& c, std::vector<std::wstring>& out);

    private:
        static bool UnitTest();
    private:
        static int g_stringToWStringConvert;
        static int g_replaceTag;
        //static std::wstringstream g_converter;
        //static std::wstring g_tempWStringContainer;
    };
}

#include "StringTools.inl"


#endif

