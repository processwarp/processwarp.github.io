---
layout: post
title:  Ubuntuでのネイティブクライアントのコンパイル方法
date:   2015-06-09 20:00:00
lang:   ja
category: docs
---

Ubuntu環境でのネイティブクライアントのコンパイル方法について説明します。
作業はおおまかに以下の4つの項目にわかれています。

* aptを利用した前提アプリケーションのインストール
* Socket.IO C++ Clientのコンパイル
* PROCESS WARPのコンパイル
* 設定ファイルの編集と疎通の確認

## 前提環境

* Ubuntu desktop 14.04 amd64

## aptを利用した前提アプリケーションのインストール

コンソールからaptを利用して前提アプリケーションをインストールします。

    $ sudo apt-get install clang cmake git libssl-dev libboost-dev libboost-system-dev libboost-date-time-dev libboost-random-dev

## Socket.IO C++ Clientのコンパイル

PROCESS WARPのコンパイルのためには既存パッケージの他にSocket.IO C++ Clientが必要になります。
[Socket.IO C++ Clientはgithubで公開されています。](https://github.com/socketio/socket.io-client-cpp)
2015/6/9現在パッケージ化されていないため、以下のとおり手動でコンパイルします。

    $ cd <作業ディレクトリ>
    $ git clone --recurse-submodules https://github.com/socketio/socket.io-client-cpp.git
    $ cd socket.io-client-cpp

UbuntuではCMakeとBoostのバージョンが低いため、CMakeLists.txtを以下のように編集します。

    $ vi CMakeLists.txt
    
    編集前:cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
    編集後:cmake_minimum_required(VERSION 2.8.0 FATAL_ERROR)
    
    編集前:set(BOOST_VER "1.55.0" CACHE STRING "boost version" )
    編集後:set(BOOST_VER "1.54.0" CACHE STRING "boost version" )

編集後、コンパイル作業を続けます。
Ubuntuのデフォルトコンパイラはgccでエラーが出るため、clangを利用するように変更します。

    $ export CC=clang
    $ export CXX=clang++
    $ cmake -D CMAKE_CXX_FLAGS=-std=c++11 .
    $ make
    $ make install

コンパイルが終了すると、buildディレクトリにヘッダ及びライブラリが格納されます。

## PROCESS WARPのコンパイル

いよいよPROCESS WARPのコンパイルにとりかかります。

    $ cd <作業ディレクトリ>
    $ git clone https://github.com/processwarp/processwarp.git
    $ cd processwarp
    $ mkdir build
    $ cd build
    $ cmake -D SIO_DIR=<作業ディレクトリ>/socket.io-client-cpp/build ..
    $ make

コンパイルが終了すると、build/srcディレクトリ下にcoreプログラムが格納されます。

## 設定ファイルの編集と疎通の確認

ネイティブクライアントはWEB版と異なり、起動用の設定ファイルを必要とします。
WEB版と同じサーバに接続します。
予めWEB版フロントエンドからアカウント登録をしておいてください。
デバイスはネイティブクライアントから自動的に登録されます。

conf/conf_sample.jsonをコピーし、各自の環境に合わせて編集しましょう。

    {
        "server":  "https://prev.processwarp.org/",
        "account": "<WEB版で登録したアカウント>",
        "password":"<WEB版で登録したパスワード>",
        "device-name": "<デバイス名>",
    
        "libs":[],
    
        "lib-filter":[
	        "<conf/libfilter_ubuntu.jsonへのフルパス>"
        ],
    
        "apps":[]
    }

編集が終わったら設定ファイルを指定して、ネイティブクライアントを起動します。


    $ core -c <設定ファイル>

ネイティブクライアントにはGUIがないためWEB版からコントロールする必要があります。
WEB版へログインし、[Try!に従い](/ja/try)サンプルアプリケーションを実行し、
ネイティブクライアントへのWarpを実行することで疎通の確認ができます。
