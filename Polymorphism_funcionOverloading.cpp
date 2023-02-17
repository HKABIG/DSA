//Polymorphism 
//Function overloading 

#include <bits/stdc++.h>
using namespace std;

class Vit{
    public:
    void func(int x){
        cout<<"I am a function with integer argument"<<endl;
    }
    void func(double x){
        cout<<"I am a function wiht double argument"<<endl;
    }
    void func(){
        cout<<"I am a funtion with no argument"<<endl;
    }
};

int main() {
	// your code goes here
	Vit obj;//instance of class , the so called object
	obj.func(4);
	obj.func();
	obj.func(6.2);
	return 0;
}
