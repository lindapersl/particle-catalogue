// PHYS 30762 Programming in C++
// Assignment 5

// Header including ZBoson class

// Author: Linda Persley (student ID: 10683097)
// Date: 20/04/2024

#ifndef ZBOSON_H
#define ZBOSON_H

#include<iostream>
#include<vector>
#include<string>
#include<memory>

#include"particle.h"
#include"gauge_boson.h"

class ZBoson : public GaugeBoson
{
  private:
    // Data member
    std::vector<std::unique_ptr<Particle>> decay_products;

  public:
    // Default constructor
    ZBoson() : GaugeBoson() {std::cout<<"Default constructor called in ZBoson class for a "<<particle_type<<"."<<std::endl;}

    // Parameterised contructor
    ZBoson(std::unique_ptr<Particle> particle_1, std::unique_ptr<Particle> particle_2, double energy, double p_x, double p_y, double p_z);

    // Copy constructor
    ZBoson(const ZBoson &original_boson);

    // Move constructor
    ZBoson(ZBoson &&original_boson);

    // Deconstructor
    virtual ~ZBoson() {std::cout<<"Destructor called in ZBoson class for a "<<particle_type<<"."<<std::endl;}

    // Move assignment operator
    ZBoson& operator=(ZBoson &&original_boson);

    // Copy assignment operator
    ZBoson& operator=(const ZBoson &original_boson);

    // Getter functions
    std::vector<std::unique_ptr<Particle>> const& get_products() const {return decay_products;}

    // Setter function
    void set_products(std::unique_ptr<Particle> particle_1, std::unique_ptr<Particle> particle_2);

    // Overriden clone function
    std::unique_ptr<Particle> clone() const {return std::make_unique<ZBoson>(*this);}

    // Print function
    void print_info();
};

#endif