from random import randint as ri

size = 1024 ** 2
a = ri(0x10000000, 0xffffffff)
b = ri(0x10000000, 0xffffffff)
print('a = %u, b = %u' % (a, b))

fp = open('test.file', 'wb')

for i in range(size):
    a *= 256
    fp.write(bytes([a // b]))
    fp.flush()
    a %= b

fp.close()