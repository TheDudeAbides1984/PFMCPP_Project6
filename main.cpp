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
    int value = 0; //2
    std::string name; //3

    T (int v, const char* newName) :
            value (v),
            name (newName)//1
    {

    }
};

struct TCompare                               //4
{
    T *compare (T* a, T* b) //5
    {
        if (a != nullptr && b != nullptr)
        {
            if (a->value < b->value) return a;
            if (a->value > b->value) return b;
        }
        return nullptr;
    }
};

struct U
{
    float f1 {0.f}, f2 {0.f};

    float mf1 (const float* f3)      //12
    {
        if (f3 == nullptr)
        {
            std::cout << "Can't perform operation on a null pointer" << std::endl;
            return 0.f;
        }
        std::cout << "U's f1 value: " << f1 << std::endl;
        this->f1 = *f3;
        std::cout << "U's f1 updated value: " << f1 << std::endl;

        while (std::abs (f2 - f1) > 0.001f)
        {
/*
 write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
 */
            if (f1 > f2)
            {
                f1 -= std::abs (f2 - f1) * .5f;
            }
            else
            {
                f2 += std::abs (f2 - f1);
            }
        }
        std::cout << "U's f1 updated value: " << f1 << std::endl;
        return f1 * f2;
    }
};

struct V
{
    static float staticFunctionA (U* that, const float* f3)        //10
    {
        if (that == nullptr || f3 == nullptr)
        {
            std::cout << "Can't perform operation on a null pointer" << std::endl;
            return 0.f;
        }
        std::cout << "U's f1 value: " << that->f1 << std::endl;
        that->f1 = *f3;
        std::cout << "U's f1 updated value: " << that->f1 << std::endl;

        while (std::abs (that->f2 - that->f1) > 0.001f)
        {
/*
 write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
 */
            if (that->f1 > that->f2)
            {
                that->f1 -= std::abs (that->f2 - that->f1) * .5f;
            }
            else
            {
                that->f2 += std::abs (that->f1 = that->f2);
            }
        }
        std::cout << "U's f2 updated value: " << that->f2 << std::endl;
        return that->f1 * that->f2;
    }
};

int main ()
{
    T t1 (5, "t1 string");                                             //6
    T t2 (9, "t2 string");                                             //6

//    <#structName1#>

    TCompare f;                                           //7
    auto* smaller = f.compare (&t1, &t2);                              //8

    if (smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }

    U u1;
    float updatedValue = 5.f;

    std::cout << "[static func] u1's multiplied values: " << V::staticFunctionA (&u1, &updatedValue)
              << std::endl;                  //11

    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.mf1 (&updatedValue) << std::endl;
}

        








