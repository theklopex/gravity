#include <iostream>
#include <EntityList.h>
#include <unistd.h>  // for sleep()



// Mass in grams
const double MASS_OF_SUN =          1989100000000000000000000000000000.0;
const double MASS_OF_MERCURY =      330110000000000000000000000.0;
const double MASS_OF_VENUS =        4867500000000000000000000000.0;
const double MASS_OF_EARTH =        5972400000000000000000000000.0;
const double MASS_OF_MARS =         641710000000000000000000000.0;
const double MASS_OF_JUPITER =      1898187000000000000000000000000.0;
const double MASS_OF_SATURN =       568317000000000000000000000000.0;
const double MASS_OF_URANUS =       86813000000000000000000000000.0;
const double MASS_OF_NEPTUNE =      102413000000000000000000000000.0;
const double MASS_OF_PLUTO =        13030000000000000000000000.0;

// moons
const double MASS_OF_MOON =         73460000000000000000000000.0;  // Earth I

const double MASS_OF_IO =           89320000000000000000000000.0;  // Jupiter I
const double MASS_OF_EUROPA =       48000000000000000000000000.0;  // Jupiter II
const double MASS_OF_GANYMEDE =     148200000000000000000000000.0;   // Jupiter III
const double MASS_OF_CALLISTO =     107600000000000000000000000.0;  // Jupiter IV

const double MASS_OF_TETHYS =       624000000000000000000000.0;  // Saturn III
const double MASS_OF_DIONE =        1095000000000000000000000.0;  // Saturn IV
const double MASS_OF_RHEA =         2307000000000000000000000.0;  // Saturn V
const double MASS_OF_TITAN =        134500000000000000000000000.0;  // Saturn VI
const double MASS_OF_IAPETUS =      1806000000000000000000000.0;  // Saturn VIII

const double MASS_OF_TITANIA =      3400000000000000000000000.0;  // Uranus III
const double MASS_OF_OBERON =       3080000000000000000000000.0;  // Uranus IV
const double MASS_OF_UMBRIEL =      1280000000000000000000000.0;  // Uranus II
const double MASS_OF_ARIEL =        1250000000000000000000000.0;  // Uranus I

const double MASS_OF_TRITON =       21390000000000000000000000.0;  // Neptune I

const double MASS_OF_CHARON =       1586000000000000000000000.0;  // Pluto I






// Radius in meters.
const double RADIUS_OF_SUN =        695508000.0;
const double RADIUS_OF_MERCURY =    2439400.0;
const double RADIUS_OF_VENUS =      6052000.0;
const double RADIUS_OF_EARTH =      6371008.4;
const double RADIUS_OF_MARS =       3389500.0;
const double RADIUS_OF_JUPITER =    69911000.0;
const double RADIUS_OF_SATURN =     58232000.0;
const double RADIUS_OF_URANUS =     25362000.0;
const double RADIUS_OF_NEPTUNE =    24622000.0;
const double RADIUS_OF_PLUTO =      1188300.0;

// moons
const double RADIUS_OF_MOON =       1737500.0;  // Earth I

const double RADIUS_OF_IO =         1821600.0;  // Jupiter I
const double RADIUS_OF_EUROPA =     1560800.0;  // Jupiter II
const double RADIUS_OF_GANYMEDE =   2634100.0;  // Jupiter III
const double RADIUS_OF_CALLISTO =   2410300.0;  // Jupiter IV

const double RADIUS_OF_TETHYS =     533000.0;  // Saturn III
const double RADIUS_OF_DIONE =      561750.0;  // Saturn IV
const double RADIUS_OF_RHEA =       763800.0;  // Saturn V
const double RADIUS_OF_TITAN =      2574730.0;  // Saturn VI
const double RADIUS_OF_IAPETUS =    735600.0;  // Saturn VIII

const double RADIUS_OF_TITANIA =    788900.0;  // Uranus III
const double RADIUS_OF_OBERON =     761400.0;  // Uranus IV
const double RADIUS_OF_UMBRIEL =    584700.0;  // Uranus II
const double RADIUS_OF_ARIEL =      578900.0;  // Uranus I

const double RADIUS_OF_TRITON =     1353400.0;  // Neptune I

const double RADIUS_OF_CHARON =     606000.0;  // Pluto I


void display(const EntityList & entityList)
{
    std::cout << "=====================================================" << std::endl;
    std::cout << entityList << std::endl;
}

// Calculate the forces pulling on every entity and then move all entities.
// secsToTranspire is the number of seconds to advance time/motion in this step.
int step(EntityList & entityList, double secsToTranspire)
{
    // Reset all force vectors.
    entityList.calculateForces(secsToTranspire);

    return 0;
}


int run(EntityList & entityList)
{
    // How many seconds will pass per one loop
    double secsPerLoop = 1;
    int retval = 0;

    while (retval == 0)
    {
        retval = step(entityList, secsPerLoop);
        // Each loop will take one second of real time.
        sleep(1);
        display(entityList);
    }
    return 0;
}


int main(int argv, char** argc)
{
    EntityList entityList;

    // You should not have two entities with the same name.  That would break stuff.

    entityList.addEntity("Earth", 0,0,0, MASS_OF_EARTH, RADIUS_OF_EARTH);
    // The moon is (on average) 384400000 meters away from the center of the Earth.
    entityList.addEntity("Moon", 384400000, 0, 0, MASS_OF_MOON, RADIUS_OF_MOON);
    return run(entityList);
}