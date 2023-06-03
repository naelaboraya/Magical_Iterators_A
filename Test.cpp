#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <stdexcept>

using namespace ariel;
using namespace std;
// Test case for adding elements to the MagicalContainer

//-------------------------------------------------------------------------------------------
TEST_CASE("Adding and re,oving elements to/from container"){
	MagicalContainer cont;
    //check if empty now 
    CHECK(cont.size()==0);
    cont.addElement(1);
    int a = 2;
    cont.addElement(a);
    CHECK(cont.size()==2);

	cont.removeElement(2);
    CHECK_THROWS_AS(cont.removeElement(5), runtime_error);
    CHECK(cont.size() == 1);
}

TEST_CASE("Asc iterator"){
    MagicalContainer container;
    container.addElement(5);
    container.addElement(4);
    container.addElement(3);
    container.addElement(2);
    container.addElement(1);

    MagicalContainer::AscendingIterator it(container);
    CHECK(it == it.begin());
    CHECK(*it == 1);
    ++it;
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 3);
    ++it;
    CHECK(*it == 4);
    ++it;
    CHECK(*it == 5);
    CHECK_FALSE(it == it.end());
    ++it;
    CHECK(it == it.end());
}

TEST_CASE("SideCross iterator"){
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);

    MagicalContainer::SideCrossIterator it(container);
    CHECK(it == it.begin());
    CHECK(*it == 1);
    ++it;
    CHECK(*it == 5);
    ++it;
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 4);
    ++it;
    CHECK(*it == 3);
    CHECK_FALSE(it == it.end());
    ++it;
    CHECK(it == it.end());
}

// Test case for the PrimeIterator
TEST_CASE("Prime iterator") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    container.addElement(6);

    
    MagicalContainer::PrimeIterator it(container);
    CHECK(it == it.begin());
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 3);
    ++it;
    CHECK(*it == 5);
    ++it;
    CHECK(it == it.end());

}
//--------------------------------------------------------------------------------------------

