#pragma once 
#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock{
private:
	std::string name;
	std::string title;
	Warlock();
	Warlock(std::string const &other);
	Warlock &operator=(Warlock const &other);
	std::map<std::string, ASpell*> arr;
	SpellBook book;

public:
	Warlock(std::string const &name, std::string const &title);
	~Warlock();
	std::string const &getName() const;
	std::string const &getTitle() const;
	void setTitle(std::string const &title);
	void introduce() const;
	void learnSpell(ASpell *spell);
	void forgetSpell(std::string namespell);
	void launchSpell(std::string namespell, ATarget const &ref);

};