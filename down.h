// PHYS 30762 Programming in C++
// Assignment 5

// Header including Down class

// Author: Linda Persley (student ID: 10683097)
// Date: 20/04/2024

#ifndef DOWN_H
#define DOWN_H

#include<iostream>
#include<string>

#include"particle.h"
#include"quark.h"

class Down : public Quark
{
  public:
    // Default constructor
    Down() : Quark() {};

    // Parameterised constructor (all down quarks have baryon number=1/3, charge=-1/3 and rest mass=4.7 MeV/c^2,
    // so this is set here)
    Down(std::string colour, double energy, double p_x, double p_y, double p_z) : Quark(0.333, colour, -0.333,
      "down", 4.7, energy, p_x, p_y, p_z) {};

    // Destructor
    virtual ~Down() {};

    // Overriden clone function
    std::unique_ptr<Particle> clone() const {return std::make_unique<Down>(*this);}
};

#endif