#include <gtest/gtest.h>
#include "SpaceShip.h"

TEST(CheckFuelCommandTest, SufficientFuel) {
    Spaceship spaceship(0.0, 0.0, 0.0, 0.0);
    spaceship.setFuelLevel(20.0);
    
    CheckFuelCommand checkFuelCommand(10.0);
    
    EXPECT_NO_THROW(checkFuelCommand.execute(spaceship));
}

TEST(CheckFuelCommandTest, InsufficientFuel) {
    Spaceship spaceship(0.0, 0.0, 0.0, 0.0);
    spaceship.setFuelLevel(5.0);
    
    CheckFuelCommand checkFuelCommand(10.0);
    
    EXPECT_THROW(checkFuelCommand.execute(spaceship), std::runtime_error);
}
