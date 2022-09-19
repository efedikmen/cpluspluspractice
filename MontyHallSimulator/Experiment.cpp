#include "Experiment.h"

Experiment::Experiment()
{
    doors.resize(3, Door());
    doors[RandUniformInt(3)].ChangeChoice();
    doors[RandUniformInt(3)].SetCar();
 
};
bool Experiment::Run()
{
    /*
    Since we are changing our preference once the empty door is shown, 
    The car must be in the door we previously didn't choose.
    So the hasCar and choice parameters should be opposite at both doors
    in order for us to win the car.

    NOTE: Not bothering with changing the choice parameters of the 
    remaining two doors to save speed over large number of iterations.
    */
   removeDoor();
   return !doors[0].CheckChoice(); // a.k.a.
};

/*
void Experiment::showDoors() const
{
    for (Door a: doors)
    {
        std::cout << "Chosen: " << a.GetChoice() << ", Has Car: " << a.GetCar() << std::endl; 
    }
};
*/