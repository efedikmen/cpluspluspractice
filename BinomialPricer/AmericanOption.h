#pragma once
#include "Option.h"
#include "BinomialModel.h"
#include "BinomialLattice.h"

class AmericanOption: public virtual Option
{
    public:
        double PriceBySnell(const BinomialModel &b) const;
        virtual ~AmericanOption(){};
        double PriceBySnell(const BinomialModel &b, BinomialLattice<double> &prices,
                            BinomialLattice<bool> &stop) const;
};