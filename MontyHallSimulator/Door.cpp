#include "Door.h"

Door::Door()
{
    hasCar = false;
    chosen = false;
};

bool Door::CheckChoice() const
{
    if (hasCar == chosen) return true;
    return false;
};