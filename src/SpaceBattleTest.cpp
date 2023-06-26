#include <gtest/gtest.h>
#include "SpaceShip.h"
#include <cmath>
#include <stdexcept>

TEST(SpaceshipTest, MoveObjectSuccessfully) {
    Spaceship obj(12.0, 5.0, -7.0, 3.0);
    obj.move();
    EXPECT_DOUBLE_EQ(obj.getPosition().first, 5.0);
    EXPECT_DOUBLE_EQ(obj.getPosition().second, 8.0);
}

TEST(SpaceshipTest, InvalidPositionRead) {
    Spaceship obj(std::nan(""), std::nan(""), -7.0, 3.0);
    EXPECT_THROW(obj.getPosition(), std::runtime_error);
}

TEST(SpaceshipTest, InvalidVelocityRead) {
    Spaceship obj(12.0, 5.0, std::nan(""), std::nan(""));
    EXPECT_THROW(obj.getVelocity(), std::runtime_error);
}

TEST(SpaceshipTest, InvalidPositionWrite) {
    Spaceship obj(12.0, 5.0, -7.0, 3.0);
    obj.move();
    EXPECT_THROW(obj.setPosition(std::make_pair(std::nan(""), 5.0)), std::runtime_error);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
