#include "stringCalc.h"
#define CATCH_CONFIG_FAST_COMPILE
#include "catch.hpp"

TEST_CASE( "Function return types are correct",
           "[types]" )
{
    int throw_stat;  // 0: no throw, 1: throw, 2: throw other

    SECTION( "lookup returns value type by value" )
    {
        LLNode<int> * headi = nullptr;
        headi = new LLNode<int>(1, headi);
        try
        {
            [[maybe_unused]] int && ii(lookup(headi, 0));
            throw_stat = 0;
        }
        catch (...)
        {
            throw_stat = 1;
        }

        {
        INFO( "lookup does not throw" );
        REQUIRE( throw_stat == 0 );
        }
        {
        INFO( "lookup returns int" );
        REQUIRE( TypeCheck<int>::check(lookup(headi, 0)) );
        }

        LLNode<double> * headd = nullptr;
        headd = new LLNode<double>(1.1, headd);
        try
        {
            [[maybe_unused]] double && dd(lookup(headd, 0));
            throw_stat = 0;
        }
        catch (...)
        {
            throw_stat = 1;
        }

        {
        INFO( "lookup does not throw" );
        REQUIRE( throw_stat == 0 );
        }
        {
        INFO( "lookup returns double" );
        REQUIRE( TypeCheck<double>::check(lookup(headd, 0)) );
        }
    }

    SECTION( "checkSorted returns bool by value" )
    {
        vector<string> v { "abc", "def", "xyz" };
        [[maybe_unused]] bool && bb(checkSorted(v.begin(), v.end()));
        INFO( "checkSorted must return bool" );
        REQUIRE( TypeCheck<bool>::check(checkSorted(v.begin(), v.end())) );
    }

    SECTION( "gcd returns int by value" )
    {
        [[maybe_unused]] int && i(gcd(2,3));
        INFO( "gcd returns int by value" );
        REQUIRE( TypeCheck<int>::check(gcd(2,3)) );
    }
}
