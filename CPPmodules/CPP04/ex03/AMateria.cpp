#include "AMateria.hpp"

//Amateria

AMateria::AMateria()
{};

AMateria::AMateria(std::string const & type) : type(type)
{};

AMateria::AMateria(AMateria const &sample) : type(sample.getType())
{};

AMateria& AMateria::operator= (const AMateria &sample)
{
	this->type = sample.getType();
	return *this; 
};

AMateria::~AMateria()
{};

std::string const &AMateria::getType() const
{return this->type;};

void AMateria::use(ICharacter &target)
{
	if (!this->type.compare("Ice"))
		std::cout << "shoot an ice bolt at " + target.getName() << std::endl;
	else if (!this->type.compare("Cure"))
		std::cout << "heals " + target.getName() + "'s wounds" << std::endl;
};

//IMateriaSource и ICaracter полностью абстрактны, не нужно у них ничего расписывать

//Character

Character::Character(std::string name) : name(name)
{
	for (int i = 0; i<4; i++)
		this->inventory[i] = 0;
	this->curr_slot = 0;
};

Character::~Character()
{
	int i = 0;
	while (i < 4 && this->inventory[i])
			delete this->inventory[i++];
}

std::string const & Character::getName() const
{return this->name;};

void	Character::equip(AMateria* m)
{
	if (this->curr_slot < 4)
		this->inventory[this->curr_slot++] = m;
}

void	Character::unequip(int idx)
{
	if(idx > -1 && idx < 4)
		this->inventory[idx] = 0;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx > -1 && idx < 4 && this->inventory[idx] != 0)
		this->inventory[idx]->use(target);
}

//Ice

Ice::Ice()
{this->type = "Ice";};

Ice::~Ice()
{};

AMateria* Ice::clone() const
{
	AMateria* clone = new Ice();
	return (clone);
}

//Cure

Cure::Cure()
{this->type = "Cure";};

Cure::~Cure()
{};

AMateria* Cure::clone() const
{
	AMateria* clone = new Cure();
	return (clone);
}

//MateriaSource

MateriaSource::MateriaSource()
{
	for (int i = 0; i<4; i++)
		this->inventory[i] = 0;
	this->curr_slot = 0;
};

MateriaSource::~MateriaSource()
{
	int i = 0;
	while (i < 4 && this->inventory[i])
			delete this->inventory[i++];
}

void MateriaSource::learnMateria(AMateria* sample)
{
	if (this->inventory[this->curr_slot])
		delete this->inventory[this->curr_slot];
	this->inventory[this->curr_slot] = sample->clone();
	if (this->curr_slot == 3)
		this->curr_slot = 0;
	else
		this->curr_slot++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
		if (!this->inventory[i]->getType().compare(type))
			return (this->inventory[i]->clone());
	return (0);
};
