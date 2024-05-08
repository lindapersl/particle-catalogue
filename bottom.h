// PHYS 30762 Programming in C++
// Assignment 5

// Header including Bottom class

// Author: Linda Persley (student ID: 10683097)
// Date: 20/04/2024

#ifndef BOTTOM_H
#define BOTTOM_H

#include<iostream>
#include<string>

#include"particle.h"
#include"quark.h"

class Bottom : public Quark
{
  public:
    // Default constructor
    Bottom() : Quark() {};

    // Parameterised constructor (all bottom quarks have baryon number=1/3, charge=-1/3 and rest mass=4180 MeV/c^2,
    // so these are set here)
    Bottom(std::string colour, double energy, double p_x, double p_y, double p_z) : Quark(0.333, colour, -0.333,
      "bottom", 4180, energy, p_x, p_y, p_z) {};

    // Deconstructor
    virtual ~Bottom() {};

    // Overriden clone function
    std::unique_ptr<Particle> clone() const {return std::make_unique<Bottom>(*this);}
};

#endif