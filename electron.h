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

#include"lepton.h"

class Electron : public Lepton
{
  private:
    // Data members
    double energy_em_1{};
    double energy_em_2{};
    double energy_had_1{};
    double energy_had_2{};
    std::vector<double> deposited_energy{0, 0, 0, 0};
    
  public:
    // Default constructor
    Electron() : Lepton() {std::cout<<"Default constructor called in Electron class for a "<<particle_type<<"."<<std::endl;}

    // Parameterised constructor
    Electron(double em_1, double em_2, double had_1, double had_2, int l_number, double charge, double spin, std::string type,
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
    double get_em_1() const {return energy_em_1;}
    double get_em_2() const {return energy_em_2;}
    double get_had_1() const {return energy_had_1;}
    double get_had_2() const {return energy_had_2;}
    std::vector<double> get_deposited_energy() const {return deposited_energy;}

    // Setter functions
    void set_em_1(double em_1);
    void set_em_2(double em_2);
    void set_had_1(double had_1);
    void set_had_2(double had_2);
    void set_deposited_energy(double em_1, double em_2, double had_1, double had_2);

    // Print function
    void print_info();
};

#endif