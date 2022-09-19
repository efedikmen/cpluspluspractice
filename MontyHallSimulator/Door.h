class Door
{
    private:
        bool hasCar;
        bool chosen;
    public:
        Door();
        ~Door(){};
        bool GetCar() const {return hasCar;};
        bool GetChoice() const {return chosen;};
        void ChangeChoice() {chosen = !chosen;};
        void SetCar() {hasCar=true;};
        bool CheckChoice() const;
};