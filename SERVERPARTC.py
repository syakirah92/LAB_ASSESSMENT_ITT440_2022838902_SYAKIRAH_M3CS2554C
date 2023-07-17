import socket
import random

def is_prime(number):
  if number <= 1:
    return False
  for i in range(2, number):
    if number % i == 0:
      return False
  return True

def main():
  server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
  server_address = ("localhost", 8080)
  server_socket.bind(server_address)

  while True:
    data, client_addr = server_socket.recvfrom(1024)
    number = int(data.decode())

    is_prime_str = "Prime" if is_prime(number) else "Not prime"

    serv_socket.sendto(is_prime_str.encode(), client_addr)

if __name__ == "__main__":
  main()
