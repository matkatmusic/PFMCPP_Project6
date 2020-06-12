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
    int value;
    std::string name;
    
    T(int v, const char* s) : value(v),name(s) {}  //1
};

struct X                                //4
{
    const T* compare(const T& a, const T& b) //5
    {
        if(a.value < b.value) return &a;
        if(a.value > b.value) return &b;
        return nullptr;
    }
};

struct U
{
    float x { 0 }, y { 0 };
    float multiply(const float& updatedValue)      //12
    {
        std::cout << "U's x value: " << this->x << std::endl;
        this->x = updatedValue;
        std::cout << "U's x updated value: " << this->x << std::endl;
        while( std::abs(this->y - this->x) > 0.001f )
        {
            /*
            write something that makes the distance between that->x and that->y get smaller
            */
            this->y += 0.1f;
        }
        std::cout << "U's y updated value: " << this->y << std::endl;
        return this->y * this->x;
    }
};

struct Z
{
    static float multiply(U& that, const float& updatedValue )        //10
    {
        std::cout << "U's x value: " << that.x << std::endl;
        that.x = updatedValue;
        std::cout << "U's x updated value: " << that.x << std::endl;
        while( std::abs(that.y - that.x) > 0.001f )
        {
            /*
            write something that makes the distance between that->x and that->y get smaller
            */
            that.y += 0.1f;
        }
        std::cout << "U's y updated value: " << that.y << std::endl;
        
        return that.y * that.x;
    }
};
        
int main()
{
    T t1(1 , "David"); //6
    T t2(2 , "Alexander"); //6
    
    X f; //7
    auto* smaller = f.compare(t1 , t2); //8

    if (smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    } 
    else 
    {
        std::cout << "t1 equals t2 OR EITHER OF THE 2 ARGUMENTS ARE NULL" << std::endl;
    }
    
    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << Z::multiply(u1 , updatedValue) << std::endl; //11
    
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.multiply( updatedValue ) << std::endl;
}
