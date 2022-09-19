#include <vector>
#include "Door.h"
#include "RandomGenerator.h"
#include <iostream>

class Experiment
{
    private:
        std::vector<Door> doors;
        void removeDoor()
        {
            int i = 0;
            // below loop is terminated when two doors remain
            while(true)
            {
                // removes a door if not chosen and doesn't have a car
                if (!doors[i].GetChoice() && !doors[i].GetCar()) 
                {
                    doors.erase(doors.begin()+i);
                    return;
                };
                i++;
            }
        };
    public:
        Experiment();
        ~Experiment(){};
        //void showDoors() const;
        bool Run();
};