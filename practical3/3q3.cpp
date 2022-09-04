#include <iostream>
#include <cmath>

/*
creating a complex numbers class with overloaded operators
*/

class Complex
{
    private: 
        double x; // real part
        double y; // complex part
    public:
        Complex()
        {
            x = 0.0;
            y = 0.0;
        };
        Complex(double re, double im)
        {
            x = re;
            y = im;
        }
        Complex(const Complex &c)
        {
            x = c.x;
            y = c.y;
        }
        ~Complex(){};
        double Get_Re() const {return x;};
        double Get_Im() const {return y;};
        void Set_Re(double re) {x = re;};
        void Set_Im(double im) {y = im;};
        double abs() const {return sqrt(x*x+y*y);};
        Complex conjugate() const
        {
            Complex p(x,-y);
            return p;
        }
        Complex operator= (const Complex &p){return p;};
        friend Complex operator+ (const Complex &c, const Complex &p)
        {
            Complex a;
            a.Set_Re(c.Get_Re()+p.Get_Re());
            a.Set_Im(c.Get_Im()+p.Get_Im());
            return a;
        } 
        Complex operator+= (const Complex &c)
        {
            this->x += c.Get_Re();
            this->y += c.Get_Im();
            return *this;
        }
        Complex operator-= (const Complex &c)
        {
            this->x -= c.Get_Re();
            this->y -= c.Get_Im();
            return *this;
        }
        friend Complex operator- (const Complex &c, const Complex &p)
        {
            Complex a;
            a.Set_Re(c.Get_Re()-p.Get_Re());
            a.Set_Im(c.Get_Im()-p.Get_Im());
            return a;
        }
        friend Complex operator* (const Complex &c, const Complex &p)
        {
            Complex a;
            a.Set_Re(c.Get_Re()*p.Get_Re()-c.Get_Im()*p.Get_Im());
            a.Set_Im(c.Get_Re()*p.Get_Im()+c.Get_Im()*p.Get_Re());
            return a;
        }
        friend bool operator== (const Complex &c, const Complex &p)
        {
            return (c.Get_Re() == p.Get_Re() && c.Get_Im() == p.Get_Im());
        }
        friend bool operator!= (const Complex &c, const Complex &p)
        {
            return !(c == p);
        }
        friend std::ostream & operator<< (std::ostream &out, const Complex &c)
        {
            if (c.Get_Im() < 0)
            {
                out << c.Get_Re() << c.Get_Im() << 'i' << std::endl;
                return out;
            }
            out << c.Get_Re() << '+' << c.Get_Im() << 'i' << std::endl;
            return out;
        }
};

int main()
{
    Complex c(1.0,1.0);
    Complex p = c.conjugate();
    std::cout << p.Get_Re() << ' ' << p.Get_Im() << std::endl;
    Complex e = c+p;
    e -= p;
    std::cout << e.Get_Re() << ' ' << e.Get_Im() << std::endl;
    Complex d = c * p;
    std::cout << "multiplication of conjugates 1+-i is:" << d.Get_Re() << " +" << d.Get_Im() << 'i' << std::endl;
    if (d == d)
    {
        std::cout << "d == d true" << std::endl;
    }
    if (d == e)
    {
        std::cout << "d == e true check your code" << std::endl;
    }
    if (d != e)
    {
        std::cout << "d != e true bravo" << std::endl;
    }
    if (d != d)
    {
        std::cout << "d != d true check your code" << std::endl;
    }
    std::cout << "Printing a complex number with the overloaded << operator: " << e << std::endl;
    return 0;
}