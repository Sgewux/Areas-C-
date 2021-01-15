#include <iostream>

using namespace std;

//Superclass
class Polygon
{
    public:

    Polygon(double iSide1, double iSide2, double iLongbase, double iBase, double iHeight)
    {
        side1 = iSide1;
        side2 = iSide2;
        longbase = iLongbase;
        base = iBase;
        height = iHeight;

    }

    double area()
    {
        return side1 * side2;
    }

    protected:
        double side1;
        double side2;
        double longbase;
        double base;
        double height;


};


//Square sublcass
class Square : public Polygon
{

public:

    Square(double iSide1) : Polygon(iSide1, iSide1, 0, 0, 0)
    {
        side1 = iSide1;
    }
};


//Triangle subclass
class Triangle : public Polygon
{

public:

    Triangle(double iBass, double iHeight) : Polygon(0, 0, 0, iBass, iHeight)
    {
        base = iBass;
        height = iHeight;
    }

    double area()
    {
        return (base * height) / 2; //Here i used polymorphism because triangle's area uses a different formula.
    }

};


//Subclass rectangle
class Rectangle : public Polygon
{

public:
    Rectangle(double iSide1, double iSide2) : Polygon(iSide1, iSide2, 0, 0, 0)
    {
        side1 = iSide1;
        side2 = iSide2;
    }
};


class Trapezoid : public Polygon
{

public:
    Trapezoid(double iLongbase, double iBase, double iHeight) : Polygon(0, 0, iLongbase, iBase, iHeight)
    {
        longbase = iLongbase;
        base = iBase;
        height = iHeight;
    }

    double area()
    {
        return (longbase * base / 2) * height;  //more polymorphism because trapezoid uses a different formula.
    }
};


//This function calculates an polygon's area according to the user's input
void calculate_area(char user_choice)
{
    switch(toupper(user_choice))
    {
    case 'S':
    {
        double a;
        cout << "Square's side: ";
        cin >> a;


        Square s(a);
        cout << "Your square's area : "<< s.area() << endl;
        break;


        }

    case 'T':
    {
        double h;
        double b;
        cout << "Triangle's height: ";
        cin >> h;
        cout << "Triangle's bass: ";
        cin >> b;

        Triangle t(b, h);
        cout << "Your triangle's area: " << t.area() << endl;
        break;
    }

    case 'R':
    {
        double s1;
        double s2;
        cout << "Rectangle's first side: ";
        cin >> s1;
        cout << "Rectangle's second side:  ";
        cin >> s2;

        Rectangle r(s1, s2);
        cout << "Your rectangle's area: " << r.area() << endl;
        break;
    }

    case 'P':
    {
        double lb;
        double b;
        double h;

        cout << "Trapezoid's long base: ";
        cin >> lb;
        cout << "Trapezoid's short base: ";
        cin >> b;
        cout << "Trapezoid's height: ";
        cin >> h;

        Trapezoid tp(lb, b, h);
        cout << "Your trapezoid's area: " << tp.area() << endl;
        break;


    }
    default:

        cout << "Wrong char";
        break;


    }
}


int main()
{

    char userInput;
    cout << "Write [S] to calculate an square's area " << endl;
    cout << "Write [T] to calculate an triangle's area " << endl;
    cout << "Write [R] to calculate an rectangle's area " << endl;
    cout << "Write [P] to calculate an trapezoid's area " << endl;
    cin >> userInput;
    calculate_area(userInput);

    return 0;
}
