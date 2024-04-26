// PHYS 30762 Programming in C++
// Assignment 5

// Implementation of Electron class member functions

// Author: Linda Persley (student ID: 10683097)
// Date: 20/04/2024

#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>

#include"lepton.h"
#include"electron.h"

// Parameterised constructor
Electron::Electron(double em_1, double em_2, double had_1, double had_2, int l_number, double charge, double spin, std::string type,
  double energy, double p_x, double p_y, double p_z) : Lepton(l_number, charge, spin, type, energy, p_x, p_y, p_z)
{
  set_deposited_energy(em_1, em_2, had_1, had_2);  // Input checking done within setter function
}

// Copy constructor
Electron::Electron(const Electron &original_lepton) : Lepton(original_lepton)
{
  // Copying data members of the original particle
  energy_em_1=original_lepton.energy_em_1;
  energy_em_2=original_lepton.energy_em_2;
  energy_had_1=original_lepton.energy_had_1;
  energy_had_2=original_lepton.energy_had_2;
  deposited_energy=std::move(original_lepton.deposited_energy);

  std::cout<<"Copy constructor called in Electron class for a "<<particle_type<<"."<<std::endl;
}

// Move constructor
Electron::Electron(Electron &&original_lepton) : Lepton(std::move(original_lepton))
{
  // Move data of the original particle to a new particle
  energy_em_1=original_lepton.energy_em_1;
  energy_em_2=original_lepton.energy_em_2;
  energy_had_1=original_lepton.energy_had_1;
  energy_had_2=original_lepton.energy_had_2;
  deposited_energy=std::move(original_lepton.deposited_energy);

  // Resets data members of the original particle
  original_lepton.set_deposited_energy(0, 0, 0, 0);

  std::cout<<"Move constructor called in Electron class for a "<<particle_type<<"."<<std::endl;
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
    Lepton::operator=(std::move(original_lepton));

    // Move data of the original particle to a new particle
    energy_em_1=original_lepton.energy_em_1;
    energy_em_2=original_lepton.energy_em_2;
    energy_had_1=original_lepton.energy_had_1;
    energy_had_2=original_lepton.energy_had_2;
    deposited_energy=std::move(original_lepton.deposited_energy);
    
    // Resets data members of the original particle
    original_lepton.set_deposited_energy(0, 0, 0, 0);

    std::cout<<"Move assignment called in Electron class for a "<<particle_type<<"."<<std::endl;
  
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
    Lepton::operator=(original_lepton);

    // Copying data members of the original particle
    energy_em_1=original_lepton.energy_em_1;
    energy_em_2=original_lepton.energy_em_2;
    energy_had_1=original_lepton.energy_had_1;
    energy_had_2=original_lepton.energy_had_2;
    deposited_energy=std::move(original_lepton.deposited_energy);

    std::cout<<"Copy assignment called in Electron class for a "<<particle_type<<"."<<std::endl;
  
    return *this;
  }
}

// Setter functions
// void Electron::set_em_1(double em_1)
// {
//   double total_energy_deposited{em_1+energy_em_2+energy_had_1+energy_had_2};

//   if(total_energy_deposited==(four_momentum_ptr->get_energy()))
//   {
//     energy_em_1=em_1;
//   }

//   else
//   {
//     std::cout<<"The total energy deposited in the calorimeter layers is not equal to the energy of"
//       <<" the electron in the 4-vector. A correct energy distribution is going to be set for you."<<std::endl;

//     // Preserving the energy ratio chosen by the user
//     double em_1_ratio{em_1/total_energy_deposited};

//     energy_em_1=em_1_ratio*(four_momentum_ptr->get_energy());
//   }

//   deposited_energy[0]=energy_em_1;
// }

// void Electron::set_em_2(double em_2)
// {
//   double total_energy_deposited{energy_em_1+em_2+energy_had_1+energy_had_2};

//   if(total_energy_deposited==(four_momentum_ptr->get_energy()))
//   {
//     energy_em_2=em_2;
//   }

