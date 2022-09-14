class PriceAndSE
{
    private: 
        double price = 0.0;
        double se = 0.0;
    public:
        ~PriceAndSE(){};
        double GetPrice() const {return price;};
        double GetSE() const {return se;};
        void SetPrice(const double z) {price=z;};
        void SetSE(const double z) {se=z;};
 };