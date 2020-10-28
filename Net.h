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
                                            Net(Cell *, const std::string&, Term::Type);
        // DTOR
                                            ~Net();
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
    
    Net::Net(Cell*, const std::string&, Term::Type)
    {
    }
    
    Net::~Net()
    {
    }
    
}
#endif // NETLIST_NET_H
