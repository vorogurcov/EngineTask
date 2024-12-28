#ifndef WRAPPER_H
#define WRAPPER_H

#include <functional>
#include "Command.h"

template <typename T>
class Wrapper : public Command {
private:
    T& instance;  
    std::function<std::string(T&, const ArgMap&)> func;  
    ArgMap defaultArgs;

    std::string execute(const ArgMap& args) override {
        return func(instance, args);
    }

public:
    Wrapper(T& obj, std::function<std::string(T&, const ArgMap&)> f, const ArgMap& args = {})
        : instance(obj), func(f), defaultArgs(args) {}
};
#endif // !WRAPPER

