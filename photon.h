// PHYS 30762 Programming in C++
// Assignment 5

// Header including Photon class

// Author: Linda Persley (student ID: 10683097)
// Date: 20/04/2024

#ifndef PHOTON_H
#define PHOTON_H

#include<iostream>
#include<string>

#include"particle.h"
#include"gauge_boson.h"

class Photon : public GaugeBoson
{
  public:
    // Default constructor
    Photon() : GaugeBoson() {};

    // Parameterised constructor (all photons have charge=0 and rest mass=0 MeV,
    // so these are set here)
    Photon(double energy, double p_x, double p_y, double p_z) : GaugeBoson(0, "photon", 0, energy,
      p_x, p_y, p_z) {};

    // Destructor
    virtual ~Photon() {};

    // Overriden clone function
    std::unique_ptr<Particle> clone() const {return std::make_unique<Photon>(*this);}
};

#endif