//
// Created by cvaz on 08/05/19.
//

#ifndef GLADIATORS_SENDABLE_H
#define GLADIATORS_SENDABLE_H

#include <algorithm>
#include <boost/property_tree/json_parser.hpp>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <string>
#include "Gladiator.h"
#include <string>
#include "LinkedList.h"

using namespace std;
using boost::property_tree::ptree;

class Sendable {
public:
    Sendable();
private:
    Gladiator glad1;
    Gladiator glad2;
    LinkedList<LinkedList<int>> movimientos; // 0000 : (xf)(yf)(xi)(yi)
    string mensaje;
};


#endif //GLADIATORS_SENDABLE_H
