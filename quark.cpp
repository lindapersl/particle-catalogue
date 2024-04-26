// PHYS 30762 Programming in C++
// Project 2

// Implementation of Quark class member functions

// Author: Linda Persley (student ID: 10683097)
// Date: 12/05/2024

#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>

#include"quark.h"
#include"particle.h"

// Parameterised constructor
Quark::Quark(double b_number, double charge, double spin, std::string type, double energy, double p_x, double p_y, double p_z) :
  Particle(charge, spin, type, energy, p_x, p_y, p_z)
{
  set_b_number(b_number);  // Input checking done within setter function
}

// // Copy constructor
// Quark::Quark(const Quark &original_Quark)
// {
//   // Avoiding self-assignment
//   if(&original_Quark!=this)
//   {
//     // Copying data members of the original particle
    

//     std::cout<<"Copy constructor called in Quark class for a "<<particle_type<<"."<<std::endl;
//   }

//   else
//   {
//     std::cerr<<"Self-assignment detected, hence copy constructor was not performed in Quark class for a "
//       <<particle_type<<"."<<std::endl;
//   }
// }

// // Move constructor
// Quark::Quark(Quark &&original_Quark)
// {
//   // Move data of the original particle to a new particle


//   // Resets data members of the original particle (unique pointer taken care of automatically)


//   std::cout<<"Move constructor called in Quark class for a "<<particle_type<<"."<<std::endl;
// }

// // Move assignment operator
// Quark& Quark::operator=(Quark &&original_Quark)
// {
//   // Avoiding self-assignment
//   if(&original_Quark==this)
//   {
//     std::cerr<<"Self-assignment detected, hence move assignment was not performed in Quark class for a "
//     <<particle_type<<"."<<std::endl;

//     return *this;
//   }

//   else
//   {
//     // Move data of the original particle to a new particle

    
//     // Resets data members of the original particle (unique pointer taken care of automatically)


//     std::cout<<"Move assignment called in Quark class for a "<<particle_type<<"."<<std::endl;
  
//     return *this;
//   }
// }

// // Copy assignment operator
// Quark& Quark::operator=(const Quark &original_Quark)
// {
//   // Avoiding self-assignment
//   if(&original_Quark==this)
//   {
//     std::cerr<<"Self-assignment detected, hence copy assignment was not performed in Quark class for a "
//     <<particle_type<<"."<<std::endl;

//     return *this;
//   }

//   else
//   {
//     // Copying data members of the original particle


//     std::cout<<"Copy assignment called in Quark class for a "<<particle_type<<"."<<std::endl;
  
//     return *this;
//   }
// }

// Setter function
void Quark::set_b_number(double b_number)
{
  // Ensuring baryon number is either 1/3 or -1/3 (has an absolute value of 1/3)
  if(fabs(b_number)==(1/3))
  {
    baryon_number=b_number;
  }

  else
  {
    std::cerr<<"The baryon number you entered is not physical. It has to be either +1/3 or -1/3."<<std::endl;
    
    if(particle_type.substr(0, 4)=="anti")
    {
      std::cout<<"A value of -1/3 will be set for you."<<std::endl;

      baryon_number=-(1/3);
    }

    else
    {
      std::cout<<"A value of +1/3 will be set for you."<<std::endl;

      baryon_number=(1/3);
    }
  }
}

// Function to convert between particles and antiparticles
std::unique_ptr<Particle> Quark::convert_particle()
{
  // Negating the charge and Quark number
  particle_charge*=-1;
  baryon_number*=-1;

  if(baryon_number<0)
  {
    particle_type="anti"+particle_type;
  }

  else if(baryon_number>0)
  {
    // Delete first four letters "anti"
    particle_type=particle_type.erase(0, 4);
  }

  return std::make_unique<Quark>(*this);
}

// Print function
void Quark::print_info()
{
  if(four_momentum_ptr!=nullptr)
  {
    Particle::print_info();

    std::cout<<"Baryon number = "<<baryon_number<<"\n"<<std::endl;
  }

  else
  {
    std::cerr<<"The four momentum pointer is a null pointer, hence information about the particle's "<<
      "four momentum cannot be printed.\n"<<std::endl;
  }
}