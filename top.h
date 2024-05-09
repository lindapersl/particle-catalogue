// PHYS 30762 Programming in C++
// Assignment 5

// Header including Top class

// Author: Linda Persley (student ID: 10683097)
// Date: 20/04/2024

#ifndef TOP_H
#define TOP_H

#include<iostream>
#include<string>

#include"particle.h"
#include"quark.h"

class Top : public Quark
{
  public:
    // Default constructor
    Top() : Quark() {};

    // Parameterised constructor (ll top quarks have baryon number=1/3, charge=2/3 and rest mass=173100 MeV/c^2,
    // so these are set here)
    Top(std::string colour, double energy, double p_x, double p_y, double p_z) : Quark(0.333, colour, 0.667,
      "top", 173100, energy, p_x, p_y, p_z) {};

    // Destructor
    virtual ~Top() {};

    // Overriden clone function
    std::unique_ptr<Particle> clone() const {return std::make_unique<Top>(*this);}
};

#endif