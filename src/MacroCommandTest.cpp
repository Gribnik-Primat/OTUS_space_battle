#include <gtest/gtest.h>
#include "SpaceShip.h"

class MockCommand : public ICommand {
public:
    void execute(Spaceship& spaceship) override {
        executed_ = true;
    }
    
    bool wasExecuted() const {
        return executed_;
    }
    
private:
    bool executed_ = false;
};

TEST(MacroCommandTest, ExecuteAllCommands) {
    Spaceship spaceship(0.0, 0.0, 0.0, 0.0);
    
    MockCommand command1;
    MockCommand command2;
    MockCommand command3;
    
    MacroCommand macroCommand({&command1, &command2, &command3});
    macroCommand.execute(spaceship);
    
    EXPECT_TRUE(command1.wasExecuted());
    EXPECT_TRUE(command2.wasExecuted());
    EXPECT_TRUE(command3.wasExecuted());
}
