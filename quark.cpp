// PHYS 30762 Programming in C++
// Project 2

// Implementation of Quark class member functions

// Author: Linda Persley (student ID: 10683097)
// Date: 12/05/2024

#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
#include<cmath>

#include"quark.h"
#include"particle.h"

// Parameterised constructor
Quark::Quark(double b_number, std::string colour, double charge, double spin, std::string type, double energy, double p_x, double p_y, double p_z) :
  Particle(charge, spin, type, energy, p_x, p_y, p_z)
{
  set_b_number(b_number);  // Input checking done within setter function
  set_colour(colour);
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
  if(fabs(b_number)==0.333)
  {
    baryon_number=b_number;
  }

  else
  {
    std::cerr<<"The baryon number you entered is not physical. It has to be either +1/3 or -1/3."<<std::endl;
    
    if(particle_type.substr(0, 4)=="anti")
    {
      std::cout<<"A value of -1/3 will be set for you."<<std::endl;

      baryon_number=-0.333;
    }

    else
    {
      std::cout<<"A value of +1/3 will be set for you."<<std::endl;

      baryon_number=0.333;
    }
  }
}

void Quark::set_colour(std::string colour)
{
  // Checking if colour charge is consistent with whether the quark is a particle or an antiparticle
  if(baryon_number==0.333) // If the quark is a particle
  {
    if((colour.substr(0, 4))!="anti") // If the colour charge is a colour
    {
      colour_charge=colour;
    }

    else
    {
      std::cerr<<"The colour charge is an anti-colour, but the quark is a particle. A colour charge was not set for you due to to this inconsistency."
        <<std::endl;
    }
  }

  else if(baryon_number==-0.333) // If the quark is an antiparticle
  {
    if((colour.substr(0, 4))=="anti") // If the colour charge is an anti-colour
    {
      colour_charge=colour;
    }

    else
    {
      std::cerr<<"The colour charge is a colour, but the quark is an antiparticle. A colour charge was not set for you due to to this inconsistency."
        <<std::endl;
    }
  }
}

// Function to convert between particles and antiparticles
std::unique_ptr<Particle> Quark::convert_particle()
{
  // Negating the charge and Quark number
  particle_charge*=-1;
  baryon_number*=-1;

  // Changing the particle type and colour charge accordingly
  if(baryon_number<0)
  {
    particle_type="anti"+particle_type;
    colour_charge="anti"+colour_charge;
  }

  else if(baryon_number>0)
  {
    // Delete first four letters "anti"
    particle_type=particle_type.erase(0, 4);
    colour_charge=colour_charge.erase(0, 4);
  }

  return this->clone();
}

// Print function
void Quark::print_info()
{
  if(four_momentum_ptr!=nullptr)
  {
    Particle::print_info();

    std::cout<<"Baryon number = "<<baryon_number<<"\nColour charge = "<<colour_charge<<std::endl;
  }

  else
  {
    std::cerr<<"The four momentum pointer is a null pointer, hence information about the particle's "<<
      "four momentum cannot be printed."<<std::endl;
  }
}