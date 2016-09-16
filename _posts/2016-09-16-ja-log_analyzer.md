---
layout: post
title:  Log analyzerを公開しました
date:   2016-09-16 00:00:00
lang:   ja
category: logs
---

PROCESS WARPは分散処理のシステムのように、複数のノードが強調して動くシステムです。
そのため、PROCESS WARPの開発(おもにデバッグ)のためには複数のノードのログ出力を比較する必要があります。
簡単なバグであれば、単純な目視で対応可能でしたが、最近は複雑なバグ対応が多いため、ログ表示用のツールを作成しました。

![スクリーンショット]({{site.baseurl}}/ja/img/20160916a.png)

## 特徴

* 検索文字列の前後n件のログを絞って検索する
* パケット送受信のログから、ログを時系列に沿って並べる
* [Githubへのリンク](https://github.com/processwarp/log-analyzer)
