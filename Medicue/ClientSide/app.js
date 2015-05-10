var express = require('express'),
	app = express(),
	server = require('http').createServer(app),
	io = require('socket.io').listen(server);

app.use(express.static('public'))

server.listen(4000);

app.get('/', function(req,res)
	{res.sendFile(__dirname + '/index.html');

	});	