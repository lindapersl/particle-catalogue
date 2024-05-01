// PHYS 30762 Programming in C++
// Assignment 5

// Header including Muon class

// Author: Linda Persley (student ID: 10683097)
// Date: 20/04/2024

#ifndef MUON_H
#define MUON_H

#include<iostream>
#include<string>

#include"particle.h"
#include"lepton.h"

class Muon : public Lepton
{
  private:
    // Data member
    bool isolation_info{}; // False = not isolated, true = isolated

  public:
    // Default constructor
    Muon() : Lepton() {std::cout<<"Default constructor called in Muon class for a "
      <<particle_type<<"."<<std::endl;}

    // Parameterised constructor (all muons have lepton number=1, charge=-1 and rest mass=105.66 MeV/c^2 so these are set here)
    Muon(bool isolated, double energy, double p_x, double p_y, double p_z) : Lepton(1, -1, "muon", 105.66, energy, p_x, p_y, p_z),
      isolation_info(isolated) {};

    // Deconstructor
    virtual ~Muon() {std::cout<<"Destructor called in Muon class for a "<<particle_type<<"."<<std::endl;}

    // Getter function
    bool get_isolation() const {return isolation_info;}

    // Setter function
    void set_isolation(bool isolated) {isolation_info=isolated;}

    // Overriden clone function
    std::unique_ptr<Particle> clone() const {return std::make_unique<Muon>(*this);}

    // Print function
    void print_info();
};

#endif