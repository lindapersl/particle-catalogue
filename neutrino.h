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
    std::string neutrino_flavour{"ghost"};

  public:
    // Default constructor
    Neutrino() : Lepton() {std::cout<<"Default constructor called in Neutrino class for a "<<particle_type<<"."<<std::endl;}

    // Parameterised constructor
    Neutrino(bool interacted, std::string flavour, int l_number, double charge, double spin, double energy, double p_x, double p_y, double p_z) :
      Lepton(l_number, charge, spin, (flavour+" neutrino"), energy, p_x, p_y, p_z), interaction_info(interacted), neutrino_flavour(flavour) {};

    // Deconstructor
    virtual ~Neutrino() {std::cout<<"Destructor called in Neutrino class for a "<<particle_type<<"."<<std::endl;}

    // Getter function
    bool get_interaction() const {return interaction_info;}
    std::string get_flavour() const {return neutrino_flavour;}

    // Setter function
    void set_interaction(bool interacted) {interaction_info=interacted;}
    void set_flavour(std::string flavour) {neutrino_flavour=flavour;}

    // Function to convert between particles and antiparticles
    std::unique_ptr<Particle> convert_particle();

    // Overriden clone function
    std::unique_ptr<Particle> clone() const {return std::make_unique<Neutrino>(*this);} ///// check for self assessment?

    // Print function
    void print_info();


};

#endif