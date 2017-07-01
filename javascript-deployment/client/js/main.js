/*
 **  Game Map Dimensions
 */
var GAME_WIDTH = 1000;
var GAME_HEIGHT = 1000;

/**
 * WebSocket
 */
var ws;

/*
 **  Create Context
 */
var game = new Phaser.Game(GAME_WIDTH, GAME_HEIGHT, Phaser.CANVAS),
    Main = function() {};

Main.prototype = {

    preload: function() {

        game.load.script('menu', 'js/Menu/menu.js');
        game.load.script('game', 'js/Game/game.js');


        game.time.desiredFps = 18;

    },

    create: function() {
        /*
         **  Add states and run the menu 
         */
        game.state.add('MENU', Menu);
        game.state.add('INGAME', InGame);
        game.state.start('MENU');
    },

}

game.state.add('Main', Main);
game.state.start('Main');