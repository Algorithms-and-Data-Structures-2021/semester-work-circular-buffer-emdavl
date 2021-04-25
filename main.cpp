#include <iostream>

#include "data_structure.hpp"

using namespace std;
using namespace itis;

int main() {
    Circular_buffer *cb = new Circular_buffer();
    cb->addBack(3);
    cb->addBack(3);
    cb->addBack(3);
    cb->addBack(3);
    cb->addBack(3);
    cb->addBack(3);
    cb->addBack(3);
    cout<<cb->getBack()<<endl;
    cout<<cb->getBack()<<endl;
    cout<<cb->getBack()<<endl;
    cout<<cb->getBack()<<endl;
    cout<<cb->getBack()<<endl;
    cout<<cb->getBack()<<endl;
    cout<<cb->getBack()<<endl;
    return 0;
}