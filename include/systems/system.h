#pragma once

#include "callable.h"

class System : virtual Callable{
public:
	virtual void start() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
    virtual ~System(){};
};
