#!/usr/local/bin/zsh

sudo pkg install -y sdcc
rm -rf wincpc
mkdir wincpc

pushd wincpc
wget http://www.wincpc.ch/wincpc.zip
unzip wincpc.zip
popd
