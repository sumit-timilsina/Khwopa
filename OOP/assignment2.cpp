// 3.

//Using member
#include <iostream>
using namespace std;
class overload
{
    int a;

public:
    overload() : a(0) {}
    overload(int b) : a(b) {}
    void display()
    {
        cout << a;
    }
    overload operator-=(overload x)
    {
        a -= x.a;
        return *this;
    }
};
int main()
{
    overload obj1(4), obj2, obj3(5);
    obj2 = obj1 -= obj3;
    obj2.display();
}

// Using member

#include <iostream>
using namespace std;
class overload
{
    int a;

public:
    overload() : a(0) {}
    overload(int b) : a(b) {}
    void display()
    {
        cout << a;
    }
    overload operator+=(overload x)
    {
        a += x.a;
        return *this;
    }
};
int main()
{
    overload obj1(4), obj2, obj3(5);
    obj2 = obj1 += obj3;
    obj2.display();
}

// Using friend
#include <iostream>
using namespace std;
class overload
{
    int a;

public:
    overload() : a(0) {}
    overload(int b) : a(b) {}
    void display()
    {
        cout << a;
    }
    friend overload operator+=(overload y, overload x);
};
overload operator+=(overload y, overload x)
{
    overload temp;
    temp.a = y.a += x.a;
    return temp;
}
int main()
{
    overload obj1(4), obj2, obj3(5);
    obj2 = obj1 += obj3;
    obj2.display();
}

// 4.
// Using member
#include <iostream>
using namespace std;
class add
{
    int x;

public:
    add() : x(0) {}
    add(int a) : x(a) {}
    add operator+(add obj2)
    {
        return x + obj2.x;
    }
    void display()
    {
        cout << x;
    }
};
int main()
{
    add obj1(5), obj2(4), obj3, obj4;
    obj3 = obj1 + obj2;
    obj4 = obj3;
    obj4.display();
}

// Using friend
#include <iostream>
using namespace std;
class add
{
    int x;

public:
    add() : x(0) {}
    add(int a) : x(a) {}
    friend add operator+(add obj1, add obj2);
    void display()
    {
        cout << x;
    }
};
add operator+(add obj1, add obj2)
{
    add temp;
    temp.x = obj1.x + obj2.x;
    return temp;
}
int main()
{
    add obj1(5), obj2(4), obj3, obj4;
    obj3 = obj1 + obj2;
    obj4 = obj3;
    obj4.display();
}

//Using member
#include <iostream>
    using namespace std;
class unary
{
    int x;

public:
    unary() : x(0) {}
    unary(int a) : x(a) {}
    unary operator++()
    {
        unary temp;
        temp.x = ++x;
        return temp;
    }
    void display()
    {
        cout << x;
    }
    unary operator++(int)
    {
        unary temp;
        temp.x = x++;
        return temp;
    }
};
int main()
{
    unary obj1(5), obj2, obj3(4), obj4;
    obj2 = ++obj1;
    obj1.display();
    obj2.display();
    obj4 = obj3++;
    obj4.display();
    obj3.display();
}

//Using friend
#include <iostream>
    using namespace std;
class unary
{
    int x;

public:
    unary() : x(0) {}
    unary(int a) : x(a) {}
    friend unary operator++(unary &obj1);
    void display()
    {
        cout << x;
    }
    friend unary operator++(unary obj3, int);
};
unary operator++(unary &obj1)
{
    unary temp;
    temp.x = ++obj1.x;
    return temp;
}
unary operator++(unary obj3, int)
{
    unary temp;
    temp.x = obj3.x++;
    return temp;
}
int main()
{
    unary obj1(5), obj2, obj3(4), obj4;
    obj2 = ++obj1;
    obj1.display();
    obj2.display();
    obj4 = obj3++;
    obj4.display();
    obj3.display();
}

//member
#include <iostream>
    using namespace std;
class compare
{
    int x;

public:
    compare() : x(0) {}
    compare(int a) : x(a) {}
    compare operator>(compare obj2)
    {
        compare temp;
        temp.x = x > obj2.x;
        return temp;
    }
    void display()
    {
        cout << x;
    }
};
int main()
{
    compare obj1(5), obj2(4), obj3;
    obj3 = obj1 > obj2;
    obj3.display();
}
//Using friend
#include <iostream>
    using namespace std;
class compare
{
    int x;

public:
    compare() : x(0) {}
    compare(int a) : x(a) {}
    friend compare operator>(compare obj1, compare obj2);
    void display()
    {
        cout << x;
    }
};
compare operator>(compare obj1, compare obj2)
{
    compare temp;
    temp.x = obj1.x > obj2.x;
    return temp;
}
int main()
{
    compare obj1(5), obj2(4), obj3;
    obj3 = obj1 > obj2;
    obj3.display();
}

