#include <iostream>
#include <cmath>

/*
class representing a point in the Cartesian coordinate system
*/

class PolarPoint;
class CartesianPoint
{
    private:    
        double x;
        double y;
    public:
        // default constructor
        CartesianPoint()
        {
            x = 0;
            y = 0;
        }
        // parametrized constructor
        CartesianPoint(double x, double y)
        {
            this->x = x;
            this->y = y;
        };
        // copy constructor
        CartesianPoint(const CartesianPoint &p)
        {
            x = p.x;
            y = p.y;
        }
        ~CartesianPoint()
        {};
        double Get_x() const
        {
            return x;
        };
        double Get_y() const
        {
            return y;
        };
        double distanceTo(const CartesianPoint &p) const
        {
            return sqrt(pow(x-p.x, 2) + pow(y-p.y, 2));
        };
        void set_x(double x)
        {
            this->x = x;
        }
        void set_y(double y)
        {
            this->y = y;
        }
        double distanceTo(const PolarPoint &p) const;
};

class PolarPoint
{
    private:
        double r;
        double theta;
    public:
        PolarPoint()
        {
            r = 0.0;
            theta = 0.0;
        };
        PolarPoint(double radius, double angle)
        {
            r = radius;
            theta = angle;
        };
        PolarPoint(const PolarPoint &p)
        {
            r = p.r;
            theta = p.theta;
        };
        ~PolarPoint()
        {};
        double Get_r() const
        {
            return r;
        };
        double Get_theta() const
        {
            return theta;
        };
        void set_r(double r)
        {
            this->r = r;
        };
        void set_theta(double theta)
        {
            this->theta = theta;
        };
        double distanceTo(const CartesianPoint &p) const;
};

CartesianPoint polarToCartesian(const PolarPoint& p)
{
    double r = p.Get_r();
    double theta = p.Get_theta();
    double x = r*cos(theta);
    double y = r*sin(theta);
    CartesianPoint cartesian(x, y);
    return cartesian;
};

PolarPoint cartesianToPolar(const CartesianPoint& p)
{
    double x = p.Get_x();
    double y = p.Get_y();
    double r = sqrt(x*x+y*y);
    double theta = atan(y/x);
    PolarPoint pol(r, theta);
    return pol;
};

double CartesianPoint::distanceTo(const PolarPoint &p) const
{
    CartesianPoint pt(polarToCartesian(p));
    double dist = distanceTo(pt);
    return dist;
}

/*double PolarPoint::distanceTo(const CartesianPoint &p) const
{
    PolarPoint pt(cartesianToPolar(p));
    double dist = distanceTo(pt);
    return dist;
}
*/
int main()
{
    CartesianPoint pt1(3.0,5.4);
    CartesianPoint pt2(1.2, 2.2);
    std::cout << pt1.distanceTo(pt2) << std::endl;
    pt1.set_x(23.2);
    std::cout << pt2.distanceTo(pt1) << std::endl;
    std::cout << pt2.distanceTo(pt2) << std::endl;
    CartesianPoint pt3(1.0, 1.0);
    PolarPoint newpt = cartesianToPolar(pt3);
    double r = newpt.Get_r();
    double theta = newpt.Get_theta();
    std::cout << r << "and" << theta << std::endl;
    std::cout << pt1.distanceTo(pt3) << std::endl;
    std::cout << pt1.distanceTo(newpt) << std::endl;
    PolarPoint pt(cartesianToPolar(pt1));
    std::cout << "r=" << pt.Get_r() << " theta=" << pt.Get_theta() << std::endl;
    std::cout << "Must be 0 if polar to Cartesian conversion works:" << pt1.distanceTo(pt) << std::endl;
    return 0;
}