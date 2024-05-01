import rsa


def load_keys():
    try:
        with open('public', mode='rb') as file:
            public = rsa.PublicKey.load_pkcs1(file.read())
        with open('private', mode='rb') as file:
            private = rsa.PrivateKey.load_pkcs1(file.read())
    except FileNotFoundError:
        public, private = rsa.newkeys(128)
        with open('public', mode='wb') as file:
            file.write(public.save_pkcs1())
        with open('private', mode='wb') as file:
            file.write(private.save_pkcs1())

    return public, private


if __name__ == '__main__':
    public, private = load_keys()
    print(public)
    print(private)
    message = "hello".encode()
    encrypted = rsa.encrypt(message, public)
    print("Encrypted:", encrypted)
    decrypted = rsa.decrypt(encrypted, private)
    print("Decrypted:", decrypted.decode("utf-8"))
