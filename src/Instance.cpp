#include "Instance.h"
#include "Term.h"
#include "Net.h"
namespace Netlist
{
    bool Instance::connect(const std::string& name, Net * net){
        Term * target = getTerm(name);
        if(target == NULL) return false;
        target->setNet(net);
        return true;
    }

    void Instance::add(Term * toadd){
        terms_.push_back(toadd);
    }

    void Instance::remove(Term * toremove){
        for(std::vector<Term*>::iterator it= terms_.begin(); it != terms_.end(); ++it){
            if(*it == toremove) terms_.erase(it);
        }
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
