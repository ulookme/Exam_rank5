#include "TargetGenerator.hpp"


TargetGenerator::TargetGenerator(){

}

TargetGenerator::~TargetGenerator(){
	std::map<std::string, ATarget*>::iterator start = this->arr.begin();
	std::map<std::string, ATarget*>::iterator end = this->arr.end();
	while(start != end)
	{
		delete start->second;
		++start;
	}
	this->arr.clear();
}


void TargetGenerator::learnTargetType(ATarget *target){
	if(target)
		arr.insert(std::pair<std::string, ATarget *>(target->getType(), target->clone()));
}

void TargetGenerator::forgetTargetType(std::string const &nametarget){
	std::map<std::string, ATarget*>::iterator it = arr.find(nametarget);
	if(it != arr.end())
		delete it->second;
	arr.erase(nametarget);
}

ATarget *TargetGenerator::createTarget(std::string const &ref){
	std::map<std::string, ATarget*>::iterator it = arr.find(ref);
	if(it != arr.end())
		return(arr[ref]);
	return(NULL);
}
