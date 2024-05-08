// PHYS 30762 Programming in C++
// Assignment 5

// Implementation of Electron class member functions

// Author: Linda Persley (student ID: 10683097)
// Date: 20/04/2024

#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>

#include"particle.h"
#include"lepton.h"
#include"electron.h"

// Parameterised constructor (all electrons have lepton number=1, charge=-1 and rest mass=0.511 MeV/c^2 so these are set here)
Electron::Electron(double layer_1, double layer_2, double layer_3, double layer_4, double energy, double p_x, double p_y,
  double p_z) : Lepton(1, -1, "electron", 0.511, energy, p_x, p_y, p_z)
{
  set_deposited_energy(layer_1, layer_2, layer_3, layer_4);  // Input checking done within setter function
}

// Copy constructor
Electron::Electron(const Electron &original_lepton) : Lepton(original_lepton)
{
  // Copying data members of the original particle
  deposited_energy=original_lepton.deposited_energy;
}

// Move constructor
Electron::Electron(Electron &&original_lepton) : Lepton(std::move(original_lepton))
{
  // Move data of the original particle to a new particle
  deposited_energy=std::move(original_lepton.deposited_energy);

  // Resets data members of the original particle
  original_lepton.reset_deposited_energy();
}

// Move assignment operator
Electron& Electron::operator=(Electron &&original_lepton)
{
  // Avoiding self-assignment
  if(&original_lepton==this)
  {
    std::cerr<<"Self-assignment detected, hence move assignment was not performed in"
    <<" Electron class for a "<<particle_type<<"."<<std::endl;


    return *this;
  }

  else
  {
    // Calling the equivalent base class operator
    Particle::operator=(std::move(original_lepton));

    // Move data of the original particle to a new particle
    deposited_energy=std::move(original_lepton.deposited_energy);
    
    // Resets data members of the original particle
    original_lepton.reset_deposited_energy();
  
    return *this;
  }
}

// Copy assignment operator
Electron& Electron::operator=(const Electron &original_lepton)
{
  // Avoiding self-assignment
  if(&original_lepton==this)
  {
    std::cerr<<"Self-assignment detected, hence copy assignment was not performed in Electron class for a "
    <<particle_type<<"."<<std::endl;

    return *this;
  }

  else
  {
    // Calling the equivalent base class operator
    Particle::operator=(original_lepton);

    // Copying data members of the original particle
    deposited_energy=original_lepton.deposited_energy;
  
    return *this;
  }
}

void Electron::set_deposited_energy(double layer_1, double layer_2, double layer_3, double layer_4)
{
  double total_energy_deposited{layer_1+layer_2+layer_3+layer_4};

  // Ensuring the sum of the energies deposited in each layer adds up to the total energy the particle carries
  if(total_energy_deposited==(four_momentum_ptr->get_energy()))
  {
    deposited_energy[0]=layer_1;
    deposited_energy[1]=layer_2;
    deposited_energy[2]=layer_3;
    deposited_energy[3]=layer_4;
  }

  else
  {
    std::cerr<<"The total energy deposited in the calorimeter layers is not equal to the energy of"
      <<" the electron in the four-momentum. A correct energy distribution is going to be set for you"
        <<" preserving the ratio of energies you inputted."<<std::endl;

    // Preserving the energy ratio chosen by the user
    double layer_1_ratio{layer_1/total_energy_deposited};
    double layer_2_ratio{layer_2/total_energy_deposited};
    double layer_3_ratio{layer_3/total_energy_deposited};
    double layer_4_ratio{layer_4/total_energy_deposited};

    deposited_energy[0]=layer_1_ratio*(four_momentum_ptr->get_energy());
    deposited_energy[1]=layer_2_ratio*(four_momentum_ptr->get_energy());
    deposited_energy[2]=layer_3_ratio*(four_momentum_ptr->get_energy());
    deposited_energy[3]=layer_4_ratio*(four_momentum_ptr->get_energy());
  }
}

// Function to reset deposited energy values to zero regardless of electron's four momenta
void Electron::reset_deposited_energy()
{
  deposited_energy[0]=0;
  deposited_energy[1]=0;
  deposited_energy[2]=0;
  deposited_energy[3]=0;
}

// Print function
void Electron::print_info()
{
  if(four_momentum_ptr!=nullptr)
  {
    // Calling the equivalent lepton class function
    Lepton::print_info();
    
    std::cout<<std::left<<std::setfill('.')<<std::setw(25)<<"Deposited energy in calorimeter layers = "
      <<std::right<<std::setfill('.')<<std::setw(8)<<"("<<deposited_energy[0]<<", "<<deposited_energy[1]<<", "<<
        deposited_energy[2]<<", "<<deposited_energy[3]<<") MeV"<<std::endl;
  }

  else
  {
    std::cerr<<"The four momentum pointer is a null pointer, hence information about the "<<particle_type<<
      "'s four momentum cannot be printed."<<std::endl;
  }
}