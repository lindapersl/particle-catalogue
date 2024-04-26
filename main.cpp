// PHYS 30762 Programming in C++
// Project 2: A program to design and demonstrate the functionality of a data catalogue of Standard Model particles.
// The catalogue is based on a class hierarchy using abstract classes and polymorphism, in addition to a separate four momentum class.

// Author: Linda Persley (student ID: 10683097)
// Date: 12/05/2024

#include<iostream>
#include<vector>
#include<memory>

#include"particle.h"
#include"lepton.h"
// #include"quark.h"
// #include"gauge_boson.h"
// #include"scalar_boson.h"
// #include"four_momentum.h"
// #include"electron.h"
// #include"muon.h"
// #include"tau.h"
// #include"neutrino.h" ///// different from report
// #include"up.h"
// #include"down.h"
// #include"charm.h"
// #include"strange.h"
// #include"top.h"
// #include"bottom.h"
// #include"photon.h"
// #include"w_boson.h"
// #include"z_boson.h"
// #include"gluon.h"

int main()
{
  // // Defining variables
  // std::vector<std::unique_ptr<Lepton>> lepton_vector;
  // std::vector<std::unique_ptr<Lepton>>::iterator vector_iterator;

  // // Two electrons
  // lepton_vector.push_back(std::make_unique<Electron>(10.1, 2.3, 6.06, 4.1, 22.56, 40.0, 28.0, 32.0));
  // lepton_vector.push_back(std::make_unique<Electron>(6.0, 5.5, 6.07, 1.2, 20.4, 10.3, 24.7, 3.8));

  // // Four muons
  // lepton_vector.push_back(std::make_unique<Muon>(1, 11.2, 4.5, 2.7, 7.0));
  // lepton_vector.push_back(std::make_unique<Muon>(1, 18.2, 1.0, 1.0, 4.0));
  // lepton_vector.push_back(std::make_unique<Muon>(1, 15.3, 4.6, 4.6, 1.2));
  // lepton_vector.push_back(std::make_unique<Muon>(1, 16.9, 2.9, 10.2, 4.6));

  // // Converting an electron into an antielectron
  // lepton_vector.push_back(std::make_unique<Electron>(6.7, 6.8, 4.0, 4.9, 29.1, 34.0, 18.5, 16.8)->convert_particle());

  // // Converting a muon into an antimuon
  // lepton_vector.push_back(std::make_unique<Muon>(1, 30.7, 23.6, 3.34, 6.5)->convert_particle());
 
  // // A muon neutrino
  // lepton_vector.push_back(std::make_unique<Neutrino>(0, "muon", 25.9, 5.7, 7.6, 9.2));

  // // An electron neutrino
  // lepton_vector.push_back(std::make_unique<Neutrino>(0, "electron", 13.0, 1.0, 2.6, 3.0));

  // // A tau decaying into a muon, a muon antineutrino and a tau neutrino
  // std::unique_ptr<Lepton> tau_1_decay_product_1{std::make_unique<Muon>(1, 13.3, 1.11, 6.5, 7.0)};
  // std::unique_ptr<Lepton> tau_1_decay_product_2{std::make_unique<Neutrino>(0, "muon", 20.0, 5.5, 4.6, 3.0)
  //   ->convert_particle()};
  // std::unique_ptr<Lepton> tau_1_decay_product_3{std::make_unique<Neutrino>(0, "tau", 11.0, 2.0, 4.0, 3.2)};

  // lepton_vector.push_back(std::make_unique<Tau>(1, std::move(tau_1_decay_product_1), std::move(tau_1_decay_product_2),
  //   std::move(tau_1_decay_product_3), 30.0, 6.0, 5.7, 5.0));

  // // A tau decaying into an antielectron, an electron neutrino an a tau antineutrino
  // std::unique_ptr<Lepton> tau_2_decay_product_1{std::make_unique<Electron>(14.1, 2.8, 5.66, 3.4, 42.6, 21.0, 28.5, 12.0)
  //   ->convert_particle()};
  // std::unique_ptr<Lepton> tau_2_decay_product_2{std::make_unique<Neutrino>(0, "electron", 29.4, 4.0, 2.1, 7.7)};
  // std::unique_ptr<Lepton> tau_2_decay_product_3{std::make_unique<Neutrino>(0, "tau", 31.0, 5.4, 4.5, 1.2)->convert_particle()};

  // lepton_vector.push_back(std::make_unique<Tau>(1, std::move(tau_2_decay_product_1), std::move(tau_2_decay_product_2),
  //   std::move(tau_2_decay_product_3), 38.9, 8.9, 5.1, 0.9));

  // // Printing information about all leptons
  // for(vector_iterator=lepton_vector.begin();vector_iterator<lepton_vector.end();vector_iterator++)
  // {
  //   (*vector_iterator)->print_info();
  //   std::cout<<"\n";
  // }

  // // Summing the four-momenta of the first two electrons
  // FourMomentum sum_four_momentum=(*lepton_vector[0])+(*lepton_vector[1]);

  // // Taking the dot product of the four-momenta of the antielectron and the antimuon
  // double dot_product=dotProduct((*lepton_vector[6]), (*lepton_vector[7]));
 
  // // Creating a unique pointer to a new electron
  // std::unique_ptr<Electron> new_electron;

  // new_electron=std::make_unique<Electron>(19.1, 2.88, 8.96, 0.1, 30.5, 37.8, 18.0, 30.0);
  
  // // Printing information about the new electron
  // std::cout<<"\nInformation about the new electron to be moved:"<<std::endl;
  // new_electron->print_info();

  // // // Moving the new electron's data to another electron
  // Electron another_electron;

  // another_electron=std::move(*new_electron);

  // // Printing information about the other electron
  // std::cout<<"\nInformation about the other electron after moving the new electron's data:"<<std::endl;
  // another_electron.print_info();

  // // Creating a shared pointer to a new tau decaying into an antielectron, an electron neutrino an a tau antineutrino
  // std::unique_ptr<Lepton> tau_3_decay_product_1{std::make_unique<Electron>(44.1, 5.0, 10.1, 6.4, 12.6, 22.9, 4.4, 9.6)
  //   ->convert_particle()};
  // std::unique_ptr<Lepton> tau_3_decay_product_2{std::make_unique<Neutrino>(0, "electron", 20.8, 2.2, 7.5, 3.9)};
  // std::unique_ptr<Lepton> tau_3_decay_product_3{std::make_unique<Neutrino>(0, "tau", 20.4, 8.2, 11.5, 0.88)->convert_particle()};

  // std::shared_ptr<Tau> tau_shared_ptr{std::make_shared<Tau>(1, std::move(tau_3_decay_product_1), std::move(tau_3_decay_product_2),
  //   std::move(tau_3_decay_product_3), 5.0, 1.0, 0.7, 0.9)};

  // // Printing information about the new Tau
  // std::cout<<"\nInformation about the new Tau:"<<std::endl;
  // tau_shared_ptr->print_info();

  // // Creating more shared pointers to the same Tau lepton
  // std::shared_ptr<Tau> tau_ptr_2{tau_shared_ptr};
  // std::shared_ptr<Tau> tau_ptr_3{tau_shared_ptr};

  // // Printing information about the same Tau lepton through the two other pointers that share its ownership
  // std::cout<<"\nInformation about the same Tau lepton, but through different shared pointers:"<<std::endl;
  // tau_ptr_2->print_info();
  // tau_ptr_3->print_info();

 return 0;
}