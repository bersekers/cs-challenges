from math import ceil

text = open("texte_clair", "rb").read()
result = open("crypted", "wb")

key = [0xAD, 0xCB]

result_text = bytes(j ^ key[i % len(key)] for i, j in enumerate(text))
print(result_text)
result.write(result_text)
