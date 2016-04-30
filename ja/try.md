---
layout: page
title: PROCESS WARPを試してみる。
permalink: /ja/try/
lang:   ja
---

## アプリケーションの移動機能を試してみる

PROCESS WARPは以下の手順で試すことができます。

* アカウントを作成する
* プログラムをインストールする
* サンプルアプリケーションを起動する
* アプリケーションを他のデバイスに移動する
* プログラムを終了する

### アカウントを作成する

まず、アカウントを作成します。
メニューにあるSignupからアカウント作成画面を開きます。
![Select sign-up from menu.](/ja/img/try/ss01.png){: .ss}

必要事項を入力し、「アカウントを作成する」を選択すると、アカウントの作成が完了します。
![Fill the form.](/ja/img/try/ss02.png){: .ss}

### プログラムをインストールする

#### MacOS X, Ubuntu Linux, Linux Mintの場合

ターミナルから以下のコマンドを入力し、インストーラーを起動します。
途中、依存するプログラムのインストールのため、パスワードの入力が求められる場合があります。

```sh
$ cd <PROCESS WARP working dir>
$ git clone https://github.com/processwarp/processwarp.git
$ script/build.sh
```

#### Androidの場合

***[こちらのリンク](https://prev.processwarp.org/processwarp.apk)***から、Android用APKファイルをダウンロードします。
サードパーティのアプリケーションのインストールを許可した状態で、ファイルを選択し、画面指示に従ってインストールします。

### サンプルアプリケーションを起動する

※アプリケーションはPCからのみ、起動できます。

***[こちらのリンク](/sample/try.ll)***からサンプルアプリケーションをダウンロードしておきます。
サンプルアプリケーションのソースコードは***[こちらのCプログラム](/sample/try.c)***です。
ターミナルから以下のコマンドを入力し、PROCESS WARPを起動します。

```sh
$ <PROCESS WARP working dir>/script/run_gui.sh
```

アカウントの入力が求められるので、先ほど作成したアカウント情報を入力します。

![Input the form to connect.](/ja/img/try/ss03.png){: .ss}

以下のボタンを選択することで、アプリケーションを選ぶことができます。
ダイアログが開くので、ダウンロードしたサンプルアプリケーションを選択します。

![Select a application.](/ja/img/try/ss04.png){: .ss}

ロボットが表示さます。簡単な計算を行い、結果を教えてくれます。

![The appilcation is runnning.](/ja/img/try/ss05.png){: .ss}

### アプリケーションを他のデバイスに移動する

他のデバイスでもPROCESS WARPを起動します。
以下のボタンを選択すると、操作しているデバイスに動いているアプリケーションが移動してきます。

![PROCESS WARP.](/ja/img/try/ss06.png){: .ss}

### プログラムを終了する

現在、PROCESS WARPの終了機能は未完成です。

MacOS XとLinuxでは、ターミナルをアクティブにした状態でControl+Cの入力をしてプログラムが停止できます。

Androidでは、設定画面のアプリからPROCESS WARPを選択し、強制終了してください。

![Kill PROCESS WARP.](/ja/img/try/ss07.png){: .ss}