//   else
//   {
//     std::cout<<"The total energy deposited in the calorimeter layers is not equal to the energy of"
//       <<" the electron in the 4-vector. A correct energy distribution is going to be set for you."<<std::endl;

//     // Preserving the energy ratio chosen by the user
//     double em_2_ratio{em_2/total_energy_deposited};

//     energy_em_2=em_2_ratio*(four_momentum_ptr->get_energy());
//   }

//   deposited_energy[1]=energy_em_2;
// }

// void Electron::set_had_1(double had_1)
// {
//   double total_energy_deposited{energy_em_1+energy_em_2+had_1+energy_had_2};

//   if(total_energy_deposited==(four_momentum_ptr->get_energy()))
//   {
//     energy_had_1=had_1;
//   }

//   else
//   {
//     std::cout<<"The total energy deposited in the calorimeter layers is not equal to the energy of"
//       <<" the electron in the 4-vector. A correct energy distribution is going to be set for you."<<std::endl;

//     // Preserving the energy ratio chosen by the user
//     double had_1_ratio{had_1/total_energy_deposited};

//     energy_had_1=had_1_ratio*(four_momentum_ptr->get_energy());
//   }

//   deposited_energy[2]=energy_had_1;
// }

// void Electron::set_had_2(double had_2)
// {
//   double total_energy_deposited{energy_em_1+energy_em_2+energy_had_1+had_2};

//   if(total_energy_deposited==(four_momentum_ptr->get_energy()))
//   {
//     energy_had_2=had_2;
//   }

//   else
//   {
//     std::cout<<"The total energy deposited in the calorimeter layers is not equal to the energy of"
//       <<" the electron in the 4-vector. A correct energy distribution is going to be set for you."<<std::endl;

//     // Preserving the energy ratio chosen by the user
//     double had_2_ratio{had_2/total_energy_deposited};

//     energy_had_2=had_2_ratio*(four_momentum_ptr->get_energy());
//   }

//   deposited_energy[3]=energy_had_2;
// }

void Electron::set_deposited_energy(double em_1, double em_2, double had_1, double had_2)
{
  double total_energy_deposited{em_1+em_2+had_1+had_2};

  if(total_energy_deposited==(four_momentum_ptr->get_energy()))
  {
    energy_em_1=em_1;
    energy_em_2=em_2;
    energy_had_1=had_1;
    energy_had_2=had_2;
  }

  else
  {
    std::cout<<"The total energy deposited in the calorimeter layers is not equal to the energy of"
      <<" the electron in the 4-vector. A correct energy distribution is going to be set for you."<<std::endl;

    // Preserving the energy ratio chosen by the user
    double em_1_ratio{em_1/total_energy_deposited};
    double em_2_ratio{em_2/total_energy_deposited};
    double had_1_ratio{had_1/total_energy_deposited};
    double had_2_ratio{had_2/total_energy_deposited};

    energy_em_1=em_1_ratio*(four_momentum_ptr->get_energy());
    energy_em_2=em_2_ratio*(four_momentum_ptr->get_energy());
    energy_had_1=had_1_ratio*(four_momentum_ptr->get_energy());
    energy_had_2=had_2_ratio*(four_momentum_ptr->get_energy());
  }

  deposited_energy[0]=energy_em_1;
  deposited_energy[1]=energy_em_2;
  deposited_energy[2]=energy_had_1;
  deposited_energy[3]=energy_had_2;
}

// Print function
void Electron::print_info()
{
  if(four_momentum_ptr!=nullptr)
  {
    Lepton::print_info();
    
    std::cout<<"Deposited energy in calorimeter layer (em_1, em_2, had_1, had_2) = ("
      <<deposited_energy[0]<<", "<<deposited_energy[1]<<", "<<deposited_energy[2]<<
        ", "<<deposited_energy[3]<<")\n"<<std::endl;
  }

  else
  {
    std::cerr<<"The four momentum pointer is a null pointer, hence information about the lepton's "<<
      "four momentum cannot be printed.\n"<<std::endl;
  }
}