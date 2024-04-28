// PHYS 30762 Programming in C++
// Assignment 5

// Implementation of Tau class member functions

// Author: Linda Persley (student ID: 10683097)
// Date: 20/04/2024

#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<memory>

#include"particle.h"
#include"lepton.h"
#include"tau.h"
#include"neutrino.h"

// Parameterised constructor
Tau::Tau(std::unique_ptr<Particle> particle_1, std::unique_ptr<Particle> particle_2, std::unique_ptr<Particle> particle_3,
      int l_number, double charge, double spin, double energy, double p_x, double p_y, double p_z) :
        Lepton(l_number, charge, spin, "tau", energy, p_x, p_y, p_z)
{
  set_products(std::move(particle_1), std::move(particle_2), std::move(particle_3)); // Input checking done within setter function
}

// Copy constructor
Tau::Tau(const Tau &original_lepton) : Lepton(original_lepton)
{
  // Deep copying the decay products of the original particle by iterating over each of its element of unique pointers
  std::vector<std::unique_ptr<Particle>>::iterator vector_iterator;

  for(vector_iterator=decay_products.begin();vector_iterator<decay_products.end();vector_iterator++)
  {
    decay_products.push_back((*vector_iterator)->clone());
  }

  std::cout<<"Copy constructor called in Tau class for a "<<particle_type<<"."<<std::endl;
}

// Move constructor
Tau::Tau(Tau &&original_lepton) : Lepton(std::move(original_lepton))
{
  // Move data of the original particle to a new particle
  decay_products=std::move(original_lepton.decay_products);

  // The data member of the original particle is reset automatically when moving a unique pointer

  std::cout<<"Move constructor called in Tau class for a "<<particle_type<<"."<<std::endl;
}

// Move assignment operator
Tau& Tau::operator=(Tau &&original_lepton)
{
  // Avoiding self-assignment
  if(&original_lepton==this)
  {
    std::cerr<<"Self-assignment detected, hence move assignment was not performed in"
    <<" Tau class for a "<<particle_type<<"."<<std::endl;


    return *this;
  }

  else
  {
    // Calling the equivalent base class operator
    Lepton::operator=(std::move(original_lepton));

    // Move data of the original particle to a new particle
    decay_products=std::move(original_lepton.decay_products);

    // The data member of the original particle is reset automatically when moving a unique pointer

    std::cout<<"Move assignment called in Tau class for a "<<particle_type<<"."<<std::endl;
  
    return *this;
  }
}

// Copy assignment operator
Tau& Tau::operator=(const Tau &original_lepton)
{
  // Avoiding self-assignment
  if(&original_lepton==this)
  {
    std::cerr<<"Self-assignment detected, hence copy assignment was not performed in Tau class for a "
    <<particle_type<<"."<<std::endl;

    return *this;
  }

  else
  {
    // Calling the equivalent base class operator
    Lepton::operator=(original_lepton);

    // Deep copying the decay products of the original particle by iterating over each of its element of unique pointers
    std::vector<std::unique_ptr<Particle>>::iterator vector_iterator;

    for(vector_iterator=decay_products.begin();vector_iterator<decay_products.end();vector_iterator++)
    {
      decay_products.push_back((*vector_iterator)->clone());
    }

    std::cout<<"Copy assignment called in Tau class for a "<<particle_type<<"."<<std::endl;
  
    return *this;
  }
}

// Setter function
void Tau::set_products(std::unique_ptr<Particle> particle_1, std::unique_ptr<Particle> particle_2, std::unique_ptr<Particle> particle_3)
{
  // Calculating the total charge of the decay products
  double sum_product_charge{particle_1->get_charge()+particle_2->get_charge()+particle_3->get_charge()};

  // Checking if the total charge is equal to that of the tau particle
  if(sum_product_charge==get_charge())
  {
    // Ensuring the decay product vector is empty before appending
    if(decay_products.size()!=0)
    {
      std::cerr<<"The decay product vector of this tau particle was not empty. It will be cleared and filled with your new particles"
        <<std::endl;

      decay_products.clear();
    }

    decay_products.push_back(particle_1->clone());
    decay_products.push_back(particle_2->clone());
    decay_products.push_back(particle_3->clone());
  }

  // else if(abs(sum_product_charge)==abs(get_charge()))
  // {
  //   // This scenario can happen if an antitau particle is instatiated - should be 
  //   // Ensuring the decay product vector is empty before appending
  //   if(decay_products.size()!=0)
  //   {
  //     std::cerr<<"The decay product vector of this tau particle was not empty.\nIt will be cleared and filled with your new particles"
  //       <<std::endl;

  //     decay_products.clear();
  //   }

  //   decay_products.push_back(particle_1->clone());
  //   decay_products.push_back(particle_2->clone());
  //   decay_products.push_back(particle_3->clone());
  // }

  else
  {
    std::cerr<<"The sum of decay product charges does not add up to the tau particle charge, so no decay products were set."<<std::endl;
  }
}

