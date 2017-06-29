/**
 * Menu
 */

var background_layer;
var assets_layer;
var event;

var Menu = {

    /**
     * Connection managed here
     */
    connect: function() {
        var ip = this.ipInput.canvasInput.value();
        var port = this.portInput.canvasInput.value();

        ScaleImage(assets_layer.create(game.world.centerX - 150, game.world.centerY + 50, 'connection_failed'), 300, 45);
    },

    preload: function() {

        /**
         * Load Assets
         */
        this.load.image('menu', 'assets/images/menu.png');
        this.load.image('title', 'assets/images/zappy_title.png');
        this.load.image('button_connect', 'assets/images/button_connect.png');
        this.load.image('connection_failed', 'assets/images/connection_failed.png');

        /**
         * Layers
         */
        background_layer = game.add.group();
        assets_layer = game.add.group();

        /**
         * Events
         */
        event = game.input.keyboard.createCursorKeys();

    },

    create: function() {

        /**
         * Title
         */

        ScaleImage(background_layer.create(0, 0, 'menu'), 1000, 1000);
        ScaleImage(assets_layer.create(game.world.centerX - 150, 50, 'title'), 300, 200);

        /**
         * Input Fields
         */
        this.ipInput = this.createInput(300, 300, 400, 'Enter IP Address ..');
        this.portInput = this.createInput(300, 400, 400, 'Enter Port ..');

        /**
         * Connection button
         */
        var connect_button = game.make.button(game.world.centerX - 150, game.world.centerY, 'button_connect', this.connect, this);
        ScaleImage(connect_button, 300, 45);
        connect_button.onInput
        assets_layer.add(connect_button);
    },

    inputFocus: function(sprite) {

        sprite.canvasInput.focus();

    },

    createInput: function(x, y, width, placeHolder) {

        /**
         * Return an input canvas object
         */

        var bmd = this.add.bitmapData(400, 50);
        var myInput = this.game.add.sprite(x, y, bmd);

        myInput.canvasInput = new CanvasInput({
            canvas: bmd.canvas,
            fontSize: 30,
            fontFamily: 'Arial',
            fontColor: '#212121',
            fontWeight: 'bold',
            width: width,
            padding: 8,
            borderWidth: 1,
            borderColor: '#000',
            borderRadius: 3,
            boxShadow: '1px 1px 0px #fff',
            innerShadow: '0px 0px 5px rgba(0, 0, 0, 0.5)',
            placeHolder: placeHolder
        });
        myInput.inputEnabled = true;
        myInput.input.useHandCursor = true;
        myInput.events.onInputUp.add(this.inputFocus, this);

        return myInput;
    },

    update: function() {

        if (event) {
            if (event.up.isDown) {
                clearGroup(background_layer);
                game.state.start('INGAME');
            } else if (event.left.isDown) {
                console.log("touche de gauche pressée");
            } else if (event.right.isDown) {
                console.log("touche de droite pressée");
            } else if (event.down.isDown) {
                console.log("touche du bas pressée");
            }
        }

    },
};