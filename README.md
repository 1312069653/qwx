qwx
----

WeChat Qt frontend 
微信Qt前端，基于[网页微信协议](https://github.com/Urinx/WeixinBot/blob/master/README.md)

images and protocol ***Copyright (C) by [Tencent](http://weixin.qq.com/)*** 
图片、协议***版权归[腾讯](http://weixin.qq.com/) 所有！*** 请不要用于商业目的！

## Build && Install

### Dependences for Loongnix

```
sudo yum install qt5-linguist qt5-qtdeclarative-devel
```

### Dependences for ArchLinux

```
sudo pacman -S qt5-base qt5-declarative qt5-tools qt5-quickcontrols qt5-graphicaleffects
```

### Dependences for Ubuntu 15.04+

```
sudo apt-get install qtdeclarative5-dev qt5-default qt5-qmake qml-module-qtquick-controls qtdeclarative5-controls-plugin
```

### Build for dynamic analysis

```
mkdir build
cd build
cmake .. -DCMAKE_C_COMPILER=clang \
    -DCMAKE_CXX_COMPILER=clang++ \
    -DCMAKE_C_FLAGS="-fsanitize=address" \
    -DCMAKE_CXX_FLAGS="-fsanitize=address" \
    -DCMAKE_LINKER_FLAGS="-fsanitize=address" \
    -DCMAKE_BUILD_TYPE=Debug
make
./src/qwx
```

## i18n also welcome other languages

```
lupdate src/*.cpp qml/*.qml -ts translations/zh_CN.ts
```
