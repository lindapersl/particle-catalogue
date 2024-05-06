// PHYS 30762 Programming in C++
// Project 2: A program to design and demonstrate the functionality of a data catalogue of Standard Model particles.
// The catalogue is based on a class hierarchy using abstract classes and polymorphism, in addition to a separate four momentum class.

// Author: Linda Persley (student ID: 10683097)
// Date: 12/05/2024

#include<iostream>
#include<vector>
#include<string>
#include<memory>
#include<map>

#include"particle_container.h"
#include"four_momentum.h"
#include"particle.h"
#include"lepton.h"
#include"quark.h"
#include"gauge_boson.h"
#include"electron.h"
#include"muon.h"
#include"tau.h"
#include"neutrino.h"
#include"up.h"
#include"down.h"
#include"charm.h"
#include"strange.h"
#include"top.h"
#include"bottom.h"
#include"gluon.h"
#include"z_boson.h"
#include"w_boson.h"
#include"higgs.h"

int main()
{
  // Defining the particle catalogue as a map with particle type name as the key
  ParticleContainer<Particle> particle_catalogue;

  // Instantiating the decay products of tau particles (particle & antiparticle)
  std::unique_ptr<Particle> tau_1_decay_product_1=std::make_unique<Muon>(0, 30, 5, 3, 7);
  std::unique_ptr<Particle> tau_1_decay_product_2=std::make_unique<Neutrino>(0, "muon", 10, 4, 7, 1)->convert_particle();
  std::unique_ptr<Particle> tau_1_decay_product_3=std::make_unique<Neutrino>(0, "tau", 8, 1, 2, 5)->convert_particle();

  std::unique_ptr<Particle> tau_2_decay_product_1=std::make_unique<Muon>(0, 30, 5, 3, 7);
  std::unique_ptr<Particle> tau_2_decay_product_2=std::make_unique<Neutrino>(0, "muon", 10, 4, 7, 1)->convert_particle();
  std::unique_ptr<Particle> tau_2_decay_product_3=std::make_unique<Neutrino>(0, "tau", 8, 1, 2, 5)->convert_particle();

  // Instantiating the decay products of the Z boson
  std::unique_ptr<Particle> z_boson_decay_product_1=std::make_unique<Up>("green", 41, 7, 11, 6);
  std::unique_ptr<Particle> z_boson_decay_product_2=std::make_unique<Up>("red", 17, 2, 1, 6)->convert_particle();

  // Instantiating the decay products of the W- boson
  std::unique_ptr<Particle> w_1_boson_decay_product_1=std::make_unique<Muon>(0, 28, 4, 11, 15);
  std::unique_ptr<Particle> w_1_boson_decay_product_2=std::make_unique<Neutrino>(0, "muon", 10, 1, 3, 6)->convert_particle();

  // Instantiating the decay products of the W+ boson
  std::unique_ptr<Particle> w_2_boson_decay_product_1=std::make_unique<Top>("red", 12, 2, 1, 5)->convert_particle();
  std::unique_ptr<Particle> w_2_boson_decay_product_2=std::make_unique<Bottom>("blue", 18, 6 , 12, 2);

  // Instantiating the decay products of the Higgs boson
  std::unique_ptr<Particle> higgs_decay_product_1=std::make_unique<GaugeBoson>(0, "photon", 0, 43, 13, 20, 3);
  std::unique_ptr<Particle> higgs_decay_product_2=std::make_unique<GaugeBoson>(0, "photon", 0, 20, 9, 12, 17);

  // std::unique_ptr<Particle> higgs_decay_product_1=std::make_unique<Bottom>(0.333, "green", -0.333, 0.5, 22, 12, 16, 19);
  // std::unique_ptr<Particle> higgs_decay_product_2=std::make_unique<Bottom>(0.333, "green", -0.333, 0.5, 19, 7, 5, 11)->convert_particle();

  // Creating a catalogue with all 31 particles
  particle_catalogue["electron"]=std::make_unique<Electron>(10, 6, 4, 3, 1.6, 0.5, 0.7, 0.8);
  particle_catalogue["antielectron"]=std::make_unique<Electron>(13, 2, 5, 4, 24, 7, 5, 9)->convert_particle();
  particle_catalogue["muon"]=std::make_unique<Muon>(1, 20, 1, 2, 3);
  particle_catalogue["antimuon"]=std::make_unique<Muon>(1, 44, 6, 11, 8)->convert_particle();
  particle_catalogue["tau"]=std::make_unique<Tau>(std::move(tau_1_decay_product_1), std::move(tau_1_decay_product_2),
    std::move(tau_1_decay_product_3), 27, 3, 6, 8);
  particle_catalogue["antitau"]=std::make_unique<Tau>(std::move(tau_2_decay_product_1), std::move(tau_2_decay_product_2),
    std::move(tau_2_decay_product_3), 18, 5, 7, 3)->convert_particle(); ///// Problem of converting decay products
  particle_catalogue["electron neutrino"]=std::make_unique<Neutrino>(0, "electron", 10, 2, 2, 1);
  particle_catalogue["electron antineutrino"]=std::make_unique<Neutrino>(0, "electron", 8, 1, 5, 3)->convert_particle();
  particle_catalogue["muon neutrino"]=std::make_unique<Neutrino>(0, "muon", 16, 6, 5, 1);
  particle_catalogue["muon antineutrino"]=std::make_unique<Neutrino>(0, "muon", 12, 2, 2, 1)->convert_particle();
  particle_catalogue["tau neutrino"]=std::make_unique<Neutrino>(0, "tau", 9, 4, 3, 6);
  particle_catalogue["tau antineutrino"]=std::make_unique<Neutrino>(0, "tau", 17, 7, 7, 3)->convert_particle();
  particle_catalogue["up"]=std::make_unique<Up>("blue", 11, 4, 5, 6);
  particle_catalogue["antiup"]=std::make_unique<Up>("red", 61, 77, 52, 13)->convert_particle();
  particle_catalogue["down"]=std::make_unique<Down>("red", 3, 1, 1, 2);
  particle_catalogue["antidown"]=std::make_unique<Down>("green", 18, 8, 6, 4)->convert_particle();
  particle_catalogue["charm"]=std::make_unique<Charm>("blue", 32, 9, 4, 7);
  particle_catalogue["anticharm"]=std::make_unique<Charm>("red", 12, 8, 6, 11)->convert_particle();
  particle_catalogue["strange"]=std::make_unique<Strange>("red", 16, 6, 6, 3);
  particle_catalogue["antistrange"]=std::make_unique<Strange>("green", 23, 3, 7, 7)->convert_particle();
  particle_catalogue["top"]=std::make_unique<Top>("blue", 44, 4, 8, 10);
  particle_catalogue["antitop"]=std::make_unique<Top>("blue", 18, 9, 13, 6)->convert_particle();
  particle_catalogue["bottom"]=std::make_unique<Bottom>("green", 30, 20, 23, 9);
  particle_catalogue["antibottom"]=std::make_unique<Bottom>("red", 29, 11, 3, 2)->convert_particle();
  particle_catalogue["gluon"]=std::make_unique<Gluon>("green", "antired", 33, 6, 4, 2);
  particle_catalogue["antigluon"]=std::make_unique<Gluon>("antigreen", "blue", 38, 9, 10, 15)->convert_particle();
  particle_catalogue["Z boson"]=std::make_unique<ZBoson>(std::move(z_boson_decay_product_1), std::move(z_boson_decay_product_2),
    20, 1, 2, 4);
  particle_catalogue["W- boson"]=std::make_unique<WBoson>(std::move(w_1_boson_decay_product_1), std::move(w_1_boson_decay_product_2),
    12, 2, 4, 7);
  particle_catalogue["W+ boson"]=std::make_unique<WBoson>(std::move(w_2_boson_decay_product_1), std::move(w_2_boson_decay_product_2),
    30, 2, 22, 12)->convert_particle(); //// Problem of converting and setting decay products
  particle_catalogue["photon"]=std::make_unique<GaugeBoson>(0, "photon", 0, 56, 14, 21, 11);
  particle_catalogue["higgs boson"]=std::make_unique<Higgs>(std::move(higgs_decay_product_1), std::move(higgs_decay_product_2),
    12, 2, 1, 4);

  std::cout<<"Total number of particles in the catalogue : "<<particle_catalogue.get_total_number_particles()<<std::endl;

  std::cout<<"Number of lepton type particles in the catalogue : "<<particle_catalogue.get_number_particles_of_type<Lepton>()<<std::endl;
  std::cout<<"Number of quark type particles in the catalogue : "<<particle_catalogue.get_number_particles_of_type<Quark>()<<std::endl;
  std::cout<<"Number of gauge boson type particles in the catalogue : "<<particle_catalogue.get_number_particles_of_type<GaugeBoson>()<<std::endl;
  std::cout<<"Number of scalar boson type particles in the catalogue : "<<particle_catalogue.get_number_particles_of_type<Higgs>()<<std::endl;
  
  // Defining a new sub-container for leptons
  ParticleContainer<Particle> lepton_catalogue;

  lepton_catalogue=particle_catalogue.get_sub_container_of_type<Lepton>();

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