#include "MagicalContainer.hpp"
#include <iostream>
#include <algorithm>

using namespace std;
using namespace ariel;

void MagicalContainer::addElement(int number){
    this->_elems.push_back(number);
    if(isPrime(number)){
        this->prime_elems.push_back(number);
    }
    this->ascending_elems.push_back(number);
    std::sort(this->ascending_elems.begin(), this->ascending_elems.end());
    this->side_cross_elems.push_back(number);
    sidecrossSort(this->side_cross_elems);
}


void MagicalContainer::removeElement(int number) {
        auto it = std::find(this->_elems.begin(), this->_elems.end(), number);
        if (it != this->_elems.end()){
        this->_elems.erase(it);}
        else {
            throw std::runtime_error("zbve");
        }
}


MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container) : _container(container) , index(0){}
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container) : _container(container) , index(0){}
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container) : _container(container) , index(0){}