//5.
#include <iostream>
    using namespace std;
class MEMORY
{
    int kb, bytes, bits;

public:
    MEMORY(int a, int b, int c)
    {
        kb = a;
        bytes = b;
        bits = c;
    }
    void display()
    {
        cout << kb << bytes << bits;
    }
    operator int()
    {
        int i;
        i = bits + bytes * 8 + kb * 1024 * 8;
        return i;
    }
};
int main()
{
    MEMORY obj1(10, 400, 500);
    int d;
    d = obj1;
    cout << d;
}

//6.
#include <iostream>
    using namespace std;
class Distance
{
    float feet;
    float inch;

public:
    Distance() : feet(0), inch(0) {}
    Distance(float a, float b)
    {
        feet = a;
        inch = b;
    }
    operator float()
    {
        float a;
        a = feet + inch / 12;
        return a;
    }
};
int main()
{
    Distance d1(12, 45);
    float dist = d1;
    cout << "distance= " << dist << " feet";
    return 0;
}

//7.
#include <iostream>
    using namespace std;
class D
{
    int meter, cen;

public:
    D() {};
    D(float b)
    {
        meter = (int)b;
        cen = (b - (int)b) * 100;
    }

    void display()
    {
        cout << meter << " " << cen;
    }
};

int main()
{
    D obj1;
    float a;
    cin >> a;
    obj1 = a;
    obj1.display();
}

//8. #include<iostream> using namespace std;
class edistance;
class mdistance
{
    float meter;
    float cen;

public:
    mdistance() {}

    mdistance(float a, float b)
    {
        meter = (int)((a + b / 12) / 3.2);
        float c = ((a + b / 12) / 3.2) - (int)((a + b / 12) / 3.2);
        cen = c * 100;
    }
    void getdata()
    {
        cin >> meter >> cen;
    }
    void display()
    {
        cout << meter << " " << cen;
    }
    operator edistance();
};
class edistance
{
    float feet;
    float inch;

public:
    edistance() {}
    edistance(float a, float b)
    {
        float d;
        feet = (int)((a + b / 100) * 3.2);
        d = ((a + b / 100) * 3.2) - (int)((a + b / 100) * 3.2);
        inch = d * 12;
    }

    void display()
    {
        cout << feet << " " << inch;
    }
    void getdatas()
    {
        cin >> feet >> inch;
    }
    operator mdistance();
};
mdistance::operator edistance()
{
    return edistance(meter, cen);
}
edistance::operator mdistance()
{
    return mdistance(feet, inch);
}
int main()
{
    mdistance obj1;
    edistance obj2;
    obj1.getdata();
    obj2 = obj1;
    obj2.display();
    obj2.getdatas();
    obj1 = obj2;
    obj1.display();
}

//9.
#include <iostream>
#define pi 3.14
    using namespace std;
class radian;
class degree
{
    float degre;

public:
    degree() {}
    degree(float a) : degre(a) {}
    operator radian();
};
class radian
{
    float rad;

public:
    radian() {}
    radian(float a)
    {
        rad = a * pi / 180;
    }
    void display()
    {
        cout << rad;
    }
};
degree::operator radian()
{
    return radian(degre);
}
int main()
{
    degree obj1(5.4);
    radian obj2;
    obj2 = obj1;
    obj2.display();
}

//10. #include<iostream> using namespace std;
class gram;
class tola
{
    float tol;

public:
    tola() {}
    tola(float a) : tol(a) {}
    operator gram();
};
class gram
{
    float gra;

public:
    gram() {}
    gram(float a)
    {
        gra = a * 11.664;
    }
    void display()
    {
        cout << gra;
    }
};
tola::operator gram()
{
    return gram(tol);
}
int main()
{
    tola obj1(5.4);
    gram obj2;
    obj2 = obj1;
    obj2.display();
}

//11.
#include <iostream>
#include <string.h>
    using namespace std;
class con
{
    char a[100];

public:
    con()
    {
        a[0] = '\0';
    }
    con(char *b)
    {
        strcpy(a, b);
    }
    con operator+(con obj2)
    {
        con temp;
        strcpy(temp.a, a);
        strcat(temp.a, obj2.a);
        return temp;
    }
    void display()
    {
        cout << a;
    }
};
int main()
{
    con obj1("ram"), obj2("hari"), obj3;
    obj3 = obj1 + obj2;
    obj3.display();
}

//12.
#include <iostream>
#include <string.h>
    using namespace std;
