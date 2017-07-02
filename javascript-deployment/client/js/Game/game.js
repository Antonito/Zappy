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
var inventory_style = { font: "22px Arial", fill: "#ffffff" };
var cell_info_style = { font: "24px Arial", fill: "#ffffff" };

/*
 ** Events Management
 */
var event;

/*
 ** Game Environnement Variable
 */
var WSZW = 0;
var WSZH = 0;
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
var animations_layer;
var textboxes_layer;
var infos_layer;
var inventory_layer;
var text_layer;
/* starting positions */
var shiftX = 0;
var shiftY = 0;
var startX = 0;
var startY = 0;
/* Sound */
var fx_theme;
var fx_broadcast;
var fx_click;

var InGame = {

    preload: function() {

        background_layer = game.add.group();
        resources_layer = game.add.group();
        mobs_layer = game.add.group();
        eggs_layer = game.add.group();
        animations_layer = game.add.group();
        textboxes_layer = game.add.group();
        text_layer = game.add.group();
        infos_layer = game.add.group();
        inventory_layer = game.add.group();

        event = game.input.keyboard.createCursorKeys();

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

        /* Effects */
        this.load.image('broadcast', 'assets/images/broadcast.png');

        /* TextBox */
        this.load.image('infofield', 'assets/images/infofield.png');

        /* Inventory */
        this.load.image('inventory', 'assets/images/inventory.png');

        /* Sound */
        this.load.audio('fx_theme', 'assets/sounds/theme.ogg');
        this.load.audio('fx_broadcast', 'assets/sounds/broadcast.ogg');
        this.load.audio('fx_click', 'assets/sounds/click.ogg');

    },

    init: function(ws, data_buffered) {

        if (data_buffered) {
            parseData(data_buffered);
        }

        ws.onmessage = function(res) {

            parseData(res.data);

        };

    },

    create: function() {

        this.background = game.add.tileSprite(0, 0, 1000, 1000, 'background');
        ScaleImage(this.background, 1000, 1000);
        background_layer.add(this.background);

        // Info Box
        this.infofield = game.add.sprite(100, 900, 'infofield')
        ScaleImage(this.infofield, 800, 100);
        textboxes_layer.add(this.infofield);

        var i_food = game.add.sprite(160, 940, 'food');
        ScaleImage(i_food, 32, 32);
        textboxes_layer.add(i_food);
        var i_linemate = game.add.sprite(260, 940, 'linemate');
        ScaleImage(i_linemate, 32, 32);
        textboxes_layer.add(i_linemate);
        var i_deraumere = game.add.sprite(360, 940, 'deraumere');
        ScaleImage(i_deraumere, 32, 32);
        textboxes_layer.add(i_deraumere);
        var i_sibur = game.add.sprite(460, 940, 'sibur');
        ScaleImage(i_sibur, 32, 32);
        textboxes_layer.add(i_sibur);
        var i_mendiane = game.add.sprite(560, 940, 'mendiane');
        ScaleImage(i_mendiane, 32, 32);
        textboxes_layer.add(i_mendiane);
        var i_phiras = game.add.sprite(660, 940, 'phiras');
        ScaleImage(i_phiras, 32, 32);
        textboxes_layer.add(i_phiras);
        var i_thystame = game.add.sprite(760, 940, 'thystame');
        ScaleImage(i_thystame, 32, 32);
        textboxes_layer.add(i_thystame);

        fx_broadcast = game.add.audio('fx_broadcast');
        fx_theme = game.add.audio('fx_theme');
        fx_click = game.add.audio('fx_click');

        fx_theme.loopFull();
        fx_theme.play();
    },

    update: function() {

        // Clear
        clearGroup(resources_layer);
        clearGroup(mobs_layer);
        clearGroup(text_layer);
        // Draw
        DrawAll(startX, startY);

        /* Events */
        // Mouse
        if (game.input.mousePointer.isDown) {

            var pos_x = Math.floor(game.input.x / 100);
            var pos_y = Math.floor(game.input.y / 100);

            if (pos_x >= 0 && pos_x < 10 &&
                pos_y >= 0 && pos_y < 10) {

                fx_click.play();
                clearGroup(infos_layer);
                clearGroup(inventory_layer);

                var cell = raw_map_resources[(startY + pos_y) % WSZH][(startX + pos_x) % WSZW];

                if (cell) {

                    infos_layer.add(game.add.text(210, 950, cell.food, cell_info_style));
                    infos_layer.add(game.add.text(310, 950, cell.linemate, cell_info_style));
                    infos_layer.add(game.add.text(410, 950, cell.deraumere, cell_info_style));
                    infos_layer.add(game.add.text(510, 950, cell.sibur, cell_info_style));
                    infos_layer.add(game.add.text(610, 950, cell.mendiane, cell_info_style));
                    infos_layer.add(game.add.text(710, 950, cell.phiras, cell_info_style));
                    infos_layer.add(game.add.text(810, 950, cell.thystame, cell_info_style));

                }


                for (var i = 0; i < raw_mobs_list.length; ++i) {

                    if (raw_mobs_list[i].X == startX + pos_x && raw_mobs_list[i].Y == pos_y + startY) {

                        DrawInventory(raw_mobs_list[i]);

                        break;
                    }
                }

            }
        }

        // Keyboard
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