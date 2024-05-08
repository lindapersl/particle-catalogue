// PHYS 30762 Programming in C++
// Project 2

// Header including Particle class

// Author: Linda Persley (student ID: 10683097)
// Date: 12/05/2024

#ifndef PARTICLE_H
#define PARTICLE_H

#include<iostream>
#include<memory>
#include<string>
#include<vector>

#include"four_momentum.h"

class Particle
{
  protected:
    //Data members
    double particle_charge{};
    double particle_spin{};
    std::string particle_type{"ghost"};
    double rest_mass_energy{};
    std::unique_ptr<FourMomentum> four_momentum_ptr{nullptr};

  public:
    // Default constructor
    Particle() {};

    // Parameterised constructor
    Particle(double charge, double spin, std::string type, double rest_mass, double energy, double p_x, double p_y, double p_z);

    // Copy constructor
    Particle(const Particle &original_Particle);

    // Move constructor
    Particle(Particle &&original_Particle);

    // Destructor
    virtual ~Particle() {};

    // Move assignment operator
    virtual Particle& operator=(Particle &&original_Particle);

    // Copy assignment operator
    virtual Particle& operator=(const Particle &original_Particle);

    // Setter function
    void set_charge(double charge) {particle_charge=charge;}
    void set_spin(double spin) {particle_spin=spin;}
    void set_type(std::string type) {particle_type=type;}
    void set_rest_mass(double rest_mass) {rest_mass_energy=rest_mass;}
    void set_four_momentum_ptr(std::unique_ptr<FourMomentum> four_mom_ptr) {four_momentum_ptr=std::move(four_mom_ptr);}

    // Getter functions
    double get_charge() const {return particle_charge;}
    double get_spin() const {return particle_spin;}
    std::string get_type() const {return particle_type;}
    double get_rest_mass() const {return rest_mass_energy;}
    const std::unique_ptr<FourMomentum>& get_four_momentum_ptr() const {return four_momentum_ptr;}

    // Function to convert between particles and antiparticles
    virtual std::unique_ptr<Particle> convert_particle()=0;

    // Pure virtual clone function to enable copying of data members involving unique pointers to the abstract
    // base class inside the copy constructors of derived classes.
    virtual std::unique_ptr<Particle> clone() const=0;

    // Print function
    virtual void print_info();

    // Friend function: overloaded sum operator of four-momentum
    friend std::vector<double> operator+(const std::vector<double>& four_momentum_vector, const Particle& particle_1);

    // Friend function: overloaded subtraction operator of four-momentum
    friend std::vector<double> operator-(const Particle& particle_1, const Particle& particle_2);

    // Friend function: (relativistic) dot product of four-momentum
    friend double dotProduct(const Particle& particle_1, const Particle& particle_2);
};

#endif