import socket, logging 
from thread import start_new_thread
from cache import Cache
from util import *

# Configurar o logging

logging.basicConfig(filename = 'proxy.log', filemode='a',format='%(asctime)s,%(msecs)d %(name)s %(levelname)s %(message)s', datefmt='%H:%M:%S', level=logging.DEBUG)

log = logging.getLogger('proxy')

class ServidorProxy():
    """docstring for ServidorProxy"""
    def __init__(self):
    self.port = 54321
    self.buffer_size = 8192
    self.conexoes = 10
    self.cache = Cache(999999999)

  def start(self):
    try:
      sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
      sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
      sock.bind(("localhost", self.port))
      sock.listen(self.conexoes)
    except Exception, e:
      print "Erro ao iniciar o servidor Proxy"
      print e
      return

    while True:
      conn, addr = sock.accept()
      data = conn.recv(self.buffer_size)
      start_new_thread(self.requestHandler, (data, conn, addr))

  def requestHandler(self, data, conn, addr):

    #Parser of the client request that return a dictionary of data key-value
    recv_data = parseHeader(data)
    response = ""
    # Do not use the GET method: not implemented
    if recv_data['method'] != 'GET':
      notImplementedMethod(conn)
      return

    # url and host of the requested server
    url = recv_data['url']
    host = recv_data['Host']
    log.info("Request from %s to %s" % (addr, url))

    # Case the 'no-cache' field of header is present in 'pragma' or 'cache-control', do not stor in cache
    
    if self.cache.existingUrl(url):
      # If-modified-since
      if 'If-Modified-Since' in recv_data.keys():
        log.debug("[*] If-Modified-Since - Verify server object")
        result = getHttp(host, data, self.buffer_size)
        parsed_result = parseServerHeader(result)

        #Case the response is 304, the object is already updated so, use the object stored in cache
        if parsed_result['status_code'] == '304':
          log.debug("[*] If-Modified-Since - Object: %s Updated" %(url))
          log.info("Cache HIT: " + url)
          response = self.cache.getData(url)
        # Case the response is 200, the object is out of date so, use the object coming from server
        elif parsed_result['status_code'] == '200':
          log.debug("[*] If-Modified-Since - Necessary update %s" % (url))
          self.cache.update(url, result)
          response = result
          log.debug("[*] If-Modified-Since - %s Updated" %(url))
      else:
        # Case do not have If-Modified-Since, just take the cache element
        log.info("Cache HIT: " + url)
        response = self.cache.getData(url)
    else:
      log.info("Cache MISS: "+ url)
      
      if 'Cache-Control' in recv_data.keys() and recv_data['Cache-Control'] == 'no-cache':
        log.info("Cache-Control - 'no-cache'")
        response = getHttp(host, data, self.buffer_size)
      else:
        response = getHttp(host, data, self.buffer_size)
        self.cache.cachePush(url, response)

    conn.send(response)
    conn.close()
