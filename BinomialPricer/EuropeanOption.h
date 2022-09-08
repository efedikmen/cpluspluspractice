#pragma once
#include "Option.h"
#include "BinomialModel.h"
#include "BinomialLattice.h"

class EuropeanOption: public virtual Option
{
    public:
        double PriceByCRR(const BinomialModel &b) const;
        virtual ~EuropeanOption(){};
        double PriceByCRR(const BinomialModel &b, BinomialLattice<double> &prices, 
                        BinomialLattice<double> &strategy, BinomialLattice<double> &rates) const;
};
