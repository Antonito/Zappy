var symbolsFunctions = {
    "msz": function(args, raw) {
        var params = args.split(" ");

        var sizeX = params[1];
        var sizeY = params[2];

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