#pragma once 
#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class ASpell;
class SpellBook{
private:
	SpellBook(std::string const &other);
	SpellBook &operator=(SpellBook const &other);
	std::map<std::string, ASpell*> arr;

public:
	SpellBook();
	~SpellBook();
	void learnSpell(ASpell *spell);
	void forgetSpell(std::string const &namespell);
	ASpell* createSpell(std::string const &ref);

};