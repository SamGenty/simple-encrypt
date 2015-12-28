# simple-encrypt-decrypt
Encrypts and Decrypts Text Files based on user made encryption

#Description

###Encryption
Program processes "text.txt" and "encryptionKey.txt". 
Both text files are then compared and encrypted into a new file
named "encryptedText.txt". 

###Decryption
The new encrypted file can also be decrypted
into "decryptedText.txt" based on the "encryptionKey.txt"

#Format of Encryption Key file
Must be .txt file named "encryptionKey"
Key format must follow example:

```
e ~
t #
a $
o %
i ^
n &
s *
```

-------
All letter "e" are replaced with "~"
All letter "t" are replaced with "#" and so on.
There is no limit to the number of pairs in the encryption key file.

#Example Input
###text.txt contains the following
```
Hello, it's me
I was wondering if after all these years you'd like to meet
```
###encryptionKey.txt contains the following
```
e ~
t #
a $
o %
i ^
n &
s *
h +
r {
d }
l \
c /
u <
m >
w @
f _
```

#Resulting Output
###textEncrypted.txt contains the following
```
H~\\%, ^#'* >~
I @$* @%&}~{^&g ^_ $_#~{ $\\ #+~*~ y~${* y%<'} \^k~ #% >~~#
```
