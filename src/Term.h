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
                                        Term(Cell *, const std::string& name, Direction);
                                        Term(Instance*, const Term * modelterm);
        // DTOR
                                        ~Term();
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
                        Cell *          getOwnerCell() const;   // return the cell that contains the term
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
    
    Term::Term(Cell *, const std::string& name, Direction)
    {
        
    }
    Term::Term(Instance*, const Term * modelterm)
    {

    }
    Term::~Term()
    {

    }

    inline Node* Term::getNode(){ return &node_;}

}
#endif // NETLIST_TERM_H
