// PHYS 30762 Programming in C++
// Assignment 5

// Header including Up class

// Author: Linda Persley (student ID: 10683097)
// Date: 20/04/2024

#ifndef UP_H
#define UP_H

#include<iostream>
#include<string>

#include"particle.h"
#include"quark.h"

class Up : public Quark
{
  public:
    // Default constructor
    Up() : Quark() {};

    // Parameterised constructor (all up quarks have baryon number=1/3, charge=2/3 and rest mass=2.2 MeV/c^2
    // so these are set here)
    Up(std::string colour, double energy, double p_x, double p_y, double p_z) : Quark(0.333, colour, 0.667, "up", 2.2, energy, p_x, p_y, p_z) {};

    // Destructor
    virtual ~Up() {};

    // Overriden clone function
    std::unique_ptr<Particle> clone() const {return std::make_unique<Up>(*this);}
};

#endif