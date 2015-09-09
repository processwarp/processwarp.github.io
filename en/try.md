---
layout: page
title:  How to try on web browser.
permalink: /en/try/
lang:   en
---

## Try out an application migrate function

We can try an application migrate function on PROCESS WARP in web page.
Please access to ***[https://prev.processwarp.org/](https://prev.processwarp.org/)*** and try it along the following description.You should prepare two computers or run two web browsers on single computer. Please reload after a moment when that dose not work.

### Get your account

At first you should get your account. You use the same account on many devices you having.
You should open dialog by select "Sign up" for getting your account.
![Select register.](/ja/img/try/ss01.png){: .ss}

You should check "Terms of service" befor get your account.
You input forms and select "Sign up", your account will be issued.
![Sign up.](/ja/img/try/ss02.png){: .ss}

### Login

In login page, You should input your account word in form and select "Login".And login on other web browser by the same account too.
![Login.](/ja/img/try/ss03.png){: .ss}

Please pick your using device.
If you want to bind new device, you should select "new device" and input "new device name".
Finally, you select "Bind".
![Bind.](/ja/img/try/ss04.png){: .ss}

### Launch sample application

Please select "Home" on side menu
and select "hello world" on icons.
After open dialog, you select device that bind a while ago and select "Load".
This application shows "Hello world" and number that is increased by one simply.When migrate application, you will notice that it is continuously.
Source code of sample applicaion is ***[this C file](/sample/hello.c)***.
![Load LLVM IR.](/ja/img/try/ss05.png){: .ss}
![Load LLVM IR.](/ja/img/try/ss06.png){: .ss}

### Migrate sample application to other device

Please select launched sample application by side menu.
You can open sub menu by selecting again it, and select "Warp" by sub menu.(You can migrate or stop your migration by any device)
![Show submenu.](/ja/img/try/ss07.png){: .ss}

You can select device to warp destination and "Warp", your application has warped.You can close source web browser in this status.
![Select Target.](/ja/img/try/ss08.png){: .ss}
![Result.](/ja/img/try/ss09.png){: .ss}

### Make application end

Please open sub menu as same as Migrate sample application.
After select "Exit", application will be end.
