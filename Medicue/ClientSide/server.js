var net = require('net');
var fs = require('fs');

/*
 * Creates a new TCP server. The handler argument is automatically
 * set as a listener for the 'connection' event.
 */
var server = net.createServer(function (socket) {
    console.log("Connection from " + socket.remoteAddress);
    fs.readFile('food.txt', 'utf8', function(err, data) {
        var pairs = [];
        var lines = data.split('\n');
        for (var i = 0; i < lines.length; i++) {
            var line = lines[i];
            if (line != "") {
                var pair = line.split(',');
                pairs.push({
                    name: pair[0],
                    time: Number(pair[1]),
                });
            }
        }
        socket.end(JSON.stringify(pairs));
    });
});

server.listen(1337, "localhost");
console.log("TCP server listening on port 1337 at localhost.");
