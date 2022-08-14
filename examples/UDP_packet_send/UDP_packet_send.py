import socket

UDP_IP = "192.168.2.87"
UDP_PORT = 1234

MESSAGE = b"Hello, RASPBERRY_PI_PICO_W!"

print("UDP target IP: %s" % UDP_IP)
print("UDP target port: %s" % UDP_PORT)
print("message: %s" % MESSAGE)

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.sendto(MESSAGE, (UDP_IP, UDP_PORT))
