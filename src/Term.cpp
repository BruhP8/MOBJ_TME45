#include "Term.h"

namespace Netlist
{
    Cell* Term::getOwnerCell() const{
        return static_cast<Cell*>(owner_);
    }

    void Term::setNet(Net* net){
        // TODO
    }

    void Term::setNet(const std::string& name){
        // TODO
    }

    void Term::setPosition(const Point& pt){
        node_.setPosition(pt);
    }

    void Term::setPosition(int x, int y){
        node_.setPosition(x, y);
    }
} // namespace Netlist

