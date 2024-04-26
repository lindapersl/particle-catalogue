// PHYS 30762 Programming in C++
// Project 2

// Implementation of Lepton class member functions

// Author: Linda Persley (student ID: 10683097)
// Date: 12/05/2024

#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<cmath>

#include"lepton.h"
#include"particle.h"

// Parameterised constructor
Lepton::Lepton(int l_number, double charge, double spin, std::string type, double energy, double p_x, double p_y, double p_z) :
  Particle(charge, spin, type, energy, p_x, p_y, p_z)
{
  set_l_number(l_number); // Input checking done within setter function
}

// // Copy constructor
// Lepton::Lepton(const Lepton &original_lepton)
// {
//   // Avoiding self-assignment
//   if(&original_lepton!=this)
//   {
//     // Copying data members of the original particle
    

//     std::cout<<"Copy constructor called in Lepton class for a "<<particle_type<<"."<<std::endl;
//   }

//   else
//   {
//     std::cerr<<"Self-assignment detected, hence copy constructor was not performed in Lepton class for a "
//       <<particle_type<<"."<<std::endl;
//   }
// }

// // Move constructor
// Lepton::Lepton(Lepton &&original_lepton)
// {
//   // Move data of the original particle to a new particle


//   // Resets data members of the original particle (unique pointer taken care of automatically)


//   std::cout<<"Move constructor called in Lepton class for a "<<particle_type<<"."<<std::endl;
// }

// // Move assignment operator
// Lepton& Lepton::operator=(Lepton &&original_lepton)
// {
//   // Avoiding self-assignment
//   if(&original_lepton==this)
//   {
//     std::cerr<<"Self-assignment detected, hence move assignment was not performed in Lepton class for a "
//     <<particle_type<<"."<<std::endl;

//     return *this;
//   }

//   else
//   {
//     // Move data of the original particle to a new particle

    
//     // Resets data members of the original particle (unique pointer taken care of automatically)


//     std::cout<<"Move assignment called in Lepton class for a "<<particle_type<<"."<<std::endl;
  
//     return *this;
//   }
// }

// // Copy assignment operator
// Lepton& Lepton::operator=(const Lepton &original_lepton)
// {
//   // Avoiding self-assignment
//   if(&original_lepton==this)
//   {
//     std::cerr<<"Self-assignment detected, hence copy assignment was not performed in Lepton class for a "
//     <<particle_type<<"."<<std::endl;

//     return *this;
//   }

//   else
//   {
//     // Copying data members of the original particle


//     std::cout<<"Copy assignment called in Lepton class for a "<<particle_type<<"."<<std::endl;
  
//     return *this;
//   }
// }

// Setter function
void Lepton::set_l_number(int l_number)
{
  // Ensuring lepton number is either 1 or -1 (has an absolute value of 1)
  if(abs(l_number)==1)
  {
    lepton_number=l_number;
  }

  else
  {
    std::cerr<<"The lepton number you entered is not physical. It has to be either +1 or -1."<<std::endl;
    
    if(particle_type.substr(0, 4)=="anti")
    {
      std::cout<<"A value of -1 will be set for you."<<std::endl;

      lepton_number=-1;
    }

    else
    {
      std::cout<<"A value of +1 will be set for you."<<std::endl;

      lepton_number=1;
    }
  }
}

// Function to convert between particles and antiparticles
std::unique_ptr<Particle> Lepton::convert_particle()
{
  // Negating the charge and lepton number
  particle_charge*=-1;
  lepton_number*=-1;

  if(lepton_number<0)
  {
    particle_type="anti"+particle_type;
  }

  else if(lepton_number>0)
  {
    // Delete first four letters "anti"
    particle_type=particle_type.erase(0, 4);
  }

  return std::make_unique<Lepton>(*this);
}

// Print function
void Lepton::print_info()
{
  if(four_momentum_ptr!=nullptr)
  {
    Particle::print_info();

    std::cout<<"Lepton number = "<<lepton_number<<"\n"<<std::endl;
  }

  else
  {
    std::cerr<<"The four momentum pointer is a null pointer, hence information about the particle's "<<
      "four momentum cannot be printed.\n"<<std::endl;
  }
}