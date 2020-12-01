#include <iostream>
#include<string>
using namespace std;
#if 0
class Person
{
public:
    void Print()
    {
        cout << _name << endl;
    }
protected:
    string _name;
private:
    int _age;   
};
class Student :public Person
{
public:
    void print()
    {
        cout << _stuNum << endl;
    }
    
protected:
    int _stuNum;
};


int main()
{
    //父类的对象不能调用子类的方法，即使将子类对象赋值给父类对象
    Person p;
    Student s;
    Person* p1 = &s;
    p = s;//子类对象赋值给父类 关系是is-a关系
    //父类不能赋值给子类  

}
class A
{
public:
    void fun()
    {
        cout << "func()" << endl;
    }
};
class B :public A
{
public:
    void fun(int i)
    {
        A::fun();
        cout << "func(int i)->" << i << endl;
    }
};
int main()
{
    B b;
    b.A::fun();
}
#endif
class Person
{
public:
    Person(const char* name = "mlk"):_name(name)
    {
        cout << "Person()" << endl;
    }//基类构造函数
    Person(const Person& p) :_name(p._name)
    {
        cout << "Person(const Person& p)" << endl;
    }//基类拷贝构造
    Person& operator=(const Person& p)
    {
        cout << "Person& operator=(const Person& p)" << endl;
        if (this != &p)
            _name = p._name;
        return *this;
    }
    ~Person()
    {
        cout << "~Person()" << endl;
    }
protected:
    string _name;
};
class Student :public Person
{
public:
    Student(const char* name, int num) :Person(name), _num(num)
    {
        cout << "Student()" << endl;
    }
    Student(const Student& s):Person(s),_num(s._num)
    {
        cout << "Student(const Student& s)" <<endl;
    }
    Student& operator=(const Student& s)
    {
        cout << "Student& operator=(const Student& s)" << endl;
        if (this != &s)
        {
            Person::operator = (s);
            _num = s._num;
        }
        return *this;
    }
    ~Student()
    {
        cout << "~Student()" << endl;
    }
protected:
    int _num;
};
int main()
{
    Student s1("mlk", 18);
    Student s2(s1);
    Student s3("mlkk", 16);
    s1 = s3;
    return 0;
}