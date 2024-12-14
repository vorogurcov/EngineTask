#ifndef SUBJECT_H
#define SUBJECT_H

#include <sstream>
#include <unordered_map>
#include <filesystem>
#include <fstream>
#include <iostream>

using ArgMap = std::unordered_map<std::string, std::string>;

class Subject {
private:
    std::string document;

public:
    Subject(const std::string& text) : document(text) {}
    Subject(const std::filesystem::path& path);
    std::string replace_words(const ArgMap& args);
    std::string find_phrase(const ArgMap& args);
    std::string capitalize_words(const ArgMap&);
    std::string capitalize_sentences(const ArgMap&);
    std::string number_sentences(const ArgMap&);
};


#endif // !SUBJECT_H


