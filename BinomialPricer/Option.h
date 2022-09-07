class Option
{
    private:
        int N;
    public:
        int GetN() const { return N; };
        void SetN(int n) { N = n; };
        virtual ~Option(){};
        virtual double payoff(double z)const=0;
};