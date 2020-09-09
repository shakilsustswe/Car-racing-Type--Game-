#ifndef MENU_H
#define MENU_H

#include<SFML/Graphics.hpp>
#define MAX_ITEMS 3

class Menu
{
public:
    Menu(float width, float height);
    virtual ~Menu();
    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem()
    {
        return selectedItemIndex;
    }

protected:

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_ITEMS];
};

#endif // MENU_H
