## randpass

The C++ `<random>` uses the The **Mersenne Twister** which is [pseudorandom number generator](https://en.wikipedia.org/wiki/Pseudorandom_number_generator) (PRNG) which is not cryptographically secure. While surfing through libsodium's [documentation](https://libsodium.gitbook.io/doc/) I noticed in the [FAQ](https://libsodium.gitbook.io/doc/quickstart#how-do-i-generate-random-numbers-that-are-safe-to-use-for-cryptography) `randombytes` API can be used to generate random numbers that are cryptographically safe. So wanted to use the [libsodium's](https://libsodium.gitbook.io/doc/generating_random_data) random number generation for random password generation. I haven't checked the "true" randomness of the output here and made this as a hobby project.

## Installtion

### Dependencies
* [Conan package manager](https://docs.conan.io/en/latest/installation.html)

### Steps
>  You can either clone or download the project

```bash

git clone git@github.com:neelabalan/randpass.git
cd randpass 
mkdir build && cd build
conan install ..
cd ..
cmake .
make
```

## Usage

The binary is created in `bin` folder of the project directory

```bash
./randpass --help   # for listing the available arguments
```

### Examples

```bash
~ ./randpass --help
Usage: randpass [options]

Optional arguments:
-h --help   	show this help message and exit
-L --length 	length of the password string
-p --pass   	number of passwords to be generated
-u          	include uppercase characters in password
-l          	include lowecase characters in password
-s          	include symbols in password
-n          	include numbers in password

~ ./bin/randpass -L 10 -p 5 -n

5570511064
4135899360
1673500421
7955381034
0917020964

~ ./bin/randpass -L 10 -p 5 -l

anqubvcqth
dwtdjmkenz
ctoecuogkp
gjpopaocro
gtnraqghag

~ ./bin/randpass -L 15 -p 2 -ul  

GLXXVQcFbSjCSpw
zaoVsaHcwjVcnvc
```

