// Q2. Access Specifiers (Private, Protected, Public):

#include <iostream>
using namespace std;

class Base
{
private:
    int a;

protected:
    int b;

public:
    int c;
};

class Derived : public Base
{
public:
    void set()
    {
        b = 10;
        c = 20;
    }
    void get()
    {
        cout << b << " " << c << endl;
    }
};

int main()
{
    Derived d;
    d.set();
    d.get();
    return 0;
}

// Q6. Inheritance Types:

// a) Single Inheritance

#include <iostream>
using namespace std;

class A
{
public:
    void showA()
    {
        cout << "Class A" << endl;
    }
};

class B : public A
{
public:
    void showB()
    {
        cout << "Class B" << endl;
    }
};

int main()
{
    B obj;
    obj.showA();
    obj.showB();
    return 0;
}
// b) Multilevel Inheritance

#include <iostream>
using namespace std;

class A
{
public:
    void showA()
    {
        cout << "A" << endl;
    }
};

class B : public A
{
public:
    void showB()
    {
        cout << "B" << endl;
    }
};

class C : public B
{
public:
    void showC()
    {
        cout << "C" << endl;
    }
};

int main()
{
    C obj;
    obj.showA();
    obj.showB();
    obj.showC();
    return 0;
}
// c) Multiple Inheritance

#include <iostream>
using namespace std;

class A
{
public:
    void showA()
    {
        cout << "A" << endl;
    }
};

class B
{
public:
    void showB()
    {
        cout << "B" << endl;
    }
};

class C : public A, public B
{
public:
    void showC()
    {
        cout << "C" << endl;
    }
};

int main()
{
    C obj;
    obj.showA();
    obj.showB();
    obj.showC();
    return 0;
}
// d) Hierarchical Inheritance

#include <iostream>
using namespace std;

class A
{
public:
    void showA()
    {
        cout << "A" << endl;
    }
};

class B : public A
{
public:
    void showB()
    {
        cout << "B" << endl;
    }
};

class C : public A
{
public:
    void showC()
    {
        cout << "C" << endl;
    }
};

int main()
{
    B obj1;
    C obj2;
    obj1.showA();
    obj1.showB();
    obj2.showA();
    obj2.showC();
    return 0;
}
// e) Hybrid Inheritance

#include <iostream>
using namespace std;

class A
{
public:
    void showA()
    {
        cout << "A" << endl;
    }
};

class B : public A
{
public:
    void showB()
    {
        cout << "B" << endl;
    }
};

class C : public A
{
public:
    void showC()
    {
        cout << "C" << endl;
    }
};

class D : public B, public C
{
public:
    void showD()
    {
        cout << "D" << endl;
    }
};

int main()
{
    D obj;
    obj.showB();
    obj.showC();
    obj.showD();
    return 0;
}

// Q7. Constructor Invocation

#include <iostream>
using namespace std;

class A
{
public:
    A()
    {
        cout << "Constructor A" << endl;
    }
};

class B : public A
{
public:
    B()
    {
        cout << "Constructor B" << endl;
    }
};

class C : public A
{
public:
    C()
    {
        cout << "Constructor C" << endl;
    }
};

class D : public B, public C
{
public:
    D()
    {
        cout << "Constructor D" << endl;
    }
};

int main()
{
    cout << "Single:" << endl;
    B obj1;
    cout << "Multilevel:" << endl;
    class E : public B
    {
    public:
        E()
        {
            cout << "Constructor E" << endl;
        }
    };
    E obj2;
    cout << "Multiple:" << endl;
    D obj3;
    return 0;
}

// Q9. Virtual Class, Virtual Function, Virtual Destructor

#include <iostream>
using namespace std;

class Person
{
public:
    virtual void display() = 0;
    virtual ~Person() {}
};

class Employee : virtual public Person
{
public:
    void display()
    {
        cout << "Employee" << endl;
    }
};

class Student : virtual public Person
{
public:
    void display()
    {
        cout << "Student" << endl;
    }
};

class Manager : public Employee, public Student
{
public:
    void display()
    {
        cout << "Manager" << endl;
    }
};

int main()
{
    Person *p = new Manager;
    p->display();
    delete p;
    return 0;
}

// Q10. Inheritance, Overriding, Accessing Overridden Members

#include <iostream>
using namespace std;

class Course
{
public:
    virtual void show()
    {
        cout << "Course" << endl;
    }
};

class Mathematics : public Course
{
public:
    void show()
    {
        cout << "Mathematics" << endl;
    }
};

class Science : public Course
{
public:
    void show()
    {
        cout << "Science" << endl;
    }
};

class Engineering : public Course
{
public:
    void show()
    {
        cout << "Engineering" << endl;
    }
};

class Physics : public Science
{
public:
    void show()
    {
        Science::show();
        cout << "Physics" << endl;
    }
};

class Chemistry : public Science
{
public:
    void show()
    {
        Science::show();
        cout << "Chemistry" << endl;
    }
};

int main()
{
    Chemistry c;
    c.show();
    return 0;
}

// Q11. Student, Test, Result (Multilevel Inheritance)

#include <iostream>
using namespace std;

class Student
{
protected:
    int roll;

public:
    void getRoll()
    {
        cin >> roll;
    }
};

class Test : public Student
{
protected:
    int m1, m2;

public:
    void getMarks()
    {
        cin >> m1 >> m2;
    }
};

class Result : public Test
{
public:
    void display()
    {
        int total = m1 + m2;
        cout << roll << " " << total << endl;
    }
};

int main()
{
    Result r;
    r.getRoll();
    r.getMarks();
    r.display();
    return 0;
}

// Q12. Abstract Class

#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void sound() = 0;
};

class Dog : public Animal
{
public:
    void sound()
    {
        cout << "Bark" << endl;
    }
};

int main()
{
    Animal *a = new Dog;
    a->sound();
    delete a;
    return 0;
}

// Q14. Pure Virtual Function, Runtime Polymorphism

#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void area() = 0;
};

class Circle : public Shape
{
public:
    void area()
    {
        cout << "Circle area" << endl;
    }
};

int main()
{
    Shape *s = new Circle;
    s->area();
    delete s;
    return 0;
}

Q19.Abstract Class, Virtual Functions

#include <iostream>
    using namespace std;

class Shape
{
public:
    virtual void area() = 0;
    virtual void display()
    {
        cout << "Shape" << endl;
    }
};

class Circle : public Shape
{
public:
    void area()
    {
        cout << "Circle area" << endl;
    }
    void display()
    {
        cout << "Circle" << endl;
    }
};

class Rectangle : public Shape
{
public:
    void area()
    {
        cout << "Rectangle area" << endl;
    }
    void display()
    {
        cout << "Rectangle" << endl;
    }
};

int main()
{
    Shape *s;
    Circle c;
    Rectangle r;
    s = &c;
    s->area();
    s->display();
    s = &r;
    s->area();
    s->display();
    return 0;
}