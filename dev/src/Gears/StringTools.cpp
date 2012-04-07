//
//  kStringTools.cpp
//  Kodo - 2.5d graphics engine
//
//  Created by Daniel Zielas on 18/2/2012.
//  Copyright Daniel Zielas. All rights reserved.
//
#include "stdafx.h"
#include "StringTools.h"

namespace Gears
{
    int StringTools::g_stringToWStringConvert = 0;
    int StringTools::g_replaceTag = 0;

    void StringTools::Initialize()
    {
        g_stringToWStringConvert = 0;
        g_replaceTag = 0;

        for ( g_stringToWStringConvert = 0; g_stringToWStringConvert < 3; g_stringToWStringConvert++ )
        {
            for ( g_replaceTag = 0; g_replaceTag < 2; g_replaceTag++ )
            {
                if ( UnitTest() )
                {
                    CLAW_MSG("StringTools SUCCED: " << g_stringToWStringConvert << "  " << g_replaceTag);
                    //return;
                }
            }
        }
        CLAW_MSG("StringTools FAIL");
        CLAW_ASSERT(false); // All options was fails
    }


    bool StringTools::UnitTest()
    {
        for (int i = 0; i < 3; i++)
        {
            std::wstring correctAnswerString(L"s1: aaaa, s2: bbbb, s3: cccc");
            std::wstring templateString(L"s1: @1@, s2: @2@, s3: @3@");
            std::wstring answerString = StringTools::Sprintf(templateString, "aaaa", "bbbb", "cccc");
            if ( correctAnswerString.compare(answerString) != 0 )
            {
                return false;
            }

            std::wstring correctAnswerInt(L"i1: 1111, i2: 2222, i3: 3333");
            std::wstring templateInt(L"i1: @1@, i2: @2@, i3: @3@");
            std::wstring answerInt = StringTools::Sprintf(templateInt, 1111, 2222, 3333);
            if ( correctAnswerInt.compare(answerInt) != 0 )
            {
                return false;
            }
        }

        return true;
    }
    //std::wstringstream StringTools::g_converter;
    //std::wstring StringTools::g_tempWStringContainer;
}
