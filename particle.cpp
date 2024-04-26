// PHYS 30762 Programming in C++
// Project 2

// Implementation of Particle class member functions

// Author: Linda Persley (student ID: 10683097)
// Date: 12/05/2024

#include<iostream>
#include<vector>
#include<string>
#include<memory>
#include<iomanip>

#include"particle.h"

// Parameterised constructor
Particle::Particle(double charge, double spin, std::string type, double energy, double p_x, double p_y, double p_z)
{
  particle_charge=charge;
  particle_spin=spin;
  particle_type=type;
  four_momentum_ptr=std::make_unique<FourMomentum>(energy, p_x, p_y, p_z);
}

// Copy constructor
Particle::Particle(const Particle &original_particle)
{
  // Copying data members of the original particle
  particle_charge=original_particle.particle_charge;
  particle_spin=original_particle.particle_spin;
  particle_type=original_particle.particle_type;
  four_momentum_ptr=std::make_unique<FourMomentum>(*(original_particle.get_four_momentum_ptr())); // Ensures deep copying

  std::cout<<"Copy constructor called in Particle class for a "<<particle_type<<"."<<std::endl;
}

// Move constructor
Particle::Particle(Particle &&original_particle)
{
  // Move data of the original particle to a new particle
  particle_charge=original_particle.particle_charge;
  particle_spin=original_particle.particle_spin;
  particle_type=std::move(original_particle.particle_type);
  four_momentum_ptr=std::move(original_particle.four_momentum_ptr);

  // Resets data members of the original particle (unique pointer taken care of automatically)
  original_particle.set_charge(0);
  original_particle.set_spin(0);
  original_particle.set_type(0);

  std::cout<<"Move constructor called in Particle class for a "<<particle_type<<"."<<std::endl;
}

// Move assignment operator
Particle& Particle::operator=(Particle &&original_particle)
{
  // Avoiding self-assignment
  if(&original_particle==this)
  {
    std::cerr<<"Self-assignment detected, hence move assignment was not performed in Particle class for a "
    <<particle_type<<"."<<std::endl;

    return *this;
  }

  else
  {
    // Move data of the original particle to a new particle
    particle_charge=original_particle.particle_charge;
    particle_spin=original_particle.particle_spin;
    particle_type=std::move(original_particle.particle_type);
    four_momentum_ptr=std::move(original_particle.four_momentum_ptr);
    
    // Resets data members of the original particle (unique pointer taken care of automatically)
    original_particle.set_charge(0);
    original_particle.set_spin(0);
    original_particle.set_type(0);

    std::cout<<"Move assignment called in Particle class for a "<<particle_type<<"."<<std::endl;
  
    return *this;
  }
}

// Copy assignment operator
Particle& Particle::operator=(const Particle &original_particle)
{
  // Avoiding self-assignment
  if(&original_particle==this)
  {
    std::cerr<<"Self-assignment detected, hence copy assignment was not performed in Particle class for a "
    <<particle_type<<"."<<std::endl;

    return *this;
  }

  else
  {
    // Copying data members of the original particle
    particle_charge=original_particle.particle_charge;
    particle_spin=original_particle.particle_spin;
    particle_type=original_particle.particle_type;
    four_momentum_ptr=std::make_unique<FourMomentum>(*(original_particle.get_four_momentum_ptr()));
    // The above ensures deep copying

    std::cout<<"Copy assignment called in Particle class for a "<<particle_type<<"."<<std::endl;
  
    return *this;
  }
}

// void Particle::set_charge(int charge)
// {
//   if((charge==1)||(charge==(-1)))
//   {
//     particle_charge=charge;
//   }

//   else
//   {
//     std::cerr<<"The charge you entered is not physical. It has to be either +1 or -1."<<
//       "\nCharge of -1 will be set for you."<<std::endl;
    
//     particle_charge=-1;
//   }
// }

// Print function
void Particle::print_info()
{
  if(four_momentum_ptr!=nullptr)
  {
    std::cout<<"Particle type = "<<particle_type<<"\nCharge = "<<particle_charge<<"\nSpin = "<<
      particle_spin<<"\nFour momentum (E/c, p_x, p_y, p_z) = ("<<std::setprecision(3)<<four_momentum_ptr->get_energy()
        <<", "<<std::setprecision(3)<<four_momentum_ptr->get_momentum_x()<<", "<<std::setprecision(3)<<
          four_momentum_ptr->get_momentum_y()<<", "<<std::setprecision(3)<<four_momentum_ptr->get_momentum_z()
            <<")"<<std::endl;
  }
}