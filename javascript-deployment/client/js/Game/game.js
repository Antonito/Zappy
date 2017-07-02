/*
 **  InGame
 */

/*
 ** Items Position in cell
 */
var SPRITES_POSITION = {

    /*  POS X, POS Y, SPRITE WIDTH, SPRITE HEIGHT */

    MOB: { X: 10, Y: 10, SW: 32, SH: 64 },
    FOOD: { X: 0, Y: 70, SW: 32, SH: 32 },
    EGG: { X: 30, Y: 80, SW: 16, SH: 16 },
    DERAUMERE: { X: 50, Y: 30, SW: 16, SH: 16 },
    LINEMATE: { X: 70, Y: 30, SW: 16, SH: 16 },
    PHIRAS: { X: 50, Y: 50, SW: 16, SH: 16 },
    SIBUR: { X: 70, Y: 50, SW: 16, SH: 16 },
    THYSTAME: { X: 50, Y: 70, SW: 16, SH: 16 },
    MENDIANE: { X: 70, Y: 70, SW: 16, SH: 16 },

};

/*
 ** Mobs Teams Index
 */
var MOBS_COLOR = [

    "mob_default", /* team 0 */
    "mob_red",
    "mob_blue",
    "mob_green",
    "mob_yellow",
    "mob_pink",
    "mob_white",
    "mob_black" /* team 7 */

]

/**
 * Font
 */
var font_style = { font: "12px Arial", fill: "#000000" };

/*
 ** Events Management
 */
var event;

/*
 ** Game Environnement Variable
 */
var WORLD_WIDTH = 10;
var WORLD_HEIGHT = 10;
/* GameState */
var MENU = 0;
var INGAME = 1;
var CURRENT_STATE = MENU;
/* Data */
var raw_map_resources = [
    // food
    // linemate
    // deraumere
    // sibur
    // mendiane
    // phiras
    // thystame
];
var raw_mobs_list = [];
var raw_eggs_list = [];
/* Layers Groups */
var background_layer;
var resources_layer;
var eggs_layer;
var mobs_layer;
var text_layer;
/* starting positions */
var shiftX = 0;
var shiftY = 0;
var startX = 0;
var startY = 0;

var InGame = {

    preload: function() {

        background_layer = game.add.group();
        resources_layer = game.add.group();
        mobs_layer = game.add.group();
        eggs_layer = game.add.group();
        text_layer = game.add.group();

        event = game.input.keyboard.createCursorKeys();

        /* Clear */
        /*        clearGroup(background_layer);
                clearGroup(resources_layer);
                clearGroup(eggs_layer);
                clearGroup(mobs_layer);
        */

        /*
         **  Load Assets
         */

        /* Mobs */
        this.load.image('mob_default', 'assets/images/mob_default.png');
        this.load.image('mob_red', 'assets/images/mob_red.png');
        this.load.image('mob_blue', 'assets/images/mob_blue.png');
        this.load.image('mob_green', 'assets/images/mob_green.png');
        this.load.image('mob_yellow', 'assets/images/mob_yellow.png');
        this.load.image('mob_pink', 'assets/images/mob_pink.png');
        this.load.image('mob_white', 'assets/images/mob_white.png');
        this.load.image('mob_black', 'assets/images/mob_black.png');

        /* Egg */
        this.load.image('egg', 'assets/images/egg.png');

        /* Background Map */
        this.load.image('background', 'assets/images/background.png');

        /* RESOURCES */
        this.load.image('food', 'assets/images/food.png');
        this.load.image('linemate', 'assets/images/linemate.png');
        this.load.image('sibur', 'assets/images/sibur.png');
        this.load.image('deraumere', 'assets/images/deraumere.png');
        this.load.image('phiras', 'assets/images/phiras.png');
        this.load.image('mendiane', 'assets/images/mendiane.png');
        this.load.image('thystame', 'assets/images/thystame.png');

    },

    init: function(ws, data_buffered) {

        if (data_buffered) {
            parseData(data_buffered);

            console.log(raw_map_resources);
        }

        ws.onmessage = function(res) {

            console.log("=> " + res.data);
            parseData(res.data);

        };

    },

    create: function() {

        this.background = game.add.tileSprite(0, 0, 1000, 1000, 'background');
        ScaleImage(this.background, 1000, 1000);
        background_layer.add(this.background);

    },

    update: function() {

        // Clear
        clearGroup(resources_layer);
        clearGroup(mobs_layer);
        clearGroup(text_layer);
        // Draw
        DrawAll(startX, startY);

        /* Events */
        if (event) {
            if (event.up.isDown) {
                shiftY += 5;
                this.background.tilePosition.y += 5;
                if (shiftY >= 100) {
                    startY = startY > 0 ? (startY - 1) % raw_map_resources[0].length : raw_map_resources[0].length - 1;
                    shiftY = 0;
                }
            } else if (event.left.isDown) {
                shiftX += 5;
                this.background.tilePosition.x += 5;
                if (shiftX >= 100) {
                    startX = startX > 0 ? (startX - 1) % raw_map_resources[0].length : raw_map_resources[0].length - 1;
                    shiftX = 0;
                }
            } else if (event.right.isDown) {
                shiftX -= 5;
                this.background.tilePosition.x -= 5;
                if (shiftX <= -100) {
                    startX = (startX + 1) % raw_map_resources[0].length;
                    shiftX = 0;
                }
            } else if (event.down.isDown) {
                shiftY -= 5;
                this.background.tilePosition.y -= 5;
                if (shiftY <= -100) {
                    startY = (startY + 1) % raw_map_resources[0].length;
                    shiftY = 0;
                }
            }
        }

    },

};