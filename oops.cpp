//OOPS IN C++
#include <bits/stdc++.h>
using namespace std;

//Class Declaration 
class student{
    //class data
    //private data
    //string garde;
    string name;
    public://public data
        int age;
        bool gender;
    student(){
        cout<<"Default Constructor"<<endl;
    }//default Constructor
    student(string s,int a,bool g){
        cout<<"Parameterised Constructor"<<endl;
    }//Parameterised Constructor
    void printInfo(){
        cout<<name<<endl;
        cout<<age<<endl;
        cout<<gender<<endl;
    }
    void setName(string s){//Setter
        name = s;
    }
    void getName(string s,int a,bool g){
        cout<<name<<endl;
        cout<<a<<endl;
        cout<<g<<endl;
    }
    student(student &a){//Copy Constructor
        cout<<"Copy Constructor"<<endl;
        name = a.name;
        age = a.age;
        gender = a.gender;
    }
    bool operator== (student &a){//Overloading operator
        if(name == a.name && age == a.age && gender == a.gender){
            return true;
        }
        else{
            return false;
        }
    }
    
};

int main() {
	// your code goes here
	student a;//we can also define a array of class objects
	string s;
	s = "John";
	a.setName(s);
	a.age = 19;
	a.gender = 1;
	a.printInfo();
	student b("sush",19,0);
	b.printInfo();
	student d = a;//Copy Constructor
	if(a==b){//Overloading operator
	    cout<<"Same"<<endl;
	}
	else{
	    cout<<"Not Same"<<endl;
	}
	
}
