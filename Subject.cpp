#include "Subject.h"

Subject::Subject(const std::filesystem::path& path) {
    std::ifstream file(path);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        this->document ="";
    }
    else {
        this->document = std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    }

    file.close();

}

std::string Subject::replace_words(const ArgMap& args) {
    std::string from = args.at("from");
    std::string to = args.at("to");

    size_t start_pos = 0;
    while ((start_pos = document.find(from, start_pos)) != std::string::npos) {
        document.replace(start_pos, from.length(), to);
        start_pos += to.length();  
    }

    return document;
}

   
std::string Subject::find_phrase(const ArgMap& args) {
    std::string phrase = args.at("phrase");

    return (document.find(phrase) != std::string::npos) ? "Found" : "Not Found";
}


std::string Subject::capitalize_words(const ArgMap& args) {
    bool capitalize = true;

    for (char& ch : document) {
        if (std::isspace(ch)) {
            capitalize = true;
        }
        else if (capitalize && std::isalpha(ch)) {
            ch = std::toupper(ch);
            capitalize = false;
        }
    }

    return document;
}

   
std::string Subject::capitalize_sentences(const ArgMap& args) {
    bool capitalize = true;

    for (size_t i = 0; i < document.length(); ++i) {
        if (capitalize && std::isalpha(document[i])) {
            document[i] = std::toupper(document[i]);
            capitalize = false;
        }
        if (document[i] == '.' || document[i] == '!' || document[i] == '?') {
            capitalize = true;
        }
    }

    return document;
}


std::string Subject::number_sentences(const ArgMap& args) {
    std::ostringstream oss;
    size_t sentence_number = 1;
    bool new_sentence = true;

    for (char ch : document) {
        if (new_sentence && std::isalpha(ch)) {
            oss << sentence_number++ << ". ";
            new_sentence = false;
        }
        oss << ch;
        if (ch == '.' || ch == '!' || ch == '?') {
            new_sentence = true;
        }
    }

    return oss.str();
}
