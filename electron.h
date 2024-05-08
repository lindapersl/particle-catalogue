// PHYS 30762 Programming in C++
// Assignment 5

// Header including Electron class

// Author: Linda Persley (student ID: 10683097)
// Date: 20/04/2024

#ifndef ELECTRON_H
#define ELECTRON_H

#include<iostream>
#include<vector>
#include<string>

#include"particle.h"
#include"lepton.h"

class Electron : public Lepton
{
  private:
    // Data members
    std::vector<double> deposited_energy{0, 0, 0, 0};
    
  public:
    // Default constructor
    Electron() : Lepton() {};

    // Parameterised constructor
    Electron(double layer_1, double layer_2, double layer_3, double layer_4, double energy, double p_x, double p_y, double p_z);

    // Copy constructor
    Electron(const Electron &original_lepton);

    // Move constructor
    Electron(Electron &&original_lepton);
    
    // Destructor
    virtual ~Electron() {};

    // Move assignment operator
    Electron& operator=(Electron &&original_lepton);

    // Copy assignment operator
    Electron& operator=(const Electron &original_lepton);

    // Getter functions
    double get_layer_1() const {return deposited_energy[0];}
    double get_layer_2() const {return deposited_energy[1];}
    double get_layer_3() const {return deposited_energy[2];}
    double get_layer_4() const {return deposited_energy[3];}
    std::vector<double> get_deposited_energy() const {return deposited_energy;}

    // Setter functions
    void set_deposited_energy(double layer_1, double layer_2, double layer_3, double layer_4);

    // Function to reset deposited energy values to zero regardless of electron's four momenta
    void reset_deposited_energy();

    // Overriden clone function
    std::unique_ptr<Particle> clone() const {return std::make_unique<Electron>(*this);}

    // Print function
    void print_info();
};

#endif