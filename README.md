# hello-rdkit-cpp

condaを使わずにc++向けにRDKitをインストールする．

以下のようにパッケージマネージャー経由でインストールすることもできるが，CMakeによる管理ができないため自前でビルドする方針をとる．
```sh
sudo apt install librdkit-dev
```

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

RDKitを以下でビルドする．
```sh
mkdir rdkit/build && cd rdkit/build
```

設定オプションを指定する．ここでは`$HOME/.local/share/rdkit`にビルドするように設定している．
```sh
cmake -DCMAKE_BUILD_TYPE=Release\
    -DRDK_BUILD_PYTHON_WRAPPERS=OFF\
    -DRDK_INSTALL_INTREE=OFF\
    -DCMAKE_INSTALL_PREFIX=$HOME/.local/share/rdkit ..
```


インストール.
```sh
make && make install
```

以下をrcファイルに追加してパスを設定する．
```
export $HOME/.local/share/rdkit:$LD_LIBRARY_PATH
```


## プログラムのビルド

`hello.cpp`のあるディレクトリにて以下の方法でビルド
```sh
mkdir build
cd build
cmake -DRDKit_DIR=./rdkit/lib/cmake/rdkit -DRKit_INCLUDE_DIR=./rdkit/Code ..
make
```

挙動を確認する．
```sh
./hello
# Hello RDKit on C++ !!
```