// IRotatable.h

#ifndef IROTATABLE_H
#define IROTATABLE_H

class IRotatable {
public:
    virtual ~IRotatable() {}

    virtual void rotate(int angle) = 0;
    virtual void rotateInDegrees(double angle) = 0;
};


#endif  // IROTATABLE_H
