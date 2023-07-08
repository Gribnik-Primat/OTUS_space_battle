#include "SpaceShip.h"
#include <cmath>
#include <stdexcept>

Spaceship::Spaceship(double posX, double posY, double velX, double velY)
    : position(std::make_pair(posX, posY)), velocity(std::make_pair(velX, velY)), direction(0), angularVelocity(0) {}

std::pair<double, double> Spaceship::getPosition() const {
    if (std::isnan(position.first) || std::isnan(position.second) || std::isinf(position.first) || std::isinf(position.second)) {
        throw std::runtime_error("Invalid position");
    }
    return position;
}

std::pair<double, double> Spaceship::getVelocity() const {
    if (std::isnan(velocity.first) || std::isnan(velocity.second) || std::isinf(velocity.first) || std::isinf(velocity.second)) {
        throw std::runtime_error("Invalid velocity");
    }
    return velocity;
}

void Spaceship::setPosition(const std::pair<double, double>& newPosition) {
    if (std::isnan(newPosition.first) || std::isnan(newPosition.second) || std::isinf(newPosition.first) || std::isinf(newPosition.second)) {
        throw std::runtime_error("Invalid position");
    }
    position = newPosition;
}

void Spaceship::move() {
    position.first += velocity.first;
    position.second += velocity.second;
}

int Spaceship::getDirection() const {
    return direction;
}

void Spaceship::setDirection(int newDirection) {
    direction = newDirection;
}

void Spaceship::rotate(int angle) {
    direction += angle;
    if (direction < 0) {
        direction += 360;
    } else if (direction >= 360) {
        direction -= 360;
    }
}

double Spaceship::convertToRadians(double degrees) const {
    return degrees * M_PI / 180.0;
}

void Spaceship::rotateInDegrees(double angle) {
    double radians = convertToRadians(angle);
    double cosValue = cos(radians);
    double sinValue = sin(radians);

    double newX = velocity.first * cosValue - velocity.second * sinValue;
    double newY = velocity.first * sinValue + velocity.second * cosValue;

    velocity = std::make_pair(newX, newY);
}

void Spaceship::setAngularVelocity(double newAngularVelocity) {
    angularVelocity = newAngularVelocity;
}

void Spaceship::rotateByAngularVelocity() {
    rotate(static_cast<int>(angularVelocity));
}
