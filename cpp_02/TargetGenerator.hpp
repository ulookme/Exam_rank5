#pragma once 
#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class TargetGenerator{
private:
	TargetGenerator(std::string const &other);
	TargetGenerator &operator=(TargetGenerator const &other);
	std::map<std::string, ATarget*> arr;

public:
	TargetGenerator();
	~TargetGenerator();
	void learnTargetType(ATarget *target);
	void forgetTargetType(std::string const &namestarget);
	ATarget* createTarget(std::string const &ref);

};