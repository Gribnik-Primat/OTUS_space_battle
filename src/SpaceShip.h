#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <utility>
#include <stdexcept>
#include <vector>

class Spaceship {
public:
    Spaceship(double posX, double posY, double velX, double velY);

    std::pair<double, double> getPosition() const;
    std::pair<double, double> getVelocity() const;

    void setPosition(const std::pair<double, double>& newPosition);
    void move();

    int getDirection() const;
    void setDirection(int newDirection);
    void rotate(int angle);

    void rotateInDegrees(double angle);
    void setAngularVelocity(double newAngularVelocity);
    void rotateByAngularVelocity();

    double getFuelLevel() const;
    void setFuelLevel(double fuelLevel);

private:
    double convertToRadians(double degrees) const;

    std::pair<double, double> position;
    std::pair<double, double> velocity;
    int direction;
    double angularVelocity;
    double mFuelLevel;
};

class ICommand {
public:
    virtual ~ICommand() {}
    virtual void execute(Spaceship& spaceship) = 0;
};

class BurnFuelCommand : public ICommand {
public:
    BurnFuelCommand(double fuelBurnRate) : fuelBurnRate_(fuelBurnRate) {}

    void execute(Spaceship& spaceship) {
        double fuelLevel = spaceship.getFuelLevel();
        double newFuelLevel = fuelLevel - fuelBurnRate_;
        spaceship.setFuelLevel(newFuelLevel);
    }

private:
    double fuelBurnRate_;
};

class CheckFuelCommand : public ICommand {
public:
    CheckFuelCommand(double fuelThreshold) : mFuelThreshold(fuelThreshold) {}

    void execute(Spaceship& spaceship) {
        double fuelLevel = spaceship.getFuelLevel();
        if (fuelLevel < mFuelThreshold) {
            throw std::runtime_error("Insufficient fuel");
        }
    }

private:
    double mFuelThreshold;
};

class RotateVelocityCommand {
public:
    RotateVelocityCommand(int angle) : mAngle(angle) {}

    void execute(Spaceship& spaceship) {
        spaceship.rotate(mAngle);
        spaceship.rotateByAngularVelocity();
    }

private:
    int mAngle;
};

class MacroCommand : public ICommand{
public:
    MacroCommand(std::initializer_list<ICommand*> commands) : commands_(commands) {}

    void execute(Spaceship& spaceship) {
        for (ICommand* command : commands_) {
            command->execute(spaceship);
        }
    }

private:
    std::vector<ICommand*> commands_;
};


#endif  // SPACESHIP_H
