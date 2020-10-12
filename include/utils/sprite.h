/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** utils sprite header
*/

#ifndef UTILS_SPRITE_H_
#define UTILS_SPRITE_H_

static const char *SPRITE_SHEET_PATH = "ressources/sprite_sheet.png";

static const sfVector2f SPRITE_POS[] = {
    /* - - - SCR_HOME - - - */
    /* SPRITE */
    {960.0f, 540.0f},
    {960.0f, 200.0f},
    /* BUTTONS */
    {960.0f, 500.0f},
    {960.0f, 650.0f},
    {960.0f, 800.0f},
    /* MORE SPRITE */
    {1110.0f, 500.0f},
    {780.0f, 650.0f},
    {1100.0f, 800.0f},

    /* - - - SCR_OPTIONS - - - */
    /* SPRITES */
    {960.0f, 540.0f},
    /* BUTTONS */
    {960.0f, 800.0f},
    /* PROG BARS  EDGES */
    {960.0f, 200.0f},
    {960.0f, 400.0f},
    /* PROG BARS */
    {960.0f, 200.0f},
    {960.0f, 400.0f},
    /* TEXT BOXES*/
    {400.0f, 800.0f},
    /* CHECK BOCK */
    {150.0f, 200.0f},
    {150.0f, 400.0f},
    {150.0f, 600.0f},
    {1770.0f, 200.0f},
    /* CHECK BOX "CHECK" */
    {150.0f, 200.0f},
    {150.0f, 400.0f},
    {150.0f, 600.0f},
    {1770.0f, 200.0f},
    /* - - - SCR_MAP_SELECTION - - - */
    /* SPRITES */
    {960.0f, 540.0f},
    {960.0f, 517.0f},
    {1480.0f, 365.0f},
    /* BUTTONS */
    {100.0f, 100.0f},
    {1500.0f, 800.0f},
    {100.0f, 540.0f},
    {1840.0f, 540.0f},
    /* TEXT BOXES */
    /* map name */
    {650.0f, 450.0f},
    /* author name */
    {650.0f, 250.0f},
    /* map size */
    {400.0f, 680.0f},
    {850.0f, 680.0f},
    /* MORE SPRITES */
    {1480.0f, 390.0f},

    /* - - - SCR_GAME - - - */
    /* SPRITES */
    {960.0f, 540.0f},
    {960.0f, 935.5f},
    {503.0f, 983.5f},
    {732.0f, 983.5f},
    {962.0f, 983.5f},
    {1192.0f, 983.5f},
    {1422.0f, 983.5f},
    /* BUTTONS */
    {100.0f, 100.0f},
    /* tools */
    {240.0f, 1010.0f},
    {70.0f, 840.0f},
    {177.0f, 903.0f},
    /* pickaxe */
    {68.5f, 1012.0f},
    /* animations */
    {1850.0f, 840.0f},
    {1680.0f, 1010.0f},
    {1744.0f, 903.0f},
    /* film */
    {1846.5f, 1007.0f},
    /* new interface button !!! */
    {503.0f, 983.5f},
    {732.0f, 983.5f},
    {962.0f, 983.5f},
    {1192.0f, 983.5f},
    {1422.0f, 983.5f},
    /* burger menus */
    /* burger menu 1 */
    {503.0f, 850.0f}, {503.0f, 750.0f},
    {503.0f, 650.0f}, {503.0f, 550.0f},
    /* burger menu 2 */
    {732.0f, 850.0f}, {732.0f, 750.0f},
    {732.0f, 650.0f}, {732.0f, 550.0f},
    /* burger menu 3 */
    {962.0f, 850.0f}, {962.0f, 750.0f},
    {962.0f, 650.0f}, {962.0f, 550.0f},
    /* burger menu 4 */
    {1192.0f, 850.0f}, {1192.0f, 750.0f},
    {1192.0f, 650.0f}, {1192.0f, 550.0f},
    /* burger menu 5 */
    {1422.0f, 850.0f}, {1422.0f, 750.0f},
    {1422.0f, 650.0f}, {1422.0f, 550.0f},
    /* HELP BOXES */
    {960.0f, 200.0f},
    /* MORE SPRITE */
    /* parrot */
    {1190.0f, 280.0f},
};

