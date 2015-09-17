#include "gamescreen.hpp"
#include "game.hpp"

GameScreen::GameScreen(sf::View *view) {
    //Create player, our venerable chef
    chefStandingRight.loadFromFile("assets/chef/ChefStandingRight.png");
    chefStandingLeft.loadFromFile("assets/chef/ChefStandingLeft.png");
    chefWalkingRight.loadFromFile("assets/chef/ChefWalkingRight.png");
    chefWalkingLeft.loadFromFile("assets/chef/ChefWalkingLeft.png");
    chefClimbing.loadFromFile("assets/chef/ChefClimbing.png");
    breadstick.loadFromFile("assets/chef/Breadstick.png");
    player = new Player(chefWalkingRight, breadstick);

    //Create levels
    background.loadFromFile("assets/map/level1/Background.png");
    platform.loadFromFile("assets/map/level1/Platform.png");
    level = new Level(background, platform);
    levels.push_back(*level);
    levelHandler = new LevelHandler("assets/map/data.xml");
    levelHandler->createLevels(levels);

    //Camera
    this->view = view;
}

void GameScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(*level, states);
    target.draw(*player, states);
}

void GameScreen::update() {
        sf::Time frameTime = frameClock.restart();

        //Player horiztonal movement
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player->move(LEFT);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player->move(RIGHT);
        } else {
            player->move(NONE);
        }

        //Player vertical movement
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            player->jump();
        }

        //Breadstick throwing
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            player->throwBreadstick();
        }

        player->update(frameTime, sf::Vector2f(view->getCenter().x + Game::SCREEN_WIDTH / 2, view->getCenter().y + Game::SCREEN_HEIGHT / 2), level->getPlatforms());

        view->move((player->getPosition().x - view->getCenter().x) / 10.0,
                (player->getPosition().y + player->getLocalBounds().height - Game::SCREEN_HEIGHT / 2 - view->getCenter().y + 50) / 20.0);
}

void GameScreen::handleEvent(sf::Event event) {

}