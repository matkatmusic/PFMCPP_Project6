/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(float v, const char* name_) :
    value(v), 
    name(name_) {}
    float value;
    std::string name;
};

struct CompareStruct
{
    T* compare(T* a, T* b)
    {
        if(a != nullptr && b != nullptr)
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
        }
        return nullptr;
    }
};

struct U
{
    float f1 { 0 }, f2 { 0 };
    float memberFunc(float* updatedVal)
    {
        if(updatedVal != nullptr)
        {
            std::cout << "U's f1 value: " << f1 << std::endl;
            f1 = *updatedVal;
            std::cout << "U's f1 updated value: " << f1 << std::endl;
            while( std::abs(f2 - f1) > 0.001f )
            {
                f2 += 0.1f;
            }
            std::cout << "U's f2 updated value: " << f2 << std::endl;
            return f2 * f1;
        }
        return 0;
    }
};

struct StaticFuncStruct
{
    static float staticFunc(U* that, float* updatedVal )
    {
        if(that != nullptr && updatedVal != nullptr)
        {
            std::cout << "U's f1 value: " << that->f1 << std::endl;
            that->f1 = *updatedVal;
            std::cout << "U's f1 updated value: " << that->f1 << std::endl;
            while( std::abs(that->f2 - that->f1) > 0.001f )
            {
                that->f2 += 0.1f;
            }
            std::cout << "U's f2 updated value: " << that->f2 << std::endl;
            return that->f2 * that->f1;
        }
        return 0;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T t1( 1.2f, "t1");   
    T t2( -0.2f, "t2");  
    
    CompareStruct f;
    auto* smaller = f.compare(&t1, &t2);

    if(smaller != nullptr)
        std::cout << "the smaller one is << " << smaller->name << std::endl;
    else
        std::cout << t1.name << " and " << t2.name << " are equal.\n";
    
    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << StaticFuncStruct::staticFunc(&u1, &updatedValue) << std::endl;
    
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.memberFunc( &updatedValue ) << std::endl;
}

        
        
        
        
        
        
        
