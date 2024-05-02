// PHYS 30762 Programming in C++
// Project 2

// Header including four momentum class

// Author: Linda Persley (student ID: 10683097)
// Date: 12/05/2024

#ifndef FOUR_MOMENTUM_H
#define FOUR_MOMENTUM_H

#include<iostream>
#include<vector>
#include<utility>

class FourMomentum
{
  private:
    // Data members
    double invariant_mass{};
    double particle_energy{};
    double momentum_x{};
    double momentum_y{};
    double momentum_z{};
    std::vector<double> four_momentum_vector{0, 0, 0, 0};

  public:
    // Default constructor
    FourMomentum() {};

    // Parameterised constructor
    FourMomentum(double rest_mass, double energy, double p_x, double p_y, double p_z);

    // Copy constructor
    FourMomentum(const FourMomentum &original_four_momentum);

    // Move constructor
    FourMomentum(FourMomentum &&original_four_momentum);

    // Destructor
    ~FourMomentum() {};

    // Move assignment operator
    FourMomentum& operator=(FourMomentum &&original_four_momentum);

    // Copy assignment operator
    FourMomentum& operator=(const FourMomentum &original_four_momentum);

    // Getter functions
    double get_invariant_mass() const {return invariant_mass;}
    double get_energy() const {return particle_energy;} 
    double get_momentum_x() const {return momentum_x;}
    double get_momentum_y() const {return momentum_y;}
    double get_momentum_z() const {return momentum_z;}
    //////std::vector<double> get_four_momentum() const {return four_momentum_vector;}

    // Setter functions
    void set_invariant_mass(double mass) {invariant_mass=mass;}
    // void set_energy(double energy) {particle_energy=energy;}
    // void set_momentum_x(double p_x) {momentum_x=p_x;}
    // void set_momentum_y(double p_y) {momentum_y=p_y;}
    // void set_momentum_z(double p_z) {momentum_z=p_z;}
    void set_four_momentum(double rest_mass, double energy, double p_x, double p_y, double p_z);

    // Function to calculate invariant mass
    std::pair<double, bool> invariant_mass_calculator(double rest_mass);

    // Oerloaded sum operator of two four-momenta
    ////std::vector<double> operator+(const FourMomentum& other_particle);

    // Overloaded dot product of two four-momenta
    /////double dotProduct(const FourMomentum& other_particle);
};

#endif