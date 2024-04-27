// PHYS 30762 Programming in C++
// Assignment 5

// Header including Neutrino class

// Author: Linda Persley (student ID: 10683097)
// Date: 20/04/2024

#ifndef NEUTRINO_H
#define NEUTRINO_H

#include<iostream>
#include<string>
#include<memory>

#include"particle.h"
#include"lepton.h"

class Neutrino : public Lepton
{
  private:
    // Data members
    bool interaction_info{};

  public:
    // Default constructor
    Neutrino() : Lepton() {std::cout<<"Default constructor called in Neutrino class for a "<<particle_type<<"."<<std::endl;}

    // Parameterised constructor
    Neutrino(bool interacted,int l_number, double charge, double spin, std::string type, double energy, double p_x, double p_y, double p_z) :
      Lepton(l_number, charge, spin, (type+" neutrino"), energy, p_x, p_y, p_z), interaction_info(interacted) {};

    // Deconstructor
    virtual ~Neutrino() {std::cout<<"Destructor called in Neutrino class for a "<<particle_type<<"."<<std::endl;}

    // Getter function
    bool get_interaction() const {return interaction_info;}

    // Setter function
    void set_interaction(bool interacted) {interaction_info=interacted;}

    // Print function
    void print_info();

    // Function to convert between particles and antiparticles
    std::unique_ptr<Particle> convert_particle();
};

#endif