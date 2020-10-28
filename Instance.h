#ifndef NETLIST_INSTANCE_H
#define NETLIST_INSTANCE_H

#include<string>
#include<vector>
#include"Cell.h"
#include"Point.h"

namespace Netlist{
    class Instance
    {
    private:
        Cell*               owner_;
        Cell*               masterCell_;
        std::string         name_;
        std::vector<Term*>  terms_;
        Point               position_;
    public:
        // CTOR
                                            Instance(Cell* owner, Cell* model, const std::string&);
        // DTOR
                                            ~Instance();
        // Accessors
        inline const    std::string&        getName         () const;
        inline          Cell*               getMasterCell   () const;
        inline          Cell*               getCell         () const;
        inline const    std::vector<Term*>& getTerms        () const;
        inline          Term*               getTerm         (const std::string&) const;
        inline          Point               getPosition     () const;
        // Mutators
                        bool                connect         (const std::string& name, Net*);
                        void                add             (Term*);
                        void                remove          (Term*);
                        void                setPosition     (const Point&);
                        void                setPosition     (int x, int y);
    };
    
    Instance::Instance(Cell* owner, Cell* model, const std::string&)
    {
    }
    
    Instance::~Instance()
    {
    }
    
}
#endif // NETLIST_INSTANCE_H
