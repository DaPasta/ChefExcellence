#include "levelhandler.hpp"
#include <iostream>

LevelHandler::LevelHandler(const char* path) {
    if(file.load_file(path)) {
        isLoaded = true;
    } else {
        isLoaded = false;
    }
}

void LevelHandler::createLevels(std::vector<Level> &levels) {
    std::string platformName = "platform";
    if(isLoaded) {
        std::cout << "Creating levels..." << std::endl;
        for(pugi::xml_node level = file.child("levels").first_child(); level; level = level.next_sibling()) {
            std::cout << "Level " << level.attribute("id").value() << ":" << std::endl;
            for(pugi::xml_node node = level.first_child(); node; node = node.next_sibling()) {
                std::cout << "\t" << node.name() << " : " << node.value() << std::endl;
                if(node.name() == platformName) {
                    std::cout << "Greetings my dear sir" << std::endl;
                }
                for(pugi::xml_attribute attribute = node.first_attribute(); attribute; attribute = attribute.next_attribute()) {
                    std::cout << "\t\t" << attribute.name() << ": " << attribute.value() << std::endl;
                }
                //TODO: create levels based on xml values
            }
        }
    } else {
        std::cout << "Level data not loaded!" << std::endl;
    }
}