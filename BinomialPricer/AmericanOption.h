#pragma once
#include "Option.h"
#include "BinomialModel.h"

class AmericanOption: public virtual Option
{
    public:
        double PriceBySnell(const BinomialModel &b) const;
        virtual ~AmericanOption(){};
};