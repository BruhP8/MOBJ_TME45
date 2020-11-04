#ifndef NETLIST_NET_H
#define NETLIST_NET_H

#include<string>
#include<vector>
#include"Cell.h"
#include"Term.h"

namespace Netlist{
    class Net
    {
    private:
        Cell*               owner_;
        std::string         name_;
        unsigned int        id_;
        Term::Type          type_;
        std::vector<Node*>  nodes_;
    public:
        // CTOR
        inline                              Net(Cell *, const std::string&, Term::Type);
        // DTOR
        inline                              ~Net();
        // Accessors
        inline          Cell*               getCell       () const;
        inline const    std::string         getName       () const;
        inline          unsigned int        getId         () const;
        inline          Term::Type          getType       () const;
        inline const    std::vector<Node*>& getNodes_     () const;
        inline          size_t              getFreeNodeId () const;
        // Mutators
                        void                add           (Node*);
                        bool                remove        (Node*);
    };
    
    inline Net::Net(Cell*, const std::string&, Term::Type)
    {
    }
    
    inline Net::~Net()
    {
    }

    inline Cell* Net::getCell() const{ return owner_;}

    inline const std::string Net::getName() const{ return name_;}
    
    inline unsigned int Net::getId() const{ return id_;}

    inline Term::Type Net::getType () const{ return type_;}

    inline const std::vector<Node*>& Net::getNodes_() const { return nodes_;}

    inline size_t Net::getFreeNodeId () const{}
}
#endif // NETLIST_NET_H