static const sfIntRect SPRITE_RECTS[] = {
    /* - - - SCR_HOME - - - */
    /* SPRITE */
    {0, 0, 1920, 1080},
    {0, 1080, 880, 280},
    /* BUTTONS */
    {0, 1360, 387, 90},
    {0, 1450, 382, 86},
    {0, 1536, 383, 85},
    /* MORE SPRITE */
    {0, 1622, 172, 158},
    {172, 1622, 87, 134},
    {259, 1622, 104, 90},

    /* - - - SCR_OPTIONS - - - */
    /* SPRITES */
    {0, 3917, 1920, 1080},
    /* BUTTONS */
    {0, 1360, 387, 90},
    /* PROG BARS EDGES */
    {0, 2545, 857, 28},
    {0, 2545, 857, 28},
    /* PROG BARS */
    {0, 2573, 829, 16},
    {0, 2573, 829, 16},
    /* TEXT BOXES */
    {0, 2589, 542, 217},
    /* CHECK BOCK */
    {485, 1629, 117, 117},
    {602, 1629, 117, 117},
    {729, 1629, 117, 133},
    {737 + 292, 2886, 128, 128},
    /* CHECK BOX "CHECK" */
    {368, 1629, 117, 117},
    {368, 1629, 117, 117},
    {368, 1629, 117, 117},
    {737 + 292 + 128, 2886, 128, 128},

    /* - - - SCR_MAP_SELECTION - - - */
    /* SPRITES */
    {0, 4997, 1920, 1080},
    {0, 3048, 1565, 869},
    {1567, 2886 + 584, 383, 375},
    /* BUTTONS */
    {737, 2886, 141, 118},
    {737 + 141, 2886, 151, 58},
    {942, 2388, 148, 94},
    {942, 2482, 148, 94},
    /* TEXT BOXES */
    /* map name */
    {862, 1632, 378, 110},
    /* author name */
    {862, 1632, 378, 110},
    /* map size */
    {862, 1632, 378, 110},
    {862, 1632, 378, 110},
    /* MORE SPRITES */
    {1567, 2886, 478, 584},

    /* - - - SCR_GAME - - - */
    /* SPRITES */
    {0, 3917, 1920, 1080},
    {0, 1780, 1920, 309},
    {712, 2089, 178, 173},
    {712, 2089, 178, 173},
    {712, 2089, 178, 173},
    {712, 2089, 178, 173},
    {712, 2089, 178, 173},
    /* BUTTONS */
    {737, 2886, 141, 118},
    /* tools */
    {890, 2088, 128, 128},
    {890, 2088, 128, 128},
    {1402, 2088, 128, 128},
    /* pickaxe */
    {583, 2372, 137, 136},
    /* animations */
    {890, 2216, 128, 128},
    {890, 2216, 128, 128},
    {1402, 2216, 128, 128},
    /* film */
    {734, 2367, 167, 146},
    /* new interface button !!! */
    {0, 2089, 178, 173},
    {178, 2089, 178, 173},
    {356, 2089, 178, 173},
    {534, 2089, 178, 173},
    {1530, 2089, 178, 173},
    /* burger menus */
    /* burger menu 1 */
    {0, 1450, 200, 86}, {0, 1450, 200, 86},
    {0, 1450, 200, 86}, {0, 1450, 200, 86},
    /* burger menu 2 */
    {0, 1450, 200, 86}, {0, 1450, 200, 86},
    {0, 1450, 200, 86}, {0, 1450, 200, 86},
    /* burger menu 3 */
    {0, 1450, 200, 86}, {0, 1450, 200, 86},
    {0, 1450, 200, 86}, {0, 1450, 200, 86},
    /* burger menu 4 */
    {0, 1450, 200, 86}, {0, 1450, 200, 86},
    {0, 1450, 200, 86}, {0, 1450, 200, 86},
    /* burger menu 5 */
    {0, 1450, 200, 86}, {0, 1450, 200, 86},
    {0, 1450, 200, 86}, {0, 1450, 200, 86},
    /* HELP BOXES */
    {0, 2806, 633, 242},
    /* parrot */
    {633, 2806, 104, 138},
};

static const bool SPRITE_IS_HIDDEN[] = {
    /* - - - SCR_HOME - - - */
    false, false, false, false, false, false, false, false,

    /* - - - SCR_OPTIONS - - - */
    false, false, false,
    false, false, false, false, false, false,
    false, false, false, true, true, true,

    /* - - - SCR_MAP_SELECTION - - - */
    false, false, false,
    false, false, false, false,
    /* TEXT BOXES */
    false, false, false, false,
    /* */
    false,

    /* - - - SCR_GAME - - - */
    /* SPRITES */
    false, false, false, false, false, false, false,
    /* BUTTONS */
    false,
    /* tools */
    false, false, false, false,
    /* animations */
    false, false, false, false,
    /* new interface button !!! */
    false, false, false, false, false,
    /* burger menus */
    true, true, true, true,
    true, true, true, true,
    true, true, true, true,
    true, true, true, true,
    true, true, true, true,
    /* HELP BOXES */
    false,
    false,
};

#endif /* !UTILS_SPRITE_H_ */
