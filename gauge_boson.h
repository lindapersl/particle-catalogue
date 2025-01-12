// PHYS 30762 Programming in C++
// Project 2

// Header including GaugeBoson class

// Author: Linda Persley (student ID: 10683097)
// Date: 12/05/2024

#ifndef GAUGEBOSON_H
#define GAUGEBOSON_H

#include<iostream>
#include<string>
#include<memory>

#include"particle.h"

class GaugeBoson : public Particle
{
  public:
    // Default constructor
    GaugeBoson() : Particle() {};

    // Parameterised constructor (all gauge bosons are spin-1 particles, so this is set here)
    GaugeBoson(double charge, std::string type, double rest_mass, double energy, double p_x, double p_y, double p_z) :
      Particle(charge, 1, type, rest_mass, energy, p_x, p_y, p_z) {};

    // Destructor
    virtual ~GaugeBoson() {};
  
    // Overridden getter functions that have no meaning in gauge boson class
    int get_l_number() const {return 0;}
    double get_b_number() const {return 0;}

    // Overriden clone function
    virtual std::unique_ptr<Particle> clone() const {return std::make_unique<GaugeBoson>(*this);}

    // Function to convert between particles and antiparticles (Not all gauge bosons have an antiparticle,
    // thus a clone of its particle is returned as this should be overridden here.)
    virtual std::unique_ptr<Particle> convert_particle() {return std::make_unique<GaugeBoson>(*this);}
};

#endif