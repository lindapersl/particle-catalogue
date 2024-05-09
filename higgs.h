// PHYS 30762 Programming in C++
// Assignment 5

// Header including Higgs class

// Author: Linda Persley (student ID: 10683097)
// Date: 20/04/2024

#ifndef HIGGS_H
#define HIGGS_H

#include<iostream>
#include<vector>
#include<string>
#include<memory>

#include"particle.h"

class Higgs : public Particle
{
  private:
    // Data member
    std::vector<std::unique_ptr<Particle>> decay_products;

  public:
    // Default constructor
    Higgs() : Particle() {};

    // Parameterised contructor
    Higgs(std::unique_ptr<Particle> particle_1, std::unique_ptr<Particle> particle_2, double energy, double p_x, double p_y, double p_z);

    // Copy constructor
    Higgs(const Higgs &original_boson);

    // Move constructor
    Higgs(Higgs &&original_boson);

    // Deconstructor
    virtual ~Higgs() {};

    // Move assignment operator
    Higgs& operator=(Higgs &&original_boson);

    // Copy assignment operator
    Higgs& operator=(const Higgs &original_boson);

    // Getter functions
    std::vector<std::unique_ptr<Particle>> const& get_products() const {return decay_products;}
  
    // Overridden getter functions that have no meaning in Higgs class
    int get_l_number() const {return 0;}
    double get_b_number() const {return 0;}

    // Setter function
    void set_products(std::unique_ptr<Particle> particle_1, std::unique_ptr<Particle> particle_2);

    // Function to convert between particles and antiparticles (The Higgs doesn't have an antiparticle,
    // thus a clone of its particle is returned as this should be overridden here.)
    std::unique_ptr<Particle> convert_particle() {return std::make_unique<Higgs>(*this);}

    // Overriden clone function
    std::unique_ptr<Particle> clone() const {return std::make_unique<Higgs>(*this);}

    // Print function
    void print_info();
};

#endif