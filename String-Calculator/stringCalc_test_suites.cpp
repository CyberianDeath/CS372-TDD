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
    SECTION( "Add - passed single value" )
    {
        {
            auto answ = Add("2");
            INFO("Add returned " << answ << "instead of 2");
            REQUIRE(2 == answ);
        }
        {
            auto answ = Add("2.0");
            INFO("Add returned " << answ << "instead of 2");
            REQUIRE(2 == answ);
        }
    }
}
