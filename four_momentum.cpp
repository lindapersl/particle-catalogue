// PHYS 30762 Programming in C++
// Project 2

// Implementation of FourMomentum class member functions

// Author: Linda Persley (student ID: 10683097)
// Date: 12/05/2024

#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
#include<utility>
#include<random>
#include<limits>

#include"four_momentum.h"
#include"particle.h"

// Parameterised constructor
FourMomentum::FourMomentum(double rest_mass, double energy, double p_x, double p_y, double p_z)
{
  set_four_momentum(rest_mass, energy, p_x, p_y, p_z); // Makes use of input checking within the setter function
}

// Copy constructor
FourMomentum::FourMomentum(const FourMomentum &original_four_momentum)
{  
  // Copying data members of the original particle
  invariant_mass=original_four_momentum.invariant_mass;
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
  invariant_mass=original_four_momentum.invariant_mass;
  particle_energy=original_four_momentum.particle_energy;
  momentum_x=original_four_momentum.momentum_x;
  momentum_y=original_four_momentum.momentum_y;
  momentum_z=original_four_momentum.momentum_z;
  four_momentum_vector=std::move(original_four_momentum.four_momentum_vector);

  // Resets data members of the original particle
  original_four_momentum.set_invariant_mass(0);
  original_four_momentum.set_four_momentum(0, 0, 0, 0, 0);
  // original_four_momentum.set_energy(0);
  // original_four_momentum.set_momentum_x(0);
  // original_four_momentum.set_momentum_y(0);
  // original_four_momentum.set_momentum_z(0);

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
      invariant_mass=original_four_momentum.invariant_mass;
      particle_energy=original_four_momentum.particle_energy;
      momentum_x=original_four_momentum.momentum_x;
      momentum_y=original_four_momentum.momentum_y;
      momentum_z=original_four_momentum.momentum_z;
      four_momentum_vector=std::move(original_four_momentum.four_momentum_vector);
      
      // Resets data members of the original particle
      original_four_momentum.set_invariant_mass(0);
      original_four_momentum.set_four_momentum(0, 0, 0, 0, 0);
      // original_four_momentum.set_energy(0);
      // original_four_momentum.set_momentum_x(0);
      // original_four_momentum.set_momentum_y(0);
      // original_four_momentum.set_momentum_z(0);

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
    invariant_mass=original_four_momentum.invariant_mass;
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
// void FourMomentum::set_energy(double energy)
// {
//   // Ensuring energy value is physical
//   if(energy>=0)
//   {
//     particle_energy=energy;
//   }

//   else
//   {
//     std::cerr<<"The energy you entered for the four momentum vector is not physical. It has to be a positive value."<<
//       "\nEnergy value 10 will be set for you."<<std::endl;

//     particle_energy=10;
//   }
// }

void FourMomentum::set_four_momentum(double rest_mass, double energy, double p_x, double p_y, double p_z)
{
  // Initially setting the four momentum elements to the inputted values without input checking (for now)
  particle_energy=energy;
  momentum_x=p_x;
  momentum_y=p_y;
  momentum_z=p_z;

  // Defining a pair of double and bool to store return variables
  std::pair<double, bool> return_variables;
  return_variables=invariant_mass_calculator(rest_mass);

  // Setting the value of (correct) invariant mass
  invariant_mass=return_variables.first;

  // If four momentum is not physical (or energy is not positive)
  // (The initially set values of four momentum elements need correcting)
  if((return_variables.second==0)||(energy<0))
  {
    std::cerr<<"The four momentum is not physical. It needs to follow special relativity and energy needs to be positive."
      <<" Correct values will be set for you."<<std::endl;

    // Choose energy value from a random number generator (energy value has to at least be invariant mass)
    std::random_device random_number;
    std::uniform_real_distribution<double> energy_distribution(invariant_mass, 200000); // An arbitrary, high number chosen for the upper bound

    particle_energy=energy_distribution(random_number);

    // Set equal momentum values for each component
    double equal_momentum_components{sqrt((std::pow(particle_energy, 2)-std::pow(invariant_mass, 2))/3)};

    momentum_x=equal_momentum_components;
    momentum_y=equal_momentum_components;
    momentum_z=equal_momentum_components;
  }

  // Setting values of the four momentum vector
  four_momentum_vector[0]=particle_energy;
  four_momentum_vector[1]=momentum_x;
  four_momentum_vector[2]=momentum_y;
  four_momentum_vector[3]=momentum_z;
}

// Function to calculate invariant mass
std::pair<double, bool> FourMomentum::invariant_mass_calculator(double rest_mass)
{
  // Defining a bool that flags whether the four momentum is physical in special relativity (false=not physical, true=physical)
  bool is_physical{1};

  // Using *this pointer to calculate
  double dot_product_3_momenta{(this->get_momentum_x()*this->get_momentum_x())+(this->get_momentum_y()*this->get_momentum_y()
    +(this->get_momentum_z()*this->get_momentum_z()))};

  double invariant_mass{sqrt((this->get_energy()*this->get_energy())-dot_product_3_momenta)};

  // Consistency check that it matches the corresponding particle's rest mass
  if(invariant_mass!=rest_mass)
  {
    std::cerr<<"The invariant mass calculated from the energy and 3-momenta does not match the rest mass of the particle."
      <<" The correct value will be set for you."<<std::endl;
    
    is_physical=0;
  
    invariant_mass=rest_mass;
  }

  // Defining a pair of double and bool in order to return two variables
  std::pair<double, bool> return_pair{invariant_mass, is_physical};

  return return_pair;
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
// std::vector<double> operator+(const Particle& particle_1, const Particle& particle_2)
// {
//   double sum_energy, sum_p_x, sum_p_y, sum_p_z;
//   std::vector<double> summed_four_momenta;

//   sum_energy=particle_1.four_momentum_ptr->get_energy()+particle_2.four_momentum_ptr
//     ->get_energy();
//   sum_p_x=particle_1.four_momentum_ptr->get_momentum_x()+particle_2.four_momentum_ptr
//     ->get_momentum_x();
//   sum_p_y=particle_1.four_momentum_ptr->get_momentum_y()+particle_2.four_momentum_ptr
//     ->get_momentum_y();
//   sum_p_z=particle_1.four_momentum_ptr->get_momentum_z()+particle_2.four_momentum_ptr
//     ->get_momentum_z();

//   summed_four_momenta.push_back(sum_energy);
//   summed_four_momenta.push_back(sum_p_x);
//   summed_four_momenta.push_back(sum_p_y);
//   summed_four_momenta.push_back(sum_p_z);

//   return summed_four_momenta;
// }

std::vector<double> operator+(const std::vector<double>& four_momentum_vector, const Particle& particle_1)
{
  double sum_energy, sum_p_x, sum_p_y, sum_p_z;
  std::vector<double> summed_four_momenta;

  sum_energy=particle_1.four_momentum_ptr->get_energy()+four_momentum_vector[0];
  sum_p_x=particle_1.four_momentum_ptr->get_momentum_x()+four_momentum_vector[1];
  sum_p_y=particle_1.four_momentum_ptr->get_momentum_y()+four_momentum_vector[2];
  sum_p_z=particle_1.four_momentum_ptr->get_momentum_z()+four_momentum_vector[3];

  summed_four_momenta.push_back(sum_energy);
  summed_four_momenta.push_back(sum_p_x);
  summed_four_momenta.push_back(sum_p_y);
  summed_four_momenta.push_back(sum_p_z);

  return summed_four_momenta;
}

// Overloaded subtraction operator
std::vector<double> operator-(const std::vector<double>& four_momentum_vector, const Particle& particle_1)
{
  double subtracted_energy, subtracted_p_x, subtracted_p_y, subtracted_p_z;
  std::vector<double> subtracted_four_momenta;

  subtracted_energy=particle_1.four_momentum_ptr->get_energy()-four_momentum_vector[0];
  subtracted_p_x=particle_1.four_momentum_ptr->get_momentum_x()-four_momentum_vector[1];
  subtracted_p_y=particle_1.four_momentum_ptr->get_momentum_y()-four_momentum_vector[2];
  subtracted_p_z=particle_1.four_momentum_ptr->get_momentum_z()-four_momentum_vector[3];

  subtracted_four_momenta.push_back(subtracted_energy);
  subtracted_four_momenta.push_back(subtracted_p_x);
  subtracted_four_momenta.push_back(subtracted_p_y);
  subtracted_four_momenta.push_back(subtracted_p_z);

  std::cout<<"\nThe sum of the four-momenta (E/c, p_x, p_y, p_z)= ("<<std::setprecision(3)
    <<subtracted_energy<<", "<<std::setprecision(3)<<subtracted_p_x<<", "<<std::setprecision(3)
      <<subtracted_p_y<<", "<<std::setprecision(3)<<subtracted_p_z<<")\n"<<std::endl;

  return subtracted_four_momenta;
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
    dot_product_scalar-=(*vector_iterator); ///// correct?
  }

  std::cout<<"Dot product of the four-momenta = "<<std::setprecision(3)<<dot_product_scalar<<"\n"<<std::endl;

  return dot_product_scalar;
}