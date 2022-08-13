#define DEBUG 1
#include <iostream>
#include <string>

/* Base Class for Progression classes ---------------------------------- */
class Progression {
public:
    Progression(int first=0); /* constructor */
    virtual ~Progression(); /* destructor */
    /* virtual destructor
     * when need to potentially delete an instance of a derived class through a pointer to this base class
     * Read: static_binding vs dynamic_binding (virtual functions)
     */
    void print_progression(int nelements); /* public method */

protected:
    std::string type;
    int first;   
    int next;
    virtual int get_next() = 0;
    /* 
     * virtual: can be redefined in derived classes
     * virtual func() = 0 ==> Pure Virtual func: must be redefined in derived classes
     */ 
};

Progression::Progression(int first)
{
#if DEBUG
    std::cout << "Progression::constructor invoked\n";
#endif
    this->type = "Abstract Progression";
    this->first = first;
    this->next = this->first;
}

Progression::~Progression()
{
#if DEBUG
    std::cout << "Progression::destructor invoked\n";
#endif
}

void Progression::print_progression(int nelements)
{
    std::cout << this->type << "\n";
    for(int i=1; i<=nelements; i++)
        std::cout << get_next() << " ";
    std::cout << std::endl;
}




/* Arithmetic Progression ---------------------------------------------------------- */
class ArithmeticProgression : public Progression {
    /* derived from Progression class via public mode */
public:
    ArithmeticProgression(int step=1);
    virtual ~ArithmeticProgression();
protected:
    int get_next();
    int step;
};

ArithmeticProgression::ArithmeticProgression(int step) : Progression(1)
{
#if DEBUG
    std::cout << "Progression::ArithmeticProgression::constructor invoked\n";
#endif
    this->type = "Arithmetic Progression";
    this->step = step;
}

ArithmeticProgression::~ArithmeticProgression()
{
#if DEBUG
    std::cout << "Progression::ArithmeticProgression::destructor invoked\n";
#endif
}

int ArithmeticProgression::get_next()
{
    int save = next;
    next = next + step;
    return save;
}




/* Geometric Progression ------------------------------------------------------------- */
class GeometricProgression : public Progression {
    /* derived from Progression class via public mode */
public:
    GeometricProgression(int factor=1);
    virtual ~GeometricProgression();
protected:
    int get_next();
    int factor;
};

GeometricProgression::GeometricProgression(int factor) : Progression(1)  /* base constructor call */
{
#if DEBUG
    std::cout << "Progression::GeometricProgression::constructor invoked\n";
#endif
    this->type = "Geometric Progression";
    this->factor = factor;
}

GeometricProgression::~GeometricProgression()
{
#if DEBUG
    std::cout << "Progression::GeometricProgression::destructor invoked\n";
#endif
}

int GeometricProgression::get_next()
{
    int save = next;
    next = factor * next;
    return save;
}




/* Driver code --------------------------------------------------------------------------------------- */
void run_stack(int n)  /* process progressions with n elements */
{
    std::cout << "[Stack Memory Operations]\n";
    
    ArithmeticProgression AP(2);
    AP.print_progression(n);

    GeometricProgression GP(2);
    GP.print_progression(n);

    std::cout << std::endl;
}

void run_heap(int n) /* process progressions with n elements */
{
    std::cout << "[Heap Memory Operations]\n";

    Progression *p;
    /* ensure to release memory before re-assigning pointer */

    p = new ArithmeticProgression(2);
    p->print_progression(n);
    delete p;

    p = new GeometricProgression(2);
    p->print_progression(n);
    delete p;

    std::cout << std::endl;
}


int main()
{
    run_stack(10);
    run_heap(10);
    return EXIT_SUCCESS;
}
