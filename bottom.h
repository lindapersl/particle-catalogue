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
  private:

  protected:

  public:
    // Default constructor
    Bottom() : Quark() {std::cout<<"Default constructor called in Bottom class for a "
      <<particle_type<<"."<<std::endl;}

    // Parameterised constructor
    Bottom(double b_number, std::string colour, double charge, double spin, double energy, double p_x,
      double p_y, double p_z) : Quark(b_number, colour, charge, spin, "bottom", energy, p_x, p_y, p_z) {};

    // Deconstructor
    virtual ~Bottom() {std::cout<<"Destructor called in Bottom class for a "<<particle_type<<"."<<std::endl;}

    // Overriden clone function
    std::unique_ptr<Particle> clone() const {return std::make_unique<Bottom>(*this);}
};

#endif