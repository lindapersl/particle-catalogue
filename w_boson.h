// PHYS 30762 Programming in C++
// Assignment 5

// Header including WBoson class

// Author: Linda Persley (student ID: 10683097)
// Date: 20/04/2024

#ifndef WBOSON_H
#define WBOSON_H

#include<iostream>
#include<vector>
#include<string>
#include<memory>

#include"particle.h"
#include"gauge_boson.h"

class WBoson : public GaugeBoson
{
  private:
    // Data member
    std::vector<std::unique_ptr<Particle>> decay_products;

  public:
    // Default constructor
    WBoson() : GaugeBoson() {};

    // Parameterised contructor
    WBoson(std::unique_ptr<Particle> particle_1, std::unique_ptr<Particle> particle_2, double energy,
      double p_x, double p_y, double p_z);

    // Copy constructor
    WBoson(const WBoson &original_boson);

    // Move constructor
    WBoson(WBoson &&original_boson);

    // Destructor
    virtual ~WBoson() {};

    // Move assignment operator
    WBoson& operator=(WBoson &&original_boson);

    // Copy assignment operator
    WBoson& operator=(const WBoson &original_boson);

    // Getter functions
    std::vector<std::unique_ptr<Particle>> const& get_products() const {return decay_products;}

    // Setter function
    void set_products(std::unique_ptr<Particle> particle_1, std::unique_ptr<Particle> particle_2);

    // Function to convert between particles and antiparticles
    std::unique_ptr<Particle> convert_particle();

    // Overriden clone function
    std::unique_ptr<Particle> clone() const {return std::make_unique<WBoson>(*this);}

    // Print function
    void print_info();
};

#endif