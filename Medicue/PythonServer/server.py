import sys, json
import BaseHTTPServer
from SimpleHTTPServer import SimpleHTTPRequestHandler

class Req(SimpleHTTPRequestHandler):
    def generateResponse(self):
        f = open('/media/sdcard/fuck.json')
        pairs = []
        for line in f:
            (name, time) = line[0:-1].split(',')
            pairs.append({
                'name': name,
                'time': time,
            })
        f.close()
        return json.dumps(pairs)

    def do_GET(self):
        response = self.generateResponse()
        self.send_response(200)
        self.send_header("Content-type", "text/html")
        self.send_header("Content-length", len(response))
        self.end_headers()
        self.wfile.write(response)

HandlerClass = Req
ServerClass  = BaseHTTPServer.HTTPServer
Protocol     = "HTTP/1.0"

if sys.argv[1:]:
    port = int(sys.argv[1])
else:
    port = 8000
server_address = ('127.0.0.1', port)

HandlerClass.protocol_version = Protocol
httpd = ServerClass(server_address, HandlerClass)

sa = httpd.socket.getsockname()
print "Serving HTTP on", sa[0], "port", sa[1], "..."
httpd.serve_forever()
