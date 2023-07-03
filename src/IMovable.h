// IMovable.h

#ifndef IMOVABLE_H
#define IMOVABLE_H

#include <utility>

class IMovable {
public:
    virtual ~IMovable() {}

    virtual void move() = 0;
};

#endif  // IMOVABLE_H
