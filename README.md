# PeachOS
PeachOS

Operating system from the course "Build a multitasking operating system and kernel with an interactive shell!" by Daniel McCarthy.

## How to build

Install the following packages.

```
sudo apt install nasm
sudo apt install qemu-system-x86
sudo apt install build-essential
sudo apt install bison
sudo apt install flex
sudo apt install libgmp3-dev
sudo apt install libmpc-dev
sudo apt install texinfo
sudo apt install libisl-dev
```

Download the file "binutils-2.35.tar.gz" from https://ftp.gnu.org/gnu/binutils/
Download the file "gcc-10.2.0.tar.gz" from https://ftp.lip6.fr/pub/gcc/releases/gcc-10.2.0/

In your terminal export the following variables.

```
export PREFIX="$HOME/opt/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"
```

Build binutils by running the following commands.

```
cd $HOME/src

mkdir build-binutils
cd build-binutils
../binutils-x.y.z/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make
make install
```

Build GCC Cross Compiler by running the following commands:

```
cd $HOME/src

# The $PREFIX/bin dir _must_ be in the PATH. We did that above.
which -- $TARGET-as || echo $TARGET-as is not in the PATH

mkdir build-gcc
cd build-gcc
../gcc-x.y.z/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers --disable-hosted-libstdcxx
make all-gcc
make all-target-libgcc
make install-gcc
make install-target-libgcc
```

Build the project by running the following commands:

```
make clean
./build.sh
```

Run the project with the following command:

```
qemu-system-x86_64 -hda ./bin/os.bin
```