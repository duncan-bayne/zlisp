sudo apt-get install -y wine unzip sdcc
rm -rf wincpc
mkdir wincpc

pushd wincpc
wget http://www.wincpc.ch/wincpc.zip
unzip wincpc.zip
popd
