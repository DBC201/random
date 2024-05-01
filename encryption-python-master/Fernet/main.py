from cryptography.fernet import Fernet
import os


def load_key(key_file):
    try:
        with open(key_file, "rb") as file:
            key = file.read()
    except FileNotFoundError:
        key = Fernet.generate_key()
        with open(key_file, "wb") as file:
            file.write(key)
    return key


def encrypt(files, cipher):
    try:
        os.chdir("encrypted")
    except FileNotFoundError:
        os.mkdir("encrypted")
    for file in files:
        try:
            with open(file, "rb") as f:
                content = f.read()
            with open("encrypted/"+file, "wb") as f:
                f.write(cipher.encrypt(content))
        except Exception as e:
            print(e)
            print("Unable to encrypt", file)


def decrypt(files, cipher):
    try:
        os.chdir("decrypted")
    except FileNotFoundError:
        os.mkdir("decrypted")
    for file in files:
        try:
            with open(file, "rb") as f:
                content = f.read()
            with open("decrypted/"+file, "wb") as f:
                f.write(cipher.decrypt(content))
        except Exception as e:
            print(e)
            print("Unable to decrypt", file)


if __name__ == '__main__':
    print("Change your directory to where the files and the key is at")
    while True:
        print(os.getcwd()+"->", end='')
        cd = input().strip()
        if cd == "done":
            break
        try:
            os.chdir(cd)
        except FileNotFoundError:
            print("Type .. to go up, folder name to change")
            print("Or you could write a full path")
            print("Type done to continue")
    key_file = input("Enter the name of the key file(it will create new if first time):")
    key = load_key(key_file)
    cipher = Fernet(key)
    selection = input("e to encrypt d to decrypt else to quit:").strip().lower()
    files = input("Enter file names with extensions:").split(' ')
    if selection == 'e':
        encrypt(files, cipher)
    elif selection == 'd':
        decrypt(files, cipher)
