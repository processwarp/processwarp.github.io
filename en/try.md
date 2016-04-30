---
layout: page
title:  How to try PROCESS WARP.
permalink: /en/try/
lang:   en
---

## Try out an application migrate function

We can try an application migrate function by below process.

* Get your account
* Install PROCESS WARP
* Launch a sample application
* Migrate the application to other device
* Quit PROCESS WARP

### Get your account

At first you should get your account.
You should open the web page by select "Signup" on this page.
![Select sign-up from menu.](/en/img/try/ss01.png){: .ss}

You input forms and select "Sign up", your account will be issued.
![Fill the form.](/en/img/try/ss02.png){: .ss}

### Install PROCESS WARP

#### Installing on MacOS X, Ubuntu Linux, Linux Mint.

Launch the installer by inputing below commands on your terminal.
Installer require your OS's password to install requiring programs if needed.

```sh
$ cd <PROCESS WARP working dir>
$ git clone https://github.com/processwarp/processwarp.git
$ script/build.sh
```

#### Installing on Android.

Download the package file from ***[this link](https://prev.processwarp.org/processwarp.apk)*** by browser on your android and install.

### Launch a sample application

Download the sample application from ***[this link](/sample/try.ll)***.
Source code of the sample applicaion is ***[this C file](/sample/hello.c)***.
Launch PROCESS WARP by inputing below command on your terminal.

```sh
$ <PROCESS WARP working dir>/script/run_gui.sh
```

Please input your account and select "connect" button.

![Input the form to connect.](/ja/img/try/ss03.png){: .ss}

You can select the sample application by selecting below button and opening a dialog.

![Select a application.](/ja/img/try/ss04.png){: .ss}

The sample application drow a robot. And he do some simple calculation and tell calculated results.

![The appilcation is runnning.](/ja/img/try/ss05.png){: .ss}

### Migrate the application to other device

Please launch PROCESS WARP on other device.
The application launched on other device should migrate to using device by touching below button.

![PROCESS WARP.](/ja/img/try/ss06.png){: .ss}

### Quit PROCESS WARP

You can halt PROCESS WARP on MacOS X and Linux by inputing Control + C at the terminal.

On android, force termination by settings.

![Kill PROCESS WARP.](/en/img/try/ss07.png){: .ss}
