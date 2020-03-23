#include "stringCalc.h"
#define CATCH_CONFIG_FAST_COMPILE
#include "catch.hpp"

TEST_CASE( "Function return types are correct")
{

    SECTION( "Add - passed empty string" )
    {
        {
            INFO("Add should return zero when passed empty string");
            REQUIRE(0 == Add(""));
        }
    }
}
