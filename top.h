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

    // Parameterised constructor
    Top(double b_number, std::string colour, double charge, double spin, double energy, double p_x,
      double p_y, double p_z) : Quark(b_number, colour, charge, spin, "top", energy, p_x, p_y, p_z) {};

    // Deconstructor
    virtual ~Top() {std::cout<<"Destructor called in Top class for a "<<particle_type<<"."<<std::endl;}

    // Overriden clone function
    std::unique_ptr<Particle> clone() const {return std::make_unique<Top>(*this);}
};

#endif