#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria
{
public:
	AMateria(std::string const & type);//
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
//все что добавил ниже
	AMateria();//
	virtual ~AMateria();//
	AMateria(AMateria const &sample);
	AMateria& operator= (const AMateria &sample);
protected:
	std::string	type;
};

class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

class ICharacter
{
public:
	virtual ~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
protected:
	std::string	name;
};

class Character : public ICharacter
{
public:
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
//добавления ниже
	Character(std::string name = "default");
//	Character(Character &sample);
//	Character& operator= (const Character &sample);
	~Character();
protected:
	std::string	name;
	AMateria*	inventory[4];
	int curr_slot;
};

class Ice : public AMateria
{
public:
		AMateria* clone() const;
//добавления ниже
		Ice();
		~Ice();
//	Ice(Ice &sample);
//	Ice& operator= (const Ice &sample);
};

class Cure : public AMateria
{
	public:
		AMateria* clone() const;
//добавления ниже
		Cure();
		~Cure();
//	Cure(Cure &sample);
//	Cure& operator= (const Cure &sample);
};

class MateriaSource : public IMateriaSource
{
public:
	void learnMateria(AMateria* sample);
	AMateria* createMateria(std::string const & type);
//добавления ниже
	MateriaSource();
//	MateriaSource(MateriaSource &sample);
	~MateriaSource();
//	MateriaSource& operator= (const MateriaSource &sample);
private:
	AMateria* inventory[4];
	int	curr_slot;
};

#endif