#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i)
        _materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src) {
    for (int i = 0; i < 4; ++i)
        _materia[i] = src._materia[i] ? src._materia[i]->clone() : NULL;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i)
        delete _materia[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {
    if (this != &rhs) {
        for (int i = 0; i < 4; ++i) {
            delete _materia[i];
            _materia[i] = rhs._materia[i] ? rhs._materia[i]->clone() : NULL;
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (!_materia[i]) {
            _materia[i] = m;
            return;
        }
    }
    std::cout << "Materia source is full" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (_materia[i] && _materia[i]->getType() == type) {
            return _materia[i]->clone();
        }
    }
    std::cout << "Materia of type " << type << " not found" << std::endl;
    return NULL;
}


