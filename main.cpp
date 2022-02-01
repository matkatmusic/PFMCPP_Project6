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

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 */


#include <iostream>
#include <string>
struct T
{
    float value;
    std::string name;
    T(const float v, const char* ptr) :  //1
    value(v),//2
    name(ptr)//3
    {}
};

struct Comparer                                //4
{   
    T* compare(T* a, T* b) //5
    {
        if (a != nullptr && b != nullptr)
        {
            if( a->value < b->value )
            {
                return a;
            }
            if( a->value > b->value )
            {
                return b;
            }
        }

        return nullptr;
    }
};

struct U
{
    float x { 0 }, y { 0 };
    float bringTogether(float& updatedValue)      //12
    {
    
        std::cout << "U's x value: " << x << std::endl;
        x = updatedValue;
        std::cout << "U's x updated value: " << x << std::endl;
        std::cout << "bringing x and y together\n";
        while( std::abs(y - x) > 0.001f )
        {
            if (y < x)
            {
                y += .1f;
                x -= .1f;
            }
            else if(y > x)
            {
                y -= .1f;
                x += .1f;
            }
            else
            {
                std::cout << "x == y!\n";
            }
        }
        std::cout << "U's y updated value: " << y << std::endl;
        return y * x; 
    }
};

struct myType
{
    static float bringTogether(U& that, float& updatedValue )        //10
    {
        std::cout << "U's x value: " << that.x << std::endl;
        that.x = updatedValue;
        std::cout << "U's x updated value: " << that.x << std::endl;
        std::cout << "bringing x and y together\n";
        while( std::abs(that.y - that.x) > 0.001f )
        {
            if (that.y < that.x)
            {
                that.y += .1f;
                that.x -= .1f;
            }
            else if(that.y > that.x)
            {
                that.y -= .1f;
                that.x += .1f;
            }
            else
            {
                std::cout << "x == y!\n";
            }

        }

        std::cout << "U's y updated value: " << that.y << std::endl;
        return that.y * that.x;
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
    T tOne(33.3f, "tOne");                                             //6
    T tTwo(55.0f, "tTwo" );                                        //6
    


    Comparer f;                                          //7
    auto* smaller = f.compare(&tOne, &tTwo);                              //8
    //std::cout << "the smaller one is << " << (smaller != nullptr ? smaller->name : "smaller is nullptr!") << std::endl; //9
    if( smaller != nullptr )
    {
       std::cout << "the smaller one is " << smaller->name << std::endl; 
    }
    else
    {
        std::cout << "a and b have the same value.\n";
    }

    U myUOne;
    float updatedValue = 5.f;
    std::cout << "[static func] myUOne's multiplied values: " << myType::bringTogether( myUOne, updatedValue) << std::endl;                  //11
    U myUTwo;
    std::cout << "[member func] myUTwo's multiplied values: " << myUTwo.bringTogether( updatedValue ) << std::endl;
}
