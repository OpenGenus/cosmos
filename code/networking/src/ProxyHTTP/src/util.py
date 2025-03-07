import socket

def parseHeader(data):

  print data
  linhas = data.splitlines()
  primeira_linha = linhas[0].split(' ')
  resultado = {'method': primeira_linha[0], 'url': primeira_linha[1], 'version': primeira_linha[2]}
  for l in linhas[1:-1]:
    split = l.split(':', 1)
    resultado[split[0]] = split[1].strip()

  return resultado

def parseServerHeader(data):

  linhas = data.splitlines()
  primeira_linha = linhas[0].split(' ')
  status_code = primeira_linha[1]
  resultado = {'version': primeira_linha[0], 'status_code': primeira_linha[1], 'status': primeira_linha[2]}

  for l in linhas[1:-1]:
    split = l.split(':', 1)
    resultado[split[0]] = split[1].strip()
  return resultado

def getHttp(url, response, buffer_size):

  response = response.replace("HTTP/1.1", "HTTP/1.0")
  sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
  sock.connect((url, 80))
  sock.send(response)
  response = ""
  response_part = sock.recv(buffer_size)

  while response_part:
    if len(response_part) > 0:
      response += response_part
    else:
      break
    response_part = sock.recv(buffer_size)

  return response

def notImplementedMethod(conn):

  string = "HTTP/1.1 501 Not Implemented\n"
  string += "Date: Thu, 20 May 2004 21:12:58 GMT\n"
  string += "Connection: close\n"
  string += "Server: Python/6.6.6 (custom)\n"

  conn.send(string)
