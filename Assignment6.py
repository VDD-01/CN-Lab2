import socket
import threading
import time

PORT = 10000

def udp_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    # Allow port to be reused
    server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

    server_socket.bind(("127.0.0.1", PORT))

    print("UDP Server started...")

    while True:
        data, address = server_socket.recvfrom(1024)
        message = data.decode()

        if message.lower() == "exit":
            print("Server stopped.")
            break

        # Convert uppercase to lowercase
        result = message.lower()

        server_socket.sendto(result.encode(), address)

    server_socket.close()


# Start UDP server
server_thread = threading.Thread(target=udp_server)
server_thread.start()

# Give server time to start
time.sleep(1)


# ---------------- CLIENT ----------------
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

server_address = ("127.0.0.1", PORT)

message = input("Enter a string: ")

# Send string to server
client_socket.sendto(message.encode(), server_address)

# Receive response
data, address = client_socket.recvfrom(1024)

print("Original string :", message)
print("Lowercase string:", data.decode())

# Tell server to stop
client_socket.sendto(b"exit", server_address)

client_socket.close()

server_thread.join()
