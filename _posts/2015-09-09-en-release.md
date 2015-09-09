---
layout: post
title:  You can load LLVM Bitcode formated program and execute multi-thread programe.
date:   2015-09-09 15:00:00
lang:   en
category: news
---

I updated PROCESS WARP.

### You can load LLVM Bitcode formated prograem.

You can compile C program by the following way with clang 3.3.

{% highlight sh %}
$ C_INCLUDE_PATH=<PROCESS WARP install path>/include/libc clang -arch x86_64 -O2 -emit-llvm -c -fno-vectorize <path to source code>
{% endhighlight %}

And it can load and execute by web-base frontend.

### You can execute multi-thread programe.

New supported apis are as follows.

* pthread_create (attr is ignored)
* pthread_join


