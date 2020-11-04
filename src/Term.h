#ifndef NETLIST_TERM_H
#define NETLIST_TERM_H

#include<string>
#include"Cell.h"
#include"Node.h"

namespace Netlist{
    class Term
    {
    public:
        //enum
        enum Type { Internal = 1, External = 2};
        enum Direction { In = 1, Out = 2, InOut = 3, Tristate = 4, Transcv = 5, Unknown = 6}; 
        // CTOR
        inline                          Term(Cell *, const std::string& name, Direction);
        inline                          Term(Instance*, const Term * modelterm);
        // DTOR
        inline                          ~Term();
        // Utility
        static          std::string     toString(Type);
        static          std::string     toString(Direction);
        static          Direction       toDirection(std::string);
        // Accessors
        inline          bool            isInternal  () const;
        inline          bool            isExternal  () const;
        inline const    std::string&    getName     () const;
        inline          Node *          getNode     ();
        inline          Net *           getNet      () const;
        inline          Cell *          getCell     () const;   // return owner of the term
                        Cell *          getOwnerCell() const;   // TODO return the cell that contains the term
        inline          Instance *      getInstance () const;   // return owner of the term
        inline          Direction       getDirection() const;
        inline          Point           getPosition () const;
        inline          Type            getType     () const;
        // Mutators
                        void            setNet      (Net*);
                        void            setNet      (const std::string&);
        inline          void            setDirection(Direction);
                        void            setPosition (const Point&);
                        void            setPosition (int x, int y);
    private:
        void *          owner_;
        std::string     name_;
        Direction       direction_;
        Type            type_;
        Net*            net_;
        Node            node_;

    };
    
    inline Term::Term(Cell *, const std::string& name, Direction)
        : name_(name), node_(this)
    {
        
    }
    inline Term::Term(Instance* inst, const Term * modelterm)
        : owner_(static_cast<void*>(inst)), node_(this) // TODO use modelterm
    {

    }
    inline Term::~Term()
    {

    }

    inline bool Term::isInternal() const {return (type_ == 1 ? 1 : 0);}
    
    inline bool Term::isExternal() const {return (type_ == 2 ? 1 : 0);}
    
    inline const std::string& Term::getName() const {return name_;}
    
    inline Node* Term::getNode(){ return &node_;}
    
    inline Net* Term::getNet() const {return net_;}
    
    inline Cell* Term::getCell() const {return (type_== Internal ? static_cast<Cell*>(owner_) : NULL);}
    
    inline Instance* Term::getInstance() const {return (type_ == External ? static_cast<Instance*>(owner_) : NULL);}
    
    inline Term::Direction Term::getDirection() const {return direction_;}
    
    inline Point Term::getPosition() const {return node_.getPosition();}
    
    inline Term::Type Term::getType() const {return type_;}

}
#endif // NETLIST_TERM_H
