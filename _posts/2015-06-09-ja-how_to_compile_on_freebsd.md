---
layout: post
title:  FreeBSDでのネイティブクライアントのコンパイル方法
date:   2015-06-09 17:00:00
lang:   ja
obsolute: true
category: docs
---

#### [```このドキュメントは古いものです。「ネイティブクライアントのインストール方法」をご覧ください。```](/docs/2015/06/21/ja-required_install.html)

FreeBSD環境でのネイティブクライアントのコンパイル方法について説明します。
作業はおおまかに以下の4つの項目にわかれています。

* pkgを利用した前提アプリケーションのインストール
* Socket.IO C++ Clientのコンパイル
* PROCESS WARPのコンパイル
* 設定ファイルの編集と疎通の確認

## 前提環境

* FreeBSD 10 amd64

## pkgを利用した前提アプリケーションのインストール

コンソールからpkgを利用して前提アプリケーションをインストールします。

    $ sudo pkg install cmake git libffi boost-libs

## Socket.IO C++ Clientのコンパイル

PROCESS WARPのコンパイルのためには既存パッケージの他にSocket.IO C++ Clientが必要になります。
[Socket.IO C++ Clientはgithubで公開されています。](https://github.com/socketio/socket.io-client-cpp)
2015/6/9現在パッケージ化されていないため、以下のとおり手動でコンパイルします。

    $ cd <作業ディレクトリ>
    $ git clone --recurse-submodules https://github.com/socketio/socket.io-client-cpp.git
    $ cd socket.io-client-cpp
    $ cmake .
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
	        "<conf/libfilter_freebsd.jsonへのフルパス>"
        ],
    
        "apps":[]
    }

編集が終わったら設定ファイルを指定して、ネイティブクライアントを起動します。


    $ core -c <設定ファイル>

ネイティブクライアントにはGUIがないためWEB版からコントロールする必要があります。
WEB版へログインし、[Try!に従い](/ja/try)サンプルアプリケーションを実行し、
ネイティブクライアントへのWarpを実行することで疎通の確認ができます。
