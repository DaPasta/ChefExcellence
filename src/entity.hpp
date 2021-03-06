#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>
#include "modules/module.hpp"
#include "modules/moduletype.hpp"
#include "modules/entitystate.hpp"

class Module;

class Entity : public sf::Drawable {
    private:
        std::map<ModuleType, Module*> modules;
        EntityState state;

    public:
        Entity();

        void addModule(ModuleType type, Module *module);

        void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        void update(sf::Time &delta);

        void setState(EntityState state);
        EntityState getState() const;

        Module* getModule(ModuleType type);

        void move(int x, int y);
        void setPosition(int x, int y);
        void setScale(float x, float y);
        sf::Vector2f getPosition() const;
        sf::FloatRect getRect() const;
};

#endif