// Function to convert between particles and antiparticles
std::unique_ptr<Particle> Tau::convert_particle()
{
  // Negating the charge and lepton number
  particle_charge*=-1;
  lepton_number*=-1;

  // std::unique_ptr<Particle> converted_product_1{decay_products[0]->convert_particle()}; ////// std::move?
  // std::unique_ptr<Particle> converted_product_2{decay_products[1]->convert_particle()};
  // std::unique_ptr<Particle> converted_product_3{decay_products[2]->convert_particle()};

  // converted_product_2->print_info();

  // set_products(std::move(converted_product_1), std::move(converted_product_2), std::move(converted_product_3));
  

  // set_products(std::move(decay_products[0]->convert_particle()), std::move(decay_products[1]->convert_particle()),
  //   std::move(decay_products[2]->convert_particle()));

  // decay_products[0]->print_info();

  // decay_products[1]->print_info();

  // decay_products[2]->print_info();

  if(lepton_number<0)
  {
    particle_type="anti"+particle_type;
  }

  else if(lepton_number>0)
  {
    // Delete first four letters "anti"
    particle_type=particle_type.erase(0, 4);
  }

  return this->clone();
}

// // Function to convert the decay products between particles and antiparticles
// void Tau::convert_products()
// {
//   // Calculating the total charge of the decay products
//   double sum_product_charge{decay_products[0]->get_charge()+decay_products[1]->get_charge()+decay_products[2]->get_charge()};

//   // Checking if the total charge is equal to that of the tau particle
//   if(sum_product_charge==get_charge())
//   {
//     // Ensuring the decay product vector is empty before appending
//     if(decay_products.size()!=0)
//     {
//       std::cerr<<"The decay product vector of this tau particle was not empty. It will be cleared and filled with your new particles"
//         <<std::endl;

//       decay_products.clear();
//     }

//     decay_products.push_back(std::move(particle_1));
//     decay_products.push_back(std::move(particle_2));
//     decay_products.push_back(std::move(particle_3));
// }

// Print function
void Tau::print_info()
{
  if((four_momentum_ptr!=nullptr)&(decay_products.size()!=0))//&(decay_product_1!=nullptr)&(decay_product_2!=nullptr)&(decay_product_3!=nullptr))
  {
    // Calling the equivalent lepton class function
    Lepton::print_info();

      std::cout<<"Particles the tau decays to = "<<decay_products[0]->get_type()<<", "<<decay_products[1]->get_type()<<
        ", "<<decay_products[2]->get_type()<<std::endl;
  }

  // else if((four_momentum_ptr==nullptr)||(decay_product_1==nullptr)||(decay_product_2==nullptr)||(decay_product_3==nullptr))
  // {
  //   std::cerr<<"At least one of the smart pointers (four momentum pointer or one of the decay product pointers) is a null pointer,"
  //     <<"hence information about the lepton's four momentum and/or decay products cannot be printed.\n"<<std::endl;
  // }

  else if((four_momentum_ptr==nullptr)&(decay_products.size()!=0))
  {
    std::cerr<<"The four momentum pointer is a null pointer, hence information about the lepton's "<<
      "four momentum cannot be printed."<<std::endl;
  }

  else if((four_momentum_ptr!=nullptr)&(decay_products.size()==0))
  {
    std::cerr<<"The decay product vector of this tau particle was empty, hence information about its "<<
      "produced particles cannot be printed."<<std::endl;
  }

  else
  {
    std::cerr<<"The decay product vector of this tau particle was empty and four momentum pointer is a null pointer,"
      <<" hence information about it cannot be printed."<<std::endl;
  }
}