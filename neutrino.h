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
    Neutrino() : Lepton() {};

    // Parameterised constructor (all neutrinos have lepton number=1, charge=0 and rest mass=0 so these are set here)
    Neutrino(bool interacted, std::string flavour, double energy, double p_x, double p_y, double p_z);

    // Deconstructor
    virtual ~Neutrino() {};

    // Getter function
    bool get_interaction() const {return interaction_info;}
    std::string get_flavour() const {return neutrino_flavour;}

    // Setter function
    void set_interaction(bool interacted) {interaction_info=interacted;}
    void set_flavour(std::string flavour);

    // Function to convert between particles and antiparticles
    std::unique_ptr<Particle> convert_particle();

    // Overriden clone function
    std::unique_ptr<Particle> clone() const {return std::make_unique<Neutrino>(*this);}

    // Print function
    void print_info();


};

#endif