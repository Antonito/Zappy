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

        console.log("drawwww ");

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

        if (pos_x < 0 && (mob.X >= 0 && mob.X < 10))
            pos_x = mob.X + (WSZW - startX);
        if (pos_y < 0 && (mob.Y >= 0 && mob.Y < 10))
            pos_y = mob.Y + (WSZH - startY);

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

    var image = resources_layer.create(
        shiftX + egg.pos_x * 100 + SPRITES_POSITION.EGG.X,
        shiftY + egg.pos_y * 100 + SPRITES_POSITION.EGG.Y, 'egg');

    ScaleImage(
        image,
        SPRITES_POSITION.EGG.SW,
        SPRITES_POSITION.EGG.SH
    );

}