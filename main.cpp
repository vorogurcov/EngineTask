#include "Subject.h"
#include "Engine.h"
#include "Wrapper.h"

int main() {

    std::filesystem::path testFile = "data/text.txt";
    Subject subj(testFile);

    Wrapper<Subject> replaceWrapper(subj, &Subject::replace_words, { {"from", "from"}, {"to", "to"} });
    Wrapper<Subject> findWrapper(subj, &Subject::find_phrase, { {"phrase", ""} });
    Wrapper<Subject> capitalizeWordsWrapper(subj, &Subject::capitalize_words, { {} });
    Wrapper<Subject> capitalizeSentencesWrapper(subj, &Subject::capitalize_sentences, { {} });
    Wrapper<Subject> numberSentencesWrapper(subj, &Subject::number_sentences, { {} });


    Engine engine;
    engine.register_command(&replaceWrapper, "replace");
    engine.register_command(&findWrapper, "find");
    engine.register_command(&capitalizeWordsWrapper, "capitalize_words");
    engine.register_command(&capitalizeSentencesWrapper, "capitalize_sentences");
    engine.register_command(&numberSentencesWrapper, "number_sentences");
    

    std::cout << engine.execute("replace", { {"from", "phrase"}, {"to", "PHRAZA"} }) << std::endl;
    std::cout << "------------------------------------\n";
    std::cout << engine.execute("find", { {"phrase", "phrase"}}) << std::endl;
    std::cout << "------------------------------------\n";
    std::cout << engine.execute("capitalize_words", {}) << std::endl;
    std::cout << "------------------------------------\n";
    std::cout << engine.execute("capitalize_sentences", {}) << std::endl;
    std::cout << "------------------------------------\n";
    std::cout << engine.execute("number_sentences", {}) << std::endl;

    return 0;
}