class overload
{
    int b;
    char a[10];

public:
    overload()
    {
        a[0] = '\0';
    }
    overload(char *b)
    {
        strcpy(a, b);
    }
    overload operator==(overload obj2)
    {
        overload temp;
        temp.b = (strcmp(a, obj2.a) == 0) ? 1 : 0;

        return temp;
    }
    void display()
    {
        cout << b;
    }
};
int main()
{
    overload obj1("ram"), obj2("hari"), obj3;
    obj3 = obj1 == obj2;
    obj3.display();
}

//13. Using constructor
#include <iostream>
#include <math.h>
    using namespace std;
class cartesian;
class polar
{
    float r, theta;

public:
    polar() {};
    polar(float a, float b)
    {
        r = a;
        theta = b;
    }
    friend cartesian;
};
class cartesian
{
    float x;
    float y;

public:
    void display()
    {
        cout << x << " " << y;
    }
    cartesian() {}
    cartesian(polar obj1)
    {
        obj1.theta = (3.14 / 180) * obj1.theta;
        x = obj1.r * cos(obj1.theta);
        y = obj1.r * sin(obj1.theta);
    }
};
int main()
{
    polar obj1(4, 5);
    cartesian obj2;
    obj2 = obj1;
    obj2.display();
}

//Using casting operator
#include <iostream>
#include <math.h>
    using namespace std;
class cartesian;
class polar
{
    float r, theta;

public:
    polar() {};
    polar(float a, float b)
    {
        r = a;
        theta = b;
    }
    operator cartesian();
};
class cartesian
{
    float x;
    float y;

public:
    cartesian() {}
    cartesian(float a, float b)
    {
        b = (3.14 / 180) * b;
        x = a * cos(b);
        y = a * sin(b);
    }
    void display()
    {
        cout << x << " " << y;
    }
};
polar::operator cartesian()
{
    return cartesian(r, theta);
}
int main()
{
    polar obj1(4, 5);
    cartesian obj2;
    obj2 = obj1;
    obj2.display();
}
//15. 
#include<iostream>
#include <string.h>
    using namespace std;
class City
{
    char cityname[20];
    float Distfromktm;

public:
    City()
    {
        cityname[0] = '\0';
    }
    City(char *c, float b)
    {
        strcpy(cityname, c);
        Distfromktm = b;
    }
    void display()
    {
        cout << cityname << Distfromktm;
    }
    void dis()
    {
        cout << Distfromktm;
    }
    City operator+(City obj2)
    {
        City temp;
        temp.Distfromktm = Distfromktm + obj2.Distfromktm;
        return temp;
    }
};
int main()
{
    City obj1("pokhara", 5), obj2("djangadi", 10), obj3;
    obj1.display();
    obj2.display();
    obj3 = obj1 + obj2;
    obj3.dis();
}

//16. Using member
#include <iostream>
    using namespace std;
class vec
{
    int x, y, z;

public:
    vec() {}
    vec(int a, int b, int c)
    {
        x = a;
        y = b;
        z = c;
    }
    vec operator-(vec obj2)
    {
        vec temp;
        temp.x = x - obj2.x;
        temp.y = y - obj2.y;
        temp.z = z - obj2.z;
        return temp;
    }
    vec operator+(vec obj2)
    {
        vec temp;
        temp.x = x + obj2.x;
        temp.y = y + obj2.y;
        temp.z = z + obj2.z;
        return temp;
    }
    void display()
    {
        cout << x << " " << y << " " << z << endl;
    }
};
int main()
{
    vec obj1(4, 5, 6), obj2(3, 5, 6), obj3;
    obj3 = obj1 - obj2;
    obj3.display();
    obj3 = obj1 + obj2;
    obj3.display();
}

//Using friend
#include <iostream>
    using namespace std;
class vec
{
    int x, y, z;

public:
    vec() {}
    vec(int a, int b, int c)
    {
        x = a;
        y = b;
        z = c;
    }
    friend vec operator-(vec obj1, vec obj2);
    friend vec operator+(vec obj1, vec obj2);
    void display()
    {
        cout << x << " " << y << " " << z << endl;
    }
};
vec operator-(vec obj1, vec obj2)
{
    vec temp;
    temp.x = obj1.x - obj2.x;
    temp.y = obj1.y - obj2.y;
    temp.z = obj1.z - obj2.z;
    return temp;
}
vec operator+(vec obj1, vec obj2)
{
    vec temp;
    temp.x = obj1.x + obj2.x;
    temp.y = obj1.y + obj2.y;
    temp.z = obj1.z + obj2.z;
    return temp;
}

int main()
{
    vec obj1(4, 5, 6), obj2(3, 5, 6), obj3;
    obj3 = obj1 - obj2;
    obj3.display();
    obj3 = obj1 + obj2;
    obj3.display();
}