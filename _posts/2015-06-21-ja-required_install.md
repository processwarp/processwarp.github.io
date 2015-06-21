---
layout: post
title:  ネイティブクライアントのインストール方法
date:   2015-06-20 17:00:00
lang:   ja
category: docs
---

## アカウントの作成

ネイティブクライアントのインストール時に、PROCESS WARPのアカウントを入力します。webからアカウントを持っていない場合は事前に作成してください。

[web版](https://prev.processwarp.org/)のRegisterからアカウントが登録できます。

## ネイティブクライアントのコンパイル

PROCESS WARPのネイティブクライアントは1行でインストールすることができます。
それぞれの環境でターミナルを起動して、作業ディレクトリにて以下のコマンドをコピー、ペーストして実行してください。

インストールの最後に登録したアカウントとデバイス名の入力をします。

### FreeBSD

前提アプリケーションのインストールのため、途中sudoのパスワードが要求されます。

    $ bash -c "$(curl -fsSL https://raw.githubusercontent.com/processwarp/processwarp/master/install/freebsd.sh)"

### Ubuntu

前提アプリケーションのインストールのため、途中sudoのパスワードが要求されます。

    $ bash -c "$(curl -fsSL https://raw.githubusercontent.com/processwarp/processwarp/master/install/ubuntu.sh)"

### MacOSX

Homebrewを利用しています。

    $ sh -c "$(curl -fsSL https://raw.githubusercontent.com/processwarp/processwarp/master/install/darwin.sh)"

## 疎通の確認

作業ディレクトリに実行可能ファイルcoreと、設定ファイルconf.jsonが作成されます。
設定ファイルを指定して、ネイティブクライアントを起動します。

    $ core -c conf.json

ネイティブクライアントにはGUIがないためWEB版からコントロールする必要があります。
WEB版へログインし、[Try!に従い](/ja/try)サンプルアプリケーションを実行し、
ネイティブクライアントへのWarpを実行することで疎通の確認ができます。
