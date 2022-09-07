#include "Option.h"
#include "BinomialModel.h"

class EuropeanOption: public virtual Option
{
    public:
        double PriceByCRR(const BinomialModel &b) const;
        virtual ~EuropeanOption(){};
};
