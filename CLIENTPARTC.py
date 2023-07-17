import socket

def get_numb():
  numb = input("Enter a number: ")
  return int(numb)

def main():
  client_sock= socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
  server_addr = ("localhost", 8080)

  numb = get_numb()

  client_socket.sendto(str(numb).encode(), server_addr)

  data, _ = client_sock.recvfrom(1024)
  is_prime_str = data.decode()

  print(f"The number {numb} is {is_prime_str}"
if __name__ == "__main__":
  main(
