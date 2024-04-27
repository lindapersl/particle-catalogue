// PHYS 30762 Programming in C++
// Assignment 5

// Header including Tau class

// Author: Linda Persley (student ID: 10683097)
// Date: 20/04/2024

#ifndef TAU_H
#define TAU_H

#include<iostream>
#include<vector>
#include<string>
#include<memory>

#include"particle.h"
#include"lepton.h"

class Tau : public Lepton
{
  private:
    // Data member
    std::vector<std::unique_ptr<Particle>> decay_products;

  public:
    // Default constructor
    Tau() : Lepton() {std::cout<<"Default constructor called in Tau class for a "<<particle_type<<"."<<std::endl;}

    // Parameterised contructor
    Tau(std::unique_ptr<Particle> particle_1, std::unique_ptr<Particle> particle_2, std::unique_ptr<Particle> particle_3,
      int l_number, double charge, double spin, std::string type, double energy, double p_x, double p_y, double p_z);

    // Copy constructor
    Tau(const Tau &original_lepton);

    // Move constructor
    Tau(Tau &&original_lepton);

    // Deconstructor
    virtual ~Tau() {std::cout<<"Destructor called in Tau class for a "<<particle_type<<"."<<std::endl;}

    // Move assignment operator
    Tau& operator=(Tau &&original_lepton);

    // Copy assignment operator
    Tau& operator=(const Tau &original_lepton);

    // Getter functions
    std::vector<std::unique_ptr<Particle>> const& get_products() const {return decay_products;}

    // Setter function
    void set_products(std::unique_ptr<Particle> particle_1, std::unique_ptr<Particle> particle_2, std::unique_ptr<Particle> particle_3);

    // Print function
    void print_info();
};

#endif