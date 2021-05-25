import time
import hashlib

inp_string = input()
start = time.time() 

x = 0x00000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF  # target
cnt = 1

while 1:
    temp = inp_string+str(cnt)
    encoded = temp.encode()  # convert temp into binary
    # output string containing number in hex
    y = hashlib.sha256(encoded).hexdigest()

    value = int(y, 16)  # string into hexadecimal int
    if(value < x):
        print(f"Appending {cnt} gives less value than target")
        print(f"Resultant string =  '{temp}'")
        print(f"Hash value =  '{value}'")

        break
    cnt = cnt+1


end = time.time()
print(f"Time taken by program after taking input is {end - start}s")


