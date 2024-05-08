// PHYS 30762 Programming in C++
// Assignment 5

// Header including Charm class

// Author: Linda Persley (student ID: 10683097)
// Date: 20/04/2024

#ifndef CHARM_H
#define CHARM_H

#include<iostream>
#include<string>

#include"particle.h"
#include"quark.h"

class Charm : public Quark
{
  public:
    // Default constructor
    Charm() : Quark() {};

    // Parameterised constructor (all charm quarks have baryon number=1/3, charge=2/3 and rest mass=1280 MeV/c^2
    // so this is set here)
    Charm(std::string colour, double energy, double p_x, double p_y, double p_z) : Quark(0.333, colour, 0.667,
      "charm", 1280, energy, p_x, p_y, p_z) {};

    // Deconstructor
    virtual ~Charm() {};

    // Overriden clone function
    std::unique_ptr<Particle> clone() const {return std::make_unique<Charm>(*this);}
};

#endif