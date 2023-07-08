#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <utility>

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

private:
    double convertToRadians(double degrees) const;

    std::pair<double, double> position;
    std::pair<double, double> velocity;
    int direction;
    double angularVelocity;
};

#endif  // SPACESHIP_H
