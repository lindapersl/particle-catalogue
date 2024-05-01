// PHYS 30762 Programming in C++
// Assignment 5

// Header including Strange class

// Author: Linda Persley (student ID: 10683097)
// Date: 20/04/2024

#ifndef STRANGE_H
#define STRANGE_H

#include<iostream>
#include<string>

#include"particle.h"
#include"quark.h"

class Strange : public Quark
{
  private:

  protected:

  public:
    // Default constructor
    Strange() : Quark() {std::cout<<"Default constructor called in Strange class for a "
      <<particle_type<<"."<<std::endl;}

    // Parameterised constructor (all strange quarks have baryon number=1/3, charge=-1/3 and rest mass=96 MeV/c^2 so these are set here)
    Strange(std::string colour, double energy, double p_x, double p_y, double p_z) : Quark(0.333, colour, -0.333,
      "strange", 96, energy, p_x, p_y, p_z) {};

    // Deconstructor
    virtual ~Strange() {std::cout<<"Destructor called in Strange class for a "<<particle_type<<"."<<std::endl;}

    // Overriden clone function
    std::unique_ptr<Particle> clone() const {return std::make_unique<Strange>(*this);}
};

#endif