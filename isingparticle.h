#ifndef ISINGPARTICLE_H
#define ISINGPARTICLE_H

class IsingParticle {
private:
    int spin;
public:
    IsingParticle();
    void flipSpin();
    int spinValue() const;
};
#endif
