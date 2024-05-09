// PHYS 30762 Programming in C++
// Assignment 5

// Header including Gluon class

// Author: Linda Persley (student ID: 10683097)
// Date: 20/04/2024

#ifndef GLUON_H
#define GLUON_H

#include<iostream>
#include<string>

#include"particle.h"
#include"gauge_boson.h"

class Gluon : public GaugeBoson
{
  private:
    std::string colour_charge_1{"ghost"};
    std::string colour_charge_2{"ghost"};

  public:
    // Default constructor
    Gluon() : GaugeBoson() {}

    // Parameterised constructor
    Gluon(std::string colour_1, std::string colour_2, double energy, double p_x, double p_y, double p_z);

    // Destructor
    virtual ~Gluon() {};

    // Setter function
    void set_colours(std::string colour_1, std::string colour_2);

    // Getter functions
    std::string get_colour_1() const {return colour_charge_1;}
    std::string get_colour_2() const {return colour_charge_2;}

    // Function to convert between particles and antiparticles
    std::unique_ptr<Particle> convert_particle();

    // Overriden clone function
    std::unique_ptr<Particle> clone() const {return std::make_unique<Gluon>(*this);}

    // Print function
    void print_info();
};

#endif