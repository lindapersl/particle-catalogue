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
  private:

  protected:
  int lepton_number{};

  public:
    // Default constructor
    Lepton() : Particle() {std::cout<<"Default constructor called in Lepton class for a "<<particle_type<<"."<<std::endl;}

    // Parameterised constructor
    Lepton(int l_number, double charge, double spin, std::string type, double energy, double p_x, double p_y, double p_z);

    // // Copy constructor
    // Lepton(const Lepton &original_lepton);

    // // Move constructor
    // Lepton(Lepton &&original_lepton);

    // Destructor
    virtual ~Lepton() {std::cout<<"Destructor called in Lepton class for a "<<particle_type<<"."<<std::endl;}

    // // Move assignment operator
    // virtual Lepton& operator=(Lepton &&original_lepton);

    // // Copy assignment operator
    // virtual Lepton& operator=(const Lepton &original_lepton);

    // Setter function
    void set_l_number(int l_number);

    // Getter functions
    int get_l_number() const {return lepton_number;}

    // Function to convert between particles and antiparticles
    virtual std::unique_ptr<Particle> convert_particle();

    // Overriden clone function
    virtual std::unique_ptr<Particle> clone() const {return std::make_unique<Lepton>(*this);}

    // Print function
    virtual void print_info();
};

#endif