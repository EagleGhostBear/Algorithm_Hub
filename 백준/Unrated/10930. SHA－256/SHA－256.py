import hashlib
data1=input()
encoding_data=data1.encode('utf-8')
hash_data = hashlib.new('sha256')
hash_data.update(encoding_data)
print(hash_data.hexdigest())