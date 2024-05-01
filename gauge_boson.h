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
  private:

  protected:

  public:
    // Default constructor
    GaugeBoson() : Particle() {std::cout<<"Default constructor called in GaugeBoson class for a "<<particle_type<<"."<<std::endl;}

    // Parameterised constructor
    GaugeBoson(double charge, double spin, std::string type, double energy, double p_x, double p_y, double p_z) : Particle(charge, spin,
      type, energy, p_x, p_y, p_z) {};

    // Destructor
    virtual ~GaugeBoson() {std::cout<<"Destructor called in GaugeBoson class for a "<<particle_type<<"."<<std::endl;}

    // Overriden clone function
    virtual std::unique_ptr<Particle> clone() const {return std::make_unique<GaugeBoson>(*this);}

    // Function to convert between particles and antiparticles (Not all gauge bosons have an antiparticle, thus a clone of its particle is returned.
    // The function should be overridden in derived classes of particles that do have a corresponding antiparticle.)
    virtual std::unique_ptr<Particle> convert_particle() {return this->clone();}

    // // Print function
    // virtual void print_info() {}
};

#endif