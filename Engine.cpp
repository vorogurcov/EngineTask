#include "Engine.h"
#include "Wrapper.h"

void Engine::register_command(Command* command, const std::string& name) {
    commands[name] = command;
}

std::string Engine::execute(const std::string& name, const ArgMap& args) {
    if (commands.find(name) != commands.end()) {
        return commands[name]->execute(args);
    }
    return "Command not found";
}
