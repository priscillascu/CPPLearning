#ifndef SEARCHANDDELETECONTACT_HPP
#define SEARCHANDDELETECONTACT_HPP

#include <iostream>
#include <string>
#include "ContactSystem.hpp"
using namespace std;

int SearchContact(ContactBuild *contact, string targetName);
void DeletePeople(ContactBuild *contact, string delName);

#endif