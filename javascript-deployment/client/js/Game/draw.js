function DrawInventory(mob) {

    var inventory = inventory_layer.create(
        800,
        600, 'inventory');
    ScaleImage(
        inventory,
        200,
        300
    );
    inventory_layer.add(inventory);

    // mob id
    var mob_appearance = inventory_layer.create(
        810,
        610,
        MOBS_COLOR[mob.id % MOBS_COLOR.length]);

    ScaleImage(
        mob_appearance,
        64,
        64
    );
    inventory_layer.add(mob_appearance);
    inventory_layer.add(game.add.text(870, 620, mob.id, inventory_style));

    // Food
    var food = inventory_layer.create(
        910,
        610,
        'food');

    ScaleImage(
        food,
        64,
        64
    );
    inventory_layer.add(food);
    inventory_layer.add(game.add.text(960, 620, mob.food, inventory_style));

    // Linemate
    var linemate = inventory_layer.create(
        810,
        680,
        'linemate');

    ScaleImage(
        linemate,
        64,
        64
    );

    inventory_layer.add(linemate);
    inventory_layer.add(game.add.text(870, 690, mob.linemate, inventory_style));

    //  Deraumere
    var deraumere = inventory_layer.create(
        910,
        680,
        'deraumere');

    ScaleImage(
        deraumere,
        64,
        64
    );
    inventory_layer.add(deraumere);
    inventory_layer.add(game.add.text(960, 690, mob.deraumere, inventory_style));

    // Sibur
    var sibur = inventory_layer.create(
        810,
        755,
        'sibur');

    ScaleImage(
        sibur,
        64,
        64
    );

    inventory_layer.add(sibur);
    inventory_layer.add(game.add.text(870, 770, mob.sibur, inventory_style));

    // Mendiane
    var mendiane = inventory_layer.create(
        900,
        755,
        'mendiane');

    ScaleImage(
        mendiane,
        64,
        64
    );
    inventory_layer.add(mendiane);
    inventory_layer.add(game.add.text(960, 770, mob.mendiane, inventory_style));

    // Phiras
    var phiras = inventory_layer.create(
        810,
        830,
        'phiras');

    ScaleImage(
        phiras,
        64,
        64
    );

    inventory_layer.add(phiras);
    inventory_layer.add(game.add.text(870, 845, mob.phiras, inventory_style));

    // Thystame
    var thystame = inventory_layer.create(
        900,
        830,
        'thystame');

    ScaleImage(
        thystame,
        64,
        64
    );
    inventory_layer.add(thystame);
    inventory_layer.add(game.add.text(960, 845, mob.thystame, inventory_style));

}

function DrawAll(startX, startY) {

    /* Draw Resources */
    for (var y = 0; y < 10 && y < raw_map_resources.length; ++y) {

        for (var x = 0; x < 10 && x < raw_map_resources[(y + startY) % raw_map_resources.length].length; ++x) {

            var cell = raw_map_resources[(y + startY) % raw_map_resources.length][(x + startX) % raw_map_resources.length];

            DrawCellResources(cell, x, y);

        }

    }

    /* Draw Mobs */
    raw_mobs_list.forEach((e) => {
        DrawCellMob(e);
    });

    /* Draw Eggs */
    raw_eggs_list.forEach((e) => {
        DrawCellEgg(e);
    });

    var pos_info = game.add.text(10, 10, "POS : (" + startX + ", " + startY + ")", font_style);
    text_layer.add(pos_info);
}

