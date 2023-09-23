#include <gtest/gtest.h>
#include "SpaceShip.h"

TEST(RotateVelocityCommandTest, RotateVelocity) {
    Spaceship spaceship(0.0, 0.0, 0.0, 10.0);
    
    RotateVelocityCommand rotateVelocityCommand(90);
    rotateVelocityCommand.execute(spaceship);
    
    std::pair<double, double> expectedVelocity(0.0, 10.0);
    EXPECT_EQ(spaceship.getVelocity(), expectedVelocity);
}
