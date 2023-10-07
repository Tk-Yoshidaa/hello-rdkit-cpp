# hello-rdkit-cpp

condaを使わずにc++向けにRDKitをインストールする．

<!-- 以下のように -->
パッケージマネージャー経由でインストールすることもできるが，CMakeによる管理ができないため自前でビルドする方針をとる．
<!-- ```sh
sudo apt install librdkit-dev
``` -->

## RDKitの取得

```sh
mkdir rdkit
curl -sSL https://github.com/rdkit/rdkit/archive/refs/tags/Release_2022_09_5.tar.gz | tar -xvzf - -C rdkit --strip-components=1
```
`Release_2022_09_5`は適当なものに置き換える．

## RDKitのビルド

依存するパッケージがインストールされていない場合は事前にそれらをインストールする必要あり．
```sh
sudo apt update
sudo apt install libboost-all-dev
sudo apt install libfreetype-dev
sudo apt install libeigen3-dev
```

If you do not have sudo, you can download `freetype` [here](https://freetype.org/download.html).
To build `freetype`, 
```sh
wget https://download.savannah.gnu.org/releases/freetype/freetype-2.10.0.tar.gz
tar -xvzf freetype-2.10.0.tar.gz
cd freetype-2.10.0
./configure --prefix=$HOME/.local/share/freetype
make && make install
```

RDKitを以下でビルドする．
なお，ここではCMakeのオプション`CMAKE_INSTALL_PREFIX`を`$HOME/.local/share/rdkit`として，ビルド先を指定している．

```sh
mkdir rdkit/build
cd rdkit/build
```

```sh
cmake -DCMAKE_BUILD_TYPE=Release\
    -DRDK_BUILD_PYTHON_WRAPPERS=OFF\
    -DRDK_INSTALL_INTREE=OFF\
    -DCMAKE_INSTALL_PREFIX=$HOME/.local/share/rdkit ..
make && make install
```

If you have installed `freetype` manually, run following commands instead:
```sh
cmake -DCMAKE_BUILD_TYPE=Release\
    -DRDK_BUILD_PYTHON_WRAPPERS=OFF\
    -DRDK_INSTALL_INTREE=OFF\
    -DFREETYPE_LIBRARY=$HOME/.local/share/freetype/lib/libfreetype.so\
    -DFREETYPE_INCLUDE_DIRS=$HOME/.local/share/freetype/include/freetype2\
    -DCMAKE_INSTALL_PREFIX=$HOME/.local/share/rdkit ..
make && make install
```

最後に，以下をrcファイルに追加してパスを設定する．ここでのパスは`CMAKE_INSTALL_PREFIX`に指定したものと同じものを設定する必要がある．
```
export LD_LIBRARY_PATH=$HOME/.local/share/rdkit:$LD_LIBRARY_PATH
```

追記したら，変更を反映する．
```
source ~/.bashrc
```


## プログラムのビルド

`hello.cpp`のあるディレクトリにて以下の方法でビルドする．

```sh
mkdir build
cd build
cmake -DCMAKE_PREFIX_PATH=$HOME/.local/share/rdkit ..
make
```
ただし上記コマンドは[Makefile](./Makefile)にまとめているため，`hello.cpp`のあるディレクトリにて単に，
```sh
make
```
とするだけでもビルドできる．

`build`ディレクトリ内（[Makefile](./Makefile)を用いてビルドした場合は，`hello.cpp`のあるディレクトリ内）に生成される`hello`を実行する．
```sh
./hello
# Hello RDKit on C++ !!
# Usage: ./hello SMILES

./hello c1ccccc1
# Input SMILES: c1ccccc1
# Input SMILES Successfully parsed!!
# Molecule Information:
#         # of atoms: 6
#         # of bonds: 6
#         # of SSSR rings: 1
```
