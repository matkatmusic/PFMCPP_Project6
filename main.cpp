/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char* c) : value(v), name(c) {}  //1
    int value; //2
    std::string name; //3
};

struct C                                //4
{
    T* compare(T& a, T& b) //5
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        return nullptr;
    }
};


struct U
{
    float a { 0 }, b { 0 };
    float updateMultiply(const float& updater)      //12
    {
        this->a = updater;
        std::cout << "U's a updated value: " << this->a << std::endl;
        while( std::abs(this->b - this->a) > 0.001f )
        {
            this->b += 1.0f;
        }
        std::cout << "U's b updated value: " << this->b << std::endl;
        return this->b * this->a;
    }
};


struct ModifyPointers
{
    static float updateMultiply(U& that, const float& updater)        //10
    {
        std::cout << "U's a value: " << that.a << std::endl;
        that.a = updater;
        std::cout << "U's a updated value: " << that.a << std::endl;
        while( std::abs(that.b - that.a) > 0.001f )
        {
            that.b += 1.0f;
        }
        std::cout << "U's b updated value: " << that.b << std::endl;
        return that.b * that.a;
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
    T a(1 , "a");                                             //6
    T b(2 , "b");                                             //6
    
    C f;                                            //7
    auto* smaller = f.compare(a , b);                              //8
    if(smaller == nullptr)
    {
        std::cout << "Values are equal";
    }
    else
    {
         std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }
    
    
    U u;
    float updatedValue = 5.f;
    std::cout << "[static func] u's multiplied values: " << ModifyPointers::updateMultiply(u , updatedValue) << std::endl;                  //11
    
    U u2;
    std::cout << "[member func] U2s multiplied values: " << u2.updateMultiply( updatedValue ) << std::endl;
}
