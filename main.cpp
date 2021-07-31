#include <iostream>
#include <string>

struct T
{
    T(int v , const char* n) : value(v), name(n) {}
    int value; //2
    std::string name; //3
};

struct CompareFunctionStruct
{
    T* compare(T &a, T &b) //5    
    {
        {
            if( a.value < b.value ) return &a; 
            if( a.value > b.value ) return &b;
        }
       return nullptr; 
    }
};

struct U
{
    float  uValue1 { 0 }, uValue2 { 0 };
    float shrinkTheGap(float& updatedValue)      //12
    {
        {
            std::cout << "U's uValue1 value: " << uValue1 << std::endl;
            uValue1 = updatedValue;
            std::cout << "U's uValue1 updated value: " << uValue1 << std::endl;
            while( std::abs(uValue2 - uValue1) > 0.001f )
            {
                uValue2 += 0.1f;
            }
            std::cout << "U's uValue2 updated value: " << uValue2 << std::endl;
            return uValue2 * uValue1;
        }
    }
};

struct UFunction
{
    static float shrinkTheGap(U& that, float& updatedValue )        //10
    {
        {
            std::cout << "U's uValue1 value: " << that.uValue1 << std::endl;
            that.uValue1 = updatedValue;
            std::cout << "U's uValue1 updated value: " << that.uValue1 << std::endl;
            while( std::abs(that.uValue2 - that.uValue1) > 0.001f )
            {
                that.uValue2 += 0.1f;
            }
            std::cout << "U's uValue2 updated value: " << that.uValue2 << std::endl;
            return that.uValue2 * that.uValue1; //this is the return value printed out in main.
        }
    }
};

int main()
{
    T tInstance1( 10, "Ta" ); //6
    T tInstance2( 2, "Tb" );  //6

    CompareFunctionStruct f;  //7
    auto smaller = f.compare( tInstance1, tInstance2 );       //8
    if (smaller != nullptr) 
    {
        std::cout << "the smaller one is << "  << smaller->name << std::endl; //9
    }

    U uInstance1;
    float updatedValue = 5.f;
    std::cout << "[static func] uInstance1's multiplied values: " << UFunction::shrinkTheGap( uInstance1, updatedValue ) << std::endl;  //11

    U uInstance2;
    std::cout << "[member func] uInstance2's multiplied values: " << uInstance2.shrinkTheGap( updatedValue ) << std::endl;
}
