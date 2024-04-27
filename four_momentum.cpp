// PHYS 30762 Programming in C++
// Project 2

// Implementation of FourMomentum class member functions

// Author: Linda Persley (student ID: 10683097)
// Date: 12/05/2024

#include<iostream>
#include<vector>
#include<iomanip>

#include"four_momentum.h"
#include"particle.h"

// Parameterised constructor
FourMomentum::FourMomentum(double energy, double p_x, double p_y, double p_z)
{
  set_energy(energy); // Makes use of input checking in setter function
  momentum_x=p_x;
  momentum_y=p_y;
  momentum_z=p_z;
}

// Copy constructor
FourMomentum::FourMomentum(const FourMomentum &original_four_momentum)
{  
  // Copying data members of the original particle
  particle_energy=original_four_momentum.particle_energy;
  momentum_x=original_four_momentum.momentum_x;
  momentum_y=original_four_momentum.momentum_y;
  momentum_z=original_four_momentum.momentum_z;
  four_momentum_vector=original_four_momentum.four_momentum_vector;

  std::cout<<"Copy constructor called in FourMomentum class."<<std::endl;
}

// Move constructor
FourMomentum::FourMomentum(FourMomentum &&original_four_momentum)
{
  // Move data of the original particle to a new particle
  particle_energy=original_four_momentum.particle_energy;
  momentum_x=original_four_momentum.momentum_x;
  momentum_y=original_four_momentum.momentum_y;
  momentum_z=original_four_momentum.momentum_z;
  four_momentum_vector=std::move(original_four_momentum.four_momentum_vector);

  // Resets data members of the original particle
  original_four_momentum.set_energy(0);
  original_four_momentum.set_momentum_x(0);
  original_four_momentum.set_momentum_y(0);
  original_four_momentum.set_momentum_z(0);

  std::cout<<"Move constructor called in FourMomentum class."<<std::endl;
}

// Move assignment operator
  FourMomentum& FourMomentum::operator=(FourMomentum &&original_four_momentum)
  {
    // Avoiding self-assignment
    if(&original_four_momentum==this)
    {
      std::cerr<<"Self-assignment detected, hence move assignment was not performed."
        <<std::endl;

      return *this;
    }

    else
    {
      // Move data of the original particle to a new particle
      particle_energy=original_four_momentum.particle_energy;
      momentum_x=original_four_momentum.momentum_x;
      momentum_y=original_four_momentum.momentum_y;
      momentum_z=original_four_momentum.momentum_z;
      four_momentum_vector=std::move(original_four_momentum.four_momentum_vector);
      
      // Resets data members of the original particle
      original_four_momentum.set_energy(0);
      original_four_momentum.set_momentum_x(0);
      original_four_momentum.set_momentum_y(0);
      original_four_momentum.set_momentum_z(0);

      std::cout<<"Move assignment called in FourMomentum class."<<std::endl;
    
      return *this;
    }
  }

// Copy assignment operator
FourMomentum& FourMomentum::operator=(const FourMomentum &original_four_momentum)
{
  // Avoiding self-assignment
  if(&original_four_momentum==this)
  {
    std::cerr<<"Self-assignment detected, hence copy assignment operator was not performed in "
      <<"FourMomentum class."<<std::endl;

    return *this;
  }

  else
  {
    // Copying data members of the original particle to a new particle
    particle_energy=original_four_momentum.particle_energy;
    momentum_x=original_four_momentum.momentum_x;
    momentum_y=original_four_momentum.momentum_y;
    momentum_z=original_four_momentum.momentum_z;
    four_momentum_vector=original_four_momentum.four_momentum_vector;
    
    std::cout<<"Copy assignment operator called in FourMomentum class"<<std::endl;

    return *this;
  }
}

// Setter functions
void FourMomentum::set_energy(double energy)
{
  // Ensuring energy value is physical
  if(energy>=0)
  {
    particle_energy=energy;
  }

  else
  {
    std::cerr<<"The energy you entered for the four momentum vector is not physical. It has to be a positive value."<<
      "\nEnergy value 10 will be set for you."<<std::endl;

    particle_energy=10;
  }
}

// Function to calculate invariant mass
double invariant_mass_calculator()
{
  double invariant_mass;

  return invariant_mass;
}

// // Overloaded sum operator
// std::vector<double> FourMomentum::operator+(const FourMomentum& other_particle)
// {
//   std::vector<double> sum_vector;
//   std::vector<double>::iterator vector_iterator;

//   for(vector_iterator=four_momentum_vector.begin();vector_iterator<four_momentum_vector.end();vector_iterator++)
//   {
//     sum_vector.push_back(*vector_iterator+(other_particle.get_four_momentum())[i]);
//   }

//   std::cout<<"\nThe sum of "<<other_particle.get_type()<<" and "<<particle_type<<
//     "'s four momenta (E/c, p_x, p_y, p_z)= ("<<sum_vector[0]<<", "<<sum_vector[1]
//       <<", "<<sum_vector[2]<<", "<<sum_vector[3]<<")\n"<<std::endl;

