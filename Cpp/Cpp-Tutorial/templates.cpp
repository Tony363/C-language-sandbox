    #include <iostream>
    using namespace std;
    
    template<typename T>
    void Swap(T & a, T & b)  {
    // your code goes here
        string temp = a;
        a = b;
        b = temp;
    }

    int main() {
        string hello = "world!", 
        world = "Hello, ";
        Swap( world, hello );
        cout << hello << world << endl; //Output is "Hello, world!"
  
        return 0;
    }