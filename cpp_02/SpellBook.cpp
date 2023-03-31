#include "SpellBook.hpp"


SpellBook::SpellBook(){

}

SpellBook::~SpellBook(){
	std::map<std::string, ASpell*>::iterator start = this->arr.begin();
	std::map<std::string, ASpell*>::iterator end = this->arr.end();
	while(start != end)
	{
		delete start->second;
		++start;
	}
	this->arr.clear();
}


void SpellBook::learnSpell(ASpell *spell){
	if(spell)
		arr.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
}

void SpellBook::forgetSpell(std::string const &namespell){
	std::map<std::string, ASpell*>::iterator it = arr.find(namespell);
	if(it != arr.end())
		delete it->second;
	arr.erase(namespell);
}

ASpell *SpellBook::createSpell(std::string const &ref){
	std::map<std::string, ASpell*>::iterator it = arr.find(ref);
	if(it != arr.end())
		return(arr[ref]);
	return(NULL);
}