//   return sum_vector;
// }

// // Overloaded dot product operator
// double dotProduct(const FourMomentum& other_particle)
// {
//   // Defining variables
//   std::vector<double> multiplied_elements(4);
//   double dot_product_scalar;

//   multiplied_elements[0]=particle_1.four_momentum_ptr->get_energy()*particle_2.four_momentum_ptr
//     ->get_energy();
//   multiplied_elements[1]=particle_1.four_momentum_ptr->get_momentum_x()*particle_2.four_momentum_ptr
//     ->get_momentum_x();
//   multiplied_elements[2]=particle_1.four_momentum_ptr->get_momentum_y()*particle_2.four_momentum_ptr
//     ->get_momentum_y();
//   multiplied_elements[3]=particle_1.four_momentum_ptr->get_momentum_z()*particle_2.four_momentum_ptr
//     ->get_momentum_z();

//   for(size_t i{};i<multiplied_elements.size();++i)
//   {
//     dot_product_scalar+=multiplied_elements[i];
//   }

//   std::cout<<"Dot product of the four-momenta = "<<std::setprecision(3)<<dot_product_scalar<<"\n"<<std::endl;

//   return dot_product_scalar;
// }

// Friend functions:

// Overloaded sum operator
FourMomentum operator+(const Particle& particle_1, const Particle& particle_2)
{
  double sum_energy, sum_p_x, sum_p_y, sum_p_z;

  sum_energy=particle_1.four_momentum_ptr->get_energy()+particle_2.four_momentum_ptr
    ->get_energy();
  sum_p_x=particle_1.four_momentum_ptr->get_momentum_x()+particle_2.four_momentum_ptr
    ->get_momentum_x();
  sum_p_y=particle_1.four_momentum_ptr->get_momentum_y()+particle_2.four_momentum_ptr
    ->get_momentum_y();
  sum_p_z=particle_1.four_momentum_ptr->get_momentum_z()+particle_2.four_momentum_ptr
    ->get_momentum_z();

  std::cout<<"\nThe sum of the four-momenta (E/c, p_x, p_y, p_z)= ("<<std::setprecision(3)
    <<sum_energy<<", "<<std::setprecision(3)<<sum_p_x<<", "<<std::setprecision(3)<<sum_p_y<<
      ", "<<std::setprecision(3)<<sum_p_z<<")\n"<<std::endl;

  return FourMomentum(sum_energy, sum_p_x, sum_p_y, sum_p_z);
}

// Overloaded subtraction operator
FourMomentum operator-(const Particle& particle_1, const Particle& particle_2)
{
  double subtracted_energy, subtracted_p_x, subtracted_p_y, subtracted_p_z;

  subtracted_energy=particle_1.four_momentum_ptr->get_energy()-particle_2.four_momentum_ptr
    ->get_energy();
  subtracted_p_x=particle_1.four_momentum_ptr->get_momentum_x()-particle_2.four_momentum_ptr
    ->get_momentum_x();
  subtracted_p_y=particle_1.four_momentum_ptr->get_momentum_y()-particle_2.four_momentum_ptr
    ->get_momentum_y();
  subtracted_p_z=particle_1.four_momentum_ptr->get_momentum_z()-particle_2.four_momentum_ptr
    ->get_momentum_z();

  std::cout<<"\nThe sum of the four-momenta (E/c, p_x, p_y, p_z)= ("<<std::setprecision(3)
    <<subtracted_energy<<", "<<std::setprecision(3)<<subtracted_p_x<<", "<<std::setprecision(3)
      <<subtracted_p_y<<", "<<std::setprecision(3)<<subtracted_p_z<<")\n"<<std::endl;

  return FourMomentum(subtracted_energy, subtracted_p_x, subtracted_p_y, subtracted_p_z);
}

// Overloaded dot product operator
double dotProduct(const Particle& particle_1, const Particle& particle_2)
{
  // Defining variables
  double dot_product_scalar;
  std::vector<double> multiplied_elements(4);
  std::vector<double>::iterator vector_iterator;

  multiplied_elements[0]=particle_1.four_momentum_ptr->get_energy()*particle_2.four_momentum_ptr
    ->get_energy();
  multiplied_elements[1]=particle_1.four_momentum_ptr->get_momentum_x()*particle_2.four_momentum_ptr
    ->get_momentum_x();
  multiplied_elements[2]=particle_1.four_momentum_ptr->get_momentum_y()*particle_2.four_momentum_ptr
    ->get_momentum_y();
  multiplied_elements[3]=particle_1.four_momentum_ptr->get_momentum_z()*particle_2.four_momentum_ptr
    ->get_momentum_z();

  for(vector_iterator=multiplied_elements.begin();vector_iterator<multiplied_elements.end();vector_iterator++)
  {
    dot_product_scalar+=(*vector_iterator);
  }

  std::cout<<"Dot product of the four-momenta = "<<std::setprecision(3)<<dot_product_scalar<<"\n"<<std::endl;

  return dot_product_scalar;
}