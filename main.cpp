/*
 Project 6: Part 1 / 2
 Video: Chapter 3 Part 2

Create a branch named Part1

Purpose:  This project will show you the difference between member functions and static class functions, as well as the difference between pointers and references and the code semantics that accompany pointers and references.

 Pointers

 Please look at the screenshot in the files to see what happens if you paste this assignment into an existing cpp file in an xcode project
 
 Task: replace all of the <place holder> with proper names and types that will make this program compile and run.
 
 press the Compile, link and run... button and work your way through all of the error messages.
 

 steps:
 
 1) finish implementing the constructor for T. the constructor parameters need to initialize 2) and 3)
 
 2) provide a member variable in T of a type of your choosing that works with the compare function below T
         note the name of the variable used in the compare function
 
 3) provide a member variable of type std::string in T that works with the *first* cout statement in main().
         note the name of the variable used in the *first* cout statement in main()
 
 4) finish defining the struct with the compare function
 5) provide proper types for the arguments to compare, and a proper return value
         be sure to make it work with the pointer semantics being used in the if statements.
         see 8) for a hint about what type to use.
 
 6) finish instantiating the two T instances being declared in main(), based on the constructor you finished implementing in T
     Their names (line 105,106) are different than the member variables names (line 77), even tho the placeholders share the same name.
     Don't let this confuse you.
 
 7) Declare 'f' with the proper type so the call to f.compare works
 
 8) call f.compare() with the correct arguments, based on 2) and 5)
 
 9) correct the cout that uses smaller's member variable with some safe pointer usage.
         the possible return values of the compare() function should give you a hint.
 
 10) complete the implementation for the static function in <structName2>
 
 11) call the <structName2> static function correctly in main()
 
 12) replicate the functionality of <structName2>'s static function by implementing a member function in U that does the same thing.
 
 13) remember the rules for using pointers!  What is the one thing we always do before we use a pointer?
 
 After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
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

struct compareFunctionStruct  //4
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

struct uFunction
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

        
        
        
        
        
        
        
