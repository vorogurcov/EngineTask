#ifndef ENGINE_H
#define ENGINE_H

#include "Command.h"

class Engine {
private:
    std::unordered_map<std::string, Command*> commands;

public:
    void register_command(Command* command, const std::string& name);

    std::string execute(const std::string& name, const ArgMap& args);
};

#endif // !ENGINE_H

