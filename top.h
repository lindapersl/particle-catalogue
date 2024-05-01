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
  private:

  protected:

  public:
    // Default constructor
    Top() : Quark() {std::cout<<"Default constructor called in Top class for a "
      <<particle_type<<"."<<std::endl;}

    // Parameterised constructor (ll top quarks have baryon number=1/3, charge=2/3 and rest mass=173100 MeV/c^2, so these are set here)
    Top(std::string colour, double energy, double p_x, double p_y, double p_z) : Quark(0.333, colour, 0.667,
      "top", 173100, energy, p_x, p_y, p_z) {};

    // Deconstructor
    virtual ~Top() {std::cout<<"Destructor called in Top class for a "<<particle_type<<"."<<std::endl;}

    // Overriden clone function
    std::unique_ptr<Particle> clone() const {return std::make_unique<Top>(*this);}
};

#endif