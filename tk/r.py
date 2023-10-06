import sys

size = 1024 ** 2
a = int(sys.argv[1])
b = int(sys.argv[2])
print('a = %u, b = %u' % (a, b))

fp = open('test.file', 'rb')

for i in range(size):
    a *= 256
    print('1' if fp.read(1) == bytes([a // b]) else 0, end = '')
    a %= b

fp.close()