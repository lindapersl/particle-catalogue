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
    // double energy_layer_1{};
    // double energy_layer_2{};
    // double energy_layer_3{};
    // double energy_layer_4{};
    std::vector<double> deposited_energy{0, 0, 0, 0};
    
  public:
    // Default constructor
    Electron() : Lepton() {std::cout<<"Default constructor called in Electron class for a "<<particle_type<<"."<<std::endl;}

    // Parameterised constructor
    Electron(double layer_1, double layer_2, double layer_3, double layer_4, int l_number, double charge, double spin,
      double energy, double p_x, double p_y, double p_z);

    // Copy constructor
    Electron(const Electron &original_lepton);

    // Move constructor
    Electron(Electron &&original_lepton);
    
    // Destructor
    virtual ~Electron() {std::cout<<"Destructor called in Electron class for a "<<particle_type<<"."<<std::endl;}

    // Move assignment operator
    Electron& operator=(Electron &&original_lepton);

    // Copy assignment operator
    Electron& operator=(const Electron &original_lepton);

    // Getter functions
    // double get_layer_1() const {return energy_layer_1;}
    // double get_layer_2() const {return energy_layer_2;}
    // double get_layer_3() const {return energy_layer_3;}
    // double get_layer_4() const {return energy_layer_4;} ////// can return element of deposited energy?
    std::vector<double> get_deposited_energy() const {return deposited_energy;}

    // Setter functions
    // void set_layer_1(double layer_1);
    // void set_layer_2(double layer_2);
    // void set_layer_3(double layer_3);
    // void set_layer_4(double layer_4);
    void set_deposited_energy(double layer_1, double layer_2, double layer_3, double layer_4);

    // Overriden clone function
    std::unique_ptr<Particle> clone() const {return std::make_unique<Electron>(*this);}

    // Print function
    void print_info();
};

#endif