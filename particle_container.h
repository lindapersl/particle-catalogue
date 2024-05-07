// PHYS 30762 Programming in C++
// Project 2

// Header including class template ParticleContainer for customising the existing stl map container

// Author: Linda Persley (student ID: 10683097)
// Date: 12/05/2024

#ifndef PARTICLE_CONTAINER_H
#define PARTICLE_CONTAINE_H

#include<iostream>
#include<map>
#include<string>
#include<memory>
#include<exception>
#include<algorithm>
#include<vector>
#include<iterator>
#include<numeric>

/////////#include"particle.h"

template<class c_type>
class ParticleContainer
{
  private:
    // Data member (defining the particle container as a map with particle name as the key)
    std::map<std::string, std::unique_ptr<c_type>> particle_container;

  protected:

  public:
  // Function to get total number of particles
  int get_total_number_particles() const {return particle_container.size();}

  // Template function to get number of particles of specific types
  template<class T>
  int get_number_particles_of_type() const;

  // Overloaded subscript ([]) operator
  std::unique_ptr<c_type>& operator[](const std::string key);

  // Function to create a sub-container of particles of a specific particle type T
  template<class U>
  ParticleContainer get_sub_container_of_type() const;

  // Function to print all particle information within a catalogue
  void print_catalogue();

  // Function to print information about one particle
  void print_particle_info(const std::string key);

  // Function to sum the four momenta of all particles
  std::vector<double> sum_four_momenta();
};

// Function to get number of particles of each type
template<class c_type>
template<class T>
int ParticleContainer<c_type>::get_number_particles_of_type() const
{
  int particle_counter{0};

  // Iterating through each element of the map and counting particles of specific type T that meets the criteria
  // (const std::pair<const std::string, std::unique_ptr<c_type>>& is the type of iterators for maps)
  std::for_each(particle_container.begin(), particle_container.end(), [&](const std::pair<const std::string, std::unique_ptr<c_type>>& iterator)
  {
    // If downcasting a pointer of an object of Particle class to a pointer of an object of a specific derived class is successful
    if(dynamic_cast<T*>(iterator.second.get())!=nullptr)
    {
      // particle_counter captured by value and incremented by lambda function
      particle_counter++;
    }
  });

  return particle_counter;
}

// Overloaded subscript ([]) operator
template<class c_type>
std::unique_ptr<c_type>& ParticleContainer<c_type>::operator[](const std::string key)
{
  // Checking if the key exists within the map
  try
  {
    return particle_container.at(key);
  }

  // If the key is invalid
  catch(const std::out_of_range& error)
  {
    // Creating a new empty (nullptr in this case) element with the inputted key
    particle_container[key]=nullptr;

    return particle_container[key];
  }
}

// Function to create a sub-container of particles of a specific particle type T
template<class c_type>
template<class U>
ParticleContainer<c_type> ParticleContainer<c_type>::get_sub_container_of_type() const
{
  // Defining a new, empty particle container
  ParticleContainer sub_container;

  // Iterating through each element of the map and adding particles of specific type T that meets the criteria
  // (const std::pair<const std::string, std::unique_ptr<c_type>>& is the type of iterators for maps)
  std::for_each(particle_container.begin(), particle_container.end(), [&](const std::pair<const std::string, std::unique_ptr<c_type>>& iterator)
  {
    // If downcasting a pointer of an object of Particle class to a pointer of an object of a specific derived class is successful
    if(dynamic_cast<U*>(iterator.second.get())!=nullptr)
    {
      sub_container[iterator.first]=iterator.second->clone();
    }
  });

  return sub_container;
}

// Function to print all particle information within a catalogue
template<class c_type>
void ParticleContainer<c_type>::print_catalogue()
{
  // Defining a map iterator
  typename std::map<std::string, std::unique_ptr<c_type>>::iterator map_iterator;

  for(map_iterator=particle_container.begin();map_iterator!=particle_container.end();map_iterator++)
  {
    (map_iterator->second)->print_info();
    std::cout<<"\n";
  }
}

// Function to print information about one particle
template<class c_type>
void ParticleContainer<c_type>::print_particle_info(const std::string key)
{
  // Checking if the particle exists within the container
  if(particle_container.find(key)!=particle_container.end()) // If it does exist
  {
    particle_container[key]->print_info();
  }

  else // If it does not exist
  {
    std::cerr<<"The particle you are trying to print information about does not exist within this catalogue."<<std::endl;
  }
}

// Function to sum the four momenta of all particles
template<class c_type>
std::vector<double> ParticleContainer<c_type>::sum_four_momenta()
{
  std::vector<double> total_four_momentum{0, 0, 0, 0};

  // Defining a map iterator
  typename std::map<std::string, std::unique_ptr<c_type>>::iterator map_iterator;

  for(map_iterator=particle_container.begin();map_iterator!=particle_container.end();map_iterator++)
  {
    // Using overloaded sum operator to add four momenta of particles
    total_four_momentum=total_four_momentum+(*(map_iterator->second));
  }

  std::cout<<"\nThe sum of the four-momenta of all particles within the catalogue (E/c, p_x, p_y, p_z)=\n("<<std::setprecision(3)
    <<total_four_momentum[0]<<", "<<std::setprecision(3)<<total_four_momentum[1]<<", "<<std::setprecision(3)<<total_four_momentum[2]<<
      ", "<<std::setprecision(3)<<total_four_momentum[3]<<")\n"<<std::endl;

  return total_four_momentum;
}

#endif