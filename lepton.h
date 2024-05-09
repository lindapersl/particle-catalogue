// PHYS 30762 Programming in C++
// Project 2

// Header including Lepton class

// Author: Linda Persley (student ID: 10683097)
// Date: 12/05/2024

#ifndef LEPTON_H
#define LEPTON_H

#include<iostream>
#include<memory>
#include<string>

#include"particle.h"

class Lepton : public Particle
{
  protected:
    int lepton_number{};

  public:
    // Default constructor
    Lepton() : Particle() {};

    // Parameterised constructor
    Lepton(int l_number, double charge, std::string type, double rest_mass, double energy, double p_x, double p_y, double p_z);

    // Destructor
    virtual ~Lepton() {};

    // Setter function
    void set_l_number(int l_number);

    // Getter functions
    int get_l_number() const {return lepton_number;}

    // Overridden getter function that has no meaning in lepton class
    double get_b_number() const {return 0;}

    // Function to convert between particles and antiparticles
    virtual std::unique_ptr<Particle> convert_particle();

    // Overriden clone function
    virtual std::unique_ptr<Particle> clone() const {return std::make_unique<Lepton>(*this);}

    // Print function
    virtual void print_info();
};

#endif