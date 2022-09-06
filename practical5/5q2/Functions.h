#pragma once

class RealFunction
{
    public:
        virtual ~RealFunction(){};
        virtual double evaluate(double x)=0;
};

class Sin: public RealFunction
{
    public:
        virtual double evaluate(double x);
        ~Sin(){};
        Sin();
};
