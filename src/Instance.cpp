#include "Instance.h"
#include "Term.h"
namespace Netlist
{
    bool Instance::connect(const std::string& name, Net * net){
        //TODO
    }

    void Instance::add(Term * toadd){
        //TODO
    }

    void Instance::remove(Term * toremove){
        //TODO
    }

    void Instance::setPosition(const Point& pos){
        position_ = pos;
    }

    void Instance::setPosition(int x, int y){
        position_.setX(x);
        position_.setY(y);
    }

    Term* Instance::getTerm(const std::string& name) const {
        for (Term* term : terms_){
            if (term->getName() == name){
                return term;
            }
        }
        return NULL; 
    }
} // namespace Netlist
