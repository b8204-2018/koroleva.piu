#include "catch.hpp"
#include "rpn_lib.h"

TEST_CASE("Reader", "[reader]") {
    SECTION("Create") {
        Reader *one = Reader::create("testinput.txt");
        REQUIRE(one != nullptr);
        Reader *two = Reader::create("testinput.txt");
        REQUIRE(one != two);
        Reader *three = Reader::create("jsgkjh");
        REQUIRE(three == nullptr);

    }
    SECTION("Read") {
        Reader *r = Reader::create("testinput.txt");
        string one = r->readLine();
        //REQUIRE(one == "2+2");
        //one = r->readLine();
        //REQUIRE(one == "5+5");
    }
}
