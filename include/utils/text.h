/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** text utils header
*/

#ifndef UTILS_TEXT_H_
#define UTILS_TEXT_H_

/*
** https://github.com/SFML/CSFML/blob/master/include/SFML/Graphics/Text.h
**
** sfText_setLineSpacing(sfText* text, float spacingFactor);
**
** sfText_setLetterSpacing(sfText* text, float spacingFactor);
**
** sfText_setStyle(sfText* text, sfUint32 style);
**
** sfText_setColor(sfText* text, sfColor color);
**
** sfText_setFillColor(sfText* text, sfColor color);
**
** sfText_setOutlineColor(sfText* text, sfColor color);
**
** sfText_setOutlineThickness(sfText* text, float thickness);
*/

static const sfVector2f TEXT_POS[] = {
    /* - - - SCR_HOME - - - */
    /* TEXT BOXES */
    {350.0f, 870.0f},

    /* - - - SCR_MAP_SELECTION - - - */
    /* TEXT BOXES */
    /* map name */
    {650.0f - 170.0f, 450.0f - 45.0f},
    /* author name */
    {650.0f - 170.0f, 250.0f - 45.0f},
    /* map size */
    {400.0f - 40.0f, 680.0f - 45.0f},
    {850.0f - 40.0f, 680.0f - 45.0f},

    /* - - - SCR_GAME - - - */
    /* HELP BOXES */
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
    {675.0f, 50.0f}, {650.0f, 175.0f},
};
static const sfVector2i TEXT_SIZE[] = {
    /* - - - SCR_HOME - - - */
    /* TEXT BOXES */
    {362, 177},

    /* - - - SCR_MAP_SELECTION - - - */
    /* TEXT BOXES */
    /* map name */
    {0, 0},
    /* author name */
    {0, 0},
    /* map size */
    {0, 0},
    {0, 0},

    /* - - - SCR_GAME - - - */
    /* HELP BOXES */
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
    {0, 0}, {0, 0},
};
static const unsigned int TEXT_CHAR_SIZE[] = {
    /* - - - SCR_HOME - - - */
    /* TEXT BOXES */
    70,

    /* - - - SCR_MAP_SELECTION - - - */
    /* TEXT BOXES */
    /* map name */
    70,
    /* author name */
    70,
    /* map size */
    70,
    70,

    /* - - - SCR_GAME - - - */
    /* HELP BOXES */
    100, 50,
    100, 50,
    100, 50,
    100, 50,
    100, 50,
    100, 50,
    100, 50,
    100, 50,
    100, 50,
    100, 50,
    100, 50,
    100, 50,
    100, 50,
    100, 50,
    100, 50,
    100, 50,
    100, 50,
    100, 50,
    100, 50,
    100, 50,
    100, 50,
    100, 50,
    100, 50,
    100, 50,
    100, 50,
    100, 50,
    100, 50,
    100, 50,
    100, 50,
    100, 50,
    100, 50,
    100, 50,
    100, 50,
};
static const int TEXT_FONT_ID[] = {
    /* - - - SCR_HOME - - - */
    /* TEXT BOXES */
    0,

    /* - - - SCR_MAP_SELECTION - - - */
    /* TEXT BOXES */
    /* map name */
    0,
    /* author name */
    0,
    /* map size */
    0, 0,

    /* - - - SCR_GAME - - - */
    /* HELP BOXES */
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
};
static const float TEXT_SPACING_FACTOR[] = {
    /* - - - SCR_HOME - - - */
    /* TEXT BOXES */
    0.2f,

    /* - - - SCR_MAP_SELECTION - - - */
    /* TEXT BOXES */
    /* map name */
    0.2f,
    /* author name */
    0.2f,
    /* map size */
    0.5f, 0.5f,

    /* - - - SCR_GAME - - - */
    /* HELP BOXES */
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
    0.2f, 0.2f,
};
static const char TEXT_STRING_DEFAULT[71][43] = {
    /* - - - SCR_HOME - - - */
    /* TEXT BOXES */
    {-1},

    /* - - - SCR_MAP_SELECTION - - - */
    /* TEXT BOXES */
    /* map name */
    {-1},
    /* author name */
    {-1},
    /* map size */
    {-1},
    {-1},

    /* - - - SCR_GAME - - - */
    /* HELP BOXES */
    "Decrement Tool", "change the current tool",
    "Increment Tool", "change the current tool",
    "Tool", "Apply new tool to brush",
    "No Tool", "Do nothing",
    "Decrement Animation", "change the current animation",
    "Increment Animation", "change the current animation",
    "Animation", "Launch selected animation",
    "End Animation", "Make the current animation to end",
    "Asset Menu", "Burger Menu: Drag asset tools",
    "Paint Menu", "Burger Menu: Paint tools",
    "Edit Tool Menu", "Burger Menu: Basic edit tools",
    "Brush Tool Menu", "Burger Menu: Basic brush tools",
    "Save Menu", "Burger Menu: save tools",
    "Assets", "House asset",
    "Assets", "Tree asset",
    "Assets", "Animal asset",
    "Assets", "Human asset",
    "Paint", "Rock color",
    "Paint", "Plain color",
    "Paint", "Dirt color",
    "Paint", "Sand color",
    "Edit", "No idea",
    "Edit", "No idea",
    "Edit", "No idea",
    "Edit", "No idea",
    "Brush", "No idea",
    "Brush", "No idea",
    "Brush", "No idea",
    "Brush", "No idea",
    "Save", "Save map",
    "Save", "Save as -> not anymore",
    "Save", "Rename map",
    "Save", "No idea",
};

#endif /* !UTILS_TEXT_H_ */
