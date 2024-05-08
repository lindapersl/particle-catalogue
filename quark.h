// PHYS 30762 Programming in C++
// Project 2

// Header including Quark class

// Author: Linda Persley (student ID: 10683097)
// Date: 12/05/2024

#ifndef QUARK_H
#define QUARK_H

#include<iostream>
#include<memory>
#include<string>

#include"particle.h"

class Quark : public Particle
{
  protected:
    double baryon_number{};
    std::string colour_charge{"ghost"};


  public:
    // Default constructor
    Quark() : Particle() {};

    // Parameterised constructor
    Quark(double b_number, std::string colour, double charge, std::string type, double rest_mass, double energy, double p_x,
      double p_y, double p_z);

    // Destructor
    virtual ~Quark() {};

    // Setter functions
    void set_b_number(double b_number);
    void set_colour(std::string colour);

    // Getter functions
    double get_b_number() const {return baryon_number;}
    std::string get_colour() const {return colour_charge;}

    // Function to convert between particles and antiparticles
    virtual std::unique_ptr<Particle> convert_particle();

    // Overriden clone function
    virtual std::unique_ptr<Particle> clone() const {return std::make_unique<Quark>(*this);}

    // Print function
    virtual void print_info();
};

#endif