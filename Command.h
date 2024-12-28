#ifndef COMMAND_H
#define COMMAND_H

#include <unordered_map>
#include <string>
using ArgMap = std::unordered_map<std::string, std::string>;

class Command {
public:
    virtual std::string execute(const ArgMap& args) = 0;
    virtual ~Command() = default;
};
#endif // COMMAND_H

