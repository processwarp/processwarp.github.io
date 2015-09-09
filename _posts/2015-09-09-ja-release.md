---
layout: post
title:  LLVM Bitcodeのロード、マルチスレッドプログラムに対応しました。
date:   2015-09-09 15:00:00
lang:   ja
category: news
---

PROCESS WARPを更新しました。

### LLVM Bitcodeフォーマットのプログラムがロード可能になりました。

Cプログラムを以下のようにコンパイルします(clang 3.3を利用します)。

{% highlight sh %}
$ C_INCLUDE_PATH=<PROCESS WARP install path>/include/libc clang -arch x86_64 -O2 -emit-llvm -c -fno-vectorize <path to source code>
{% endhighlight %}

コンパイルしたプログラムはwebフロントエンドからロード、実行が可能です。

### マルチスレッドプログラムに対応しました。

新しくサポートするAPIは以下のとおりです。

* pthread_create (attrは無視されます)
* pthread_join


