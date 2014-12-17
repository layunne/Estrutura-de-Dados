
#include "Node.h"
#include <QString>

// Binary tree abstract class
template <typename E> class BinTree {
public:

	// left menor
	// right maior
	
	
    BinTree() {}//Base constructor
    BinTree(Node<E>& sub){}//Constructor with sub tree
    //onde tem Node substituir pela classe de vocês caso nome seja diferente
    ~BinTree(){} // Base destructor

    virtual void add(const E& item) = 0;//add in tree
    
    virtual void remove(E item) = 0;//Remove item from the tree
    
    virtual void clear() = 0;//Clean tree
    
    virtual bool inTree(const E item) = 0;//checks if the tree is
    
    virtual const E lower() = 0;// return lower value
    
    virtual const E greater() = 0;//return higher value
    
    virtual QString toString() = 0;// print tree
    
    virtual int countNode() const = 0;//return number node
    
    virtual int countLevel() const = 0;//return number level
    
    virtual int countLeaf() const = 0;//return number leaf
    
    virtual int height() const = 0;//return size of tree
    
    virtual const Node<E> *getTree() = 0;// return root
    
    virtual void addSubTree(Node<E>*& node) = 0;//add sub tree
    
//    //onde tem Node substituir pela classe de você caso nome seja diferente
    
    virtual void toLeft() = 0; // Go left
    
    virtual void toRight() = 0;// Go right
    
    virtual const E getHere() const = 0;// Return value current node

};
