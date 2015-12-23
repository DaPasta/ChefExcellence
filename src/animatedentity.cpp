#include "animatedentity.hpp"
#include <iostream>

AnimatedEntity::AnimatedEntity(std::map<Direction, Animation> &animations) {
    this->animations = animations;
}

void AnimatedEntity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

void AnimatedEntity::update(sf::Time delta) {
    sprite.update(delta);
}

void AnimatedEntity::changeAnimation(Direction state) {
    currentState = state;
    sprite.setAnimation(animations.at(state));
}

void AnimatedEntity::move(int x, int y) {
    sprite.move(x, y);
}

void AnimatedEntity::setPosition(int x, int y) {
    sprite.setPosition(x, y);
}

void AnimatedEntity::setScale(float x, float y) {
    sprite.setScale(x, y);
}

sf::Vector2f AnimatedEntity::getPosition() const {
    return sprite.getPosition();
}

sf::FloatRect AnimatedEntity::getRect() const {
    return sprite.getGlobalBounds();
}

