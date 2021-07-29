/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if you can convert a pointer to a reference in this project. Think carefully when making your changes.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>

//comments are me trying to make sense of what is going on in the example
struct T
{
    T(int v , const char* n) : value(v), name(n) {} //1  Constructor initialises member variables to value of parameters. question, why const char not std::string?
    int value; //2
    std::string name; //3
};

struct compareFunctionStruct  FIXME: type names must begin with a capital letter
{
    T* compare(T* a, T* b) //5    function that takes pointers (to two instances of T) as parameters. T* is the RETURN type of the function. 
    {
        if (a != nullptr && b != nullptr) //check pointers are not null before using
        {
            if( a->value < b->value ) return a; // function compares values of member variables of a and b
            if( a->value > b->value ) return b;
        }
        return nullptr; // if  neither condition is met, function returns nullptr (does this protect against the function allocating junk to memory?)
    }
};


struct U
{
    float  uValue1 { 0 }, uValue2 { 0 };
    float shrinkTheGap(float* updatedValue)      //12
    {
        if (updatedValue != nullptr)
        {
            std::cout << "U's uValue1 value: " << uValue1 << std::endl;
            uValue1 = *updatedValue;
            std::cout << "U's uValue1 updated value: " << uValue1 << std::endl;
            while( std::abs(uValue2 - uValue1) > 0.001f )
            {
                uValue2 += 0.1f;
            }
            std::cout << "U's uValue2 updated value: " << uValue2 << std::endl;
            return uValue2 * uValue1;
        }
        return 0.f;
    }
};

struct uFunction FIXME: type names must begin with a capital letter
{
    static float shrinkTheGap(U* that, float* updatedValue )        //10
    {
        if (that != nullptr && updatedValue != nullptr)
        {
            std::cout << "U's uValue1 value: " << that->uValue1 << std::endl;
            that->uValue1 = *updatedValue;
            std::cout << "U's uValue1 updated value: " << that->uValue1 << std::endl;
            while( std::abs(that->uValue2 - that->uValue1) > 0.001f )
            {
                that->uValue2 += 0.1f;
            }
            std::cout << "U's uValue2 updated value: " << that->uValue2 << std::endl;
            return that->uValue2 * that->uValue1; //this is the return value printed out in main.
        }
        return 0.f;
    }
};

int main()
{
    T tInstance1( 10, "Ta" ); //6
    T tInstance2( 2, "Tb" );  //6

    compareFunctionStruct f;  //7
    auto* smaller = f.compare( &tInstance1, &tInstance2 );       //8
    if (smaller != nullptr) //if statement only operates if return value of f.compare is valid
    {
        std::cout << "the smaller one is << "  << smaller->name << std::endl; //9
    }

    U uInstance1;
    float updatedValue = 5.f;
    std::cout << "[static func] uInstance1's multiplied values: " << uFunction::shrinkTheGap( &uInstance1, &updatedValue ) << std::endl;  //11

    U uInstance2;
    std::cout << "[member func] uInstance2's multiplied values: " << uInstance2.shrinkTheGap( &updatedValue ) << std::endl;
}

        
        
        
        
        
        
        
