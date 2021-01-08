#pragma once

#include <string>
#include <typeinfo>

class Component {
public:
    virtual ~Component(){}
public:
    std::string getType();
    template<typename T>
        static std::string getType(){
            T helper;
            return typeid(helper).name();
        }
};
