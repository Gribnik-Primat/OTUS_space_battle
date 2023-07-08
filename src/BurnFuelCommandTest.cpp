#include <gtest/gtest.h>
#include "SpaceShip.h"

TEST(BurnFuelCommandTest, DecreaseFuelLevel) {
    Spaceship spaceship(0.0, 0.0, 0.0, 0.0);
    spaceship.setFuelLevel(20.0);
    
    BurnFuelCommand burnFuelCommand(5.0);
    burnFuelCommand.execute(spaceship);
    
    EXPECT_DOUBLE_EQ(spaceship.getFuelLevel(), 15.0);
}
