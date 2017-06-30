var net = require('net');
var io = require('socket.io')();

var ZAPPY_SERVER_PORT = 4242;
var ZAPPY_SERVER_IP = '127.0.0.1';

var MW_SERVER_PORT = 3000;
// var MW_SERVER_IP = '127.0.0.1';

var client = new net.Socket();

const WebSocket = require('ws');

var wss;

client.connect(ZAPPY_SERVER_PORT, ZAPPY_SERVER_IP, function() {
    console.log('[ZappyServer] Connected');

    // Notify the server that we are a graphic client
    client.write('GRAPHIC\n');

    // Start listening for socketIO clients
    wss = new WebSocket.Server({ port: MW_SERVER_PORT });

    wss.on('connection', function connection(ws, req) {

        // Notify in console that a new customer has logged in
        console.log("New client connected from " + req.connection.remoteAddress);

    });

    wss.on('disconnect', function() {
        console.log('[WebSocket] Client disconnected');
    });

});

// ZappyServer middleware
client.on('data', function(data) {

    var datastr = String.fromCharCode.apply(null, new Uint16Array(data));

    // Send data to all clients
    wss.clients.forEach(function each(client) {
        if (client.readyState === WebSocket.OPEN) {
            client.send(datastr);
        }
    });

});

// ZappyServer close handler
client.on('close', function() {
    console.log('[ZappyServer] Connection closed');
});