function DrawCellResources(cell_res, x, y) {

    if (cell_res.food > 0) {

        var image = resources_layer.create(
            shiftX + x * 100 + SPRITES_POSITION.FOOD.X,
            shiftY + y * 100 + SPRITES_POSITION.FOOD.Y, 'food');

        ScaleImage(
            image,
            SPRITES_POSITION.FOOD.SW,
            SPRITES_POSITION.FOOD.SH
        );

    }

    if (cell_res.linemate > 0) {

        var image = resources_layer.create(
            shiftX + x * 100 + SPRITES_POSITION.LINEMATE.X,
            shiftY + y * 100 + SPRITES_POSITION.LINEMATE.Y, 'linemate');

        ScaleImage(
            image,
            SPRITES_POSITION.LINEMATE.SW,
            SPRITES_POSITION.LINEMATE.SH
        );

    }

    if (cell_res.deraumere > 0) {

        var image = resources_layer.create(
            shiftX + x * 100 + SPRITES_POSITION.DERAUMERE.X,
            shiftY + y * 100 + SPRITES_POSITION.DERAUMERE.Y, 'deraumere');

        ScaleImage(
            image,
            SPRITES_POSITION.DERAUMERE.SW,
            SPRITES_POSITION.DERAUMERE.SH
        );

    }

    if (cell_res.sibur > 0) {

        var image = resources_layer.create(
            shiftX + x * 100 + SPRITES_POSITION.SIBUR.X,
            shiftY + y * 100 + SPRITES_POSITION.SIBUR.Y, 'sibur');

        ScaleImage(
            image,
            SPRITES_POSITION.SIBUR.SW,
            SPRITES_POSITION.SIBUR.SH
        );

    }

    if (cell_res.mendiane > 0) {

        var image = resources_layer.create(
            shiftX + x * 100 + SPRITES_POSITION.MENDIANE.X,
            shiftY + y * 100 + SPRITES_POSITION.MENDIANE.Y, 'mendiane');

        ScaleImage(
            image,
            SPRITES_POSITION.MENDIANE.SW,
            SPRITES_POSITION.MENDIANE.SH
        );

    }

    if (cell_res.phiras > 0) {

        var image = resources_layer.create(
            shiftX + x * 100 + SPRITES_POSITION.PHIRAS.X,
            shiftY + y * 100 + SPRITES_POSITION.PHIRAS.Y, 'phiras');

        ScaleImage(
            image,
            SPRITES_POSITION.PHIRAS.SW,
            SPRITES_POSITION.PHIRAS.SH
        );

    }

    if (cell_res.thystame > 0) {

        var image = resources_layer.create(
            shiftX + x * 100 + SPRITES_POSITION.THYSTAME.X,
            shiftY + y * 100 + SPRITES_POSITION.THYSTAME.Y, 'thystame');

        ScaleImage(
            image,
            SPRITES_POSITION.THYSTAME.SW,
            SPRITES_POSITION.THYSTAME.SH
        );

    }

}

function DrawCellMob(mob, x, y) {

    var pos_x = mob.X - startX;
    var pos_y = mob.Y - startY;

    if ((0 <= pos_x && pos_x < 10) &&
        (0 <= pos_y && pos_y < 10)) {

        var image = resources_layer.create(
            shiftX + pos_x * 100 + SPRITES_POSITION.MOB.X,
            shiftY + pos_y * 100 + SPRITES_POSITION.MOB.Y,
            MOBS_COLOR[mob.id % MOBS_COLOR.length]);

        ScaleImage(
            image,
            SPRITES_POSITION.MOB.SW,
            SPRITES_POSITION.MOB.SH
        );

    } else if (pos_x < 0 || pos_y < 0) {

        if (pos_x < 0 && (mob.X >= 0 && mob.X < 10)) {
            pos_x = parseInt(mob.X) + (parseInt(WSZW) - parseInt(startX));
        }
        if (pos_y < 0 && (mob.Y >= 0 && mob.Y < 10)) {
            pos_y = parseInt(mob.Y) + (parseInt(WSZH) - parseInt(startY));
        }

        if ((0 <= pos_x && pos_x < 10) &&
            (0 <= pos_y && pos_y < 10)) {

            var image = resources_layer.create(
                shiftX + pos_x * 100 + SPRITES_POSITION.MOB.X,
                shiftY + pos_y * 100 + SPRITES_POSITION.MOB.Y,
                MOBS_COLOR[mob.id % MOBS_COLOR.length]);

            ScaleImage(
                image,
                SPRITES_POSITION.MOB.SW,
                SPRITES_POSITION.MOB.SH
            );

        }
    }

}

function DrawCellEgg(egg, x, y) {

    var pos_x = egg.X - startX;
    var pos_y = egg.Y - startY;

    if ((0 <= pos_x && pos_x < 10) &&
        (0 <= pos_y && pos_y < 10)) {

        var image = resources_layer.create(
            shiftX + pos_x * 100 + SPRITES_POSITION.EGG.X,
            shiftY + pos_y * 100 + SPRITES_POSITION.EGG.Y,
            'egg');

        ScaleImage(
            image,
            SPRITES_POSITION.EGG.SW,
            SPRITES_POSITION.EGG.SH
        );

    } else if (pos_x < 0 || pos_y < 0) {

        if (pos_x < 0 && (egg.X >= 0 && egg.X < 10)) {
            pos_x = parseInt(egg.X) + (parseInt(WSZW) - parseInt(startX));
        }
        if (pos_y < 0 && (egg.Y >= 0 && egg.Y < 10)) {
            pos_y = parseInt(egg.Y) + (parseInt(WSZH) - parseInt(startY));
        }

        if ((0 <= pos_x && pos_x < 10) &&
            (0 <= pos_y && pos_y < 10)) {

            var image = resources_layer.create(
                shiftX + pos_x * 100 + SPRITES_POSITION.EGG.X,
                shiftY + pos_y * 100 + SPRITES_POSITION.EGG.Y,
                'egg');

            ScaleImage(
                image,
                SPRITES_POSITION.EGG.SW,
                SPRITES_POSITION.EGG.SH
            );

        }
    }

}