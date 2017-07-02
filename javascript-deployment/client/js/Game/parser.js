var symbolsFunctions = {
    "msz": function(args, raw) {
        var params = args.split(" ");

        var sizeX = params[1];
        var sizeY = params[2];

        WSZW = sizeX;
        WSZH = sizeY;

        // Re-init the game map
        raw_map_resources = [];
        for (var y = 0; y < sizeY; ++y) {
            raw_map_resources[y] = [];
            for (var x = 0; x < sizeX; ++x) {
                raw_map_resources[y][x] = {
                    'food': 0,
                    'linemate': 0,
                    'deraumere': 0,
                    'sibur': 0,
                    'mendiane': 0,
                    'phiras': 0,
                    'thystame': 0
                };
            }
        }
    },

    "bct": function(args, raw) {
        var params = args.split(" ");

        if (params.length === 10) {
            raw_map_resources[params[2]][params[1]] = {
                'food': params[3],
                'linemate': params[4],
                'deraumere': params[5],
                'sibur': params[6],
                'mendiane': params[7],
                'phiras': params[8],
                'thystame': params[9]
            };
        }
    },

    "ppo": function(args) {

        var params = args.split(" ");

        if (raw_mobs_list.find((e) => { return e.id == params[1]; }) == undefined) {
            raw_mobs_list.push({
                'id': params[1],
                'X': params[2],
                'Y': params[3],
                'O': params[4],
                'L': 1,
                'food': 0,
                'linemate': 0,
                'deraumere': 0,
                'sibur': 0,
                'mendiane': 0,
                'phiras': 0,
                'thystame': 0,
            });
        } else {
            raw_mobs_list.find((e) => { return e.id == params[1]; }).X = params[2];
            raw_mobs_list.find((e) => { return e.id == params[1]; }).Y = params[3];
            raw_mobs_list.find((e) => { return e.id == params[1]; }).O = params[4];
        }
    },

    "pbc": function(args) {

        var params = args.split(" ");

        raw_mobs_list.find((e) => {

            if (e.id == params[1]) {

                var pos_x = e.X - startX;
                var pos_y = e.Y - startY;

                if ((0 <= pos_x && pos_x <= 10) &&
                    (0 <= pos_y && pos_y <= 10)) {

                    var image = animations_layer.create(
                        shiftX + pos_x * 100,
                        shiftY + pos_y * 100,
                        'broadcast');

                    ScaleImage(
                        image,
                        100,
                        100
                    );

                    setTimeout(function() {
                        animations_layer.remove(image);
                    }, 500);

                }
                return true;
            }
            return false;
        })
    }

}

var parseData = function(data) {

    var lines = data.split("\n");

    lines.forEach((e) => {

        var sym = e.substr(0, e.indexOf(" "));

        if (sym in symbolsFunctions) {
            symbolsFunctions[sym](e);
        }

    });

}