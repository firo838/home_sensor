# home_sensor
家庭で使用することを想定したIoTセンサー。

## Arduino
Arduino LLCによって開発されるAVRマイコン及び入出力ポートを持つArduinoシリーズ。

Arduino IDEを使用してC言語風のプログラミング言語を使用してマイコンを簡単に開発することができる。

### Arduino Scratch code.
使用したソースコード。

Arduino IDEを使用してArduino本体に転送する。

home_sensor/scratch/home_sensor.ino/multi_sensor/multi_sensor.ino

## ELK Stack
ELK（ELK Stack）とは，Elastic社が提供する「データ受信・整形」，「データ保存・解析・検索」，「データ可視化」を実現するオープンソースのツール群です。

これらの構築にUbuntu16.04x64でサーバを構築しています。

https://www.elastic.co/jp/products
### Losgatsh
データ受信・整形を行うツール。TCP通信やファイルからのデータを読み込み，任意の形式に整形してデータを出力する機能を持つ。

データを受信するLinuxサーバの以下のディレクトリに設定ファイルを配置する。

```
使用したConfig

/etc/logstash/conf.d/home_sensor.conf
```
### Elasticsearch
データを保存・検索・解析するためのデータベースエンジン。

初期設定を終えたElasticsearchサーバに対して，curlコマンドでMapping（DBスキーマ）を登録する。

```
使用したMapping

curl -XPUT SERVERADDR:9200/home_sensor --data @home_sensor.json

Githubのelasticsearchディレクトリにある「check_query.json」はElasticsearchに対して検索とする際に使用したテストクエリ。

curl -XGET "http://localhost:9200/home_sensor/_search" -data @check_query.json
```
### Kibana
データベースに保存されたデータをWebブラウザ上で可視化するためのツール。

"home_sensor1"をキーにして可視化のためのデータ検索を行う。

```
特に設定ファイルなし。
```

## docs
プロダクトのホームページのためのコンテンツ。

完成イメージを掲載。

https://firo838.github.io/home_sensor/

## docker
Dockerはコンテナ型仮想化のためのツール。

未実装。

## 最後に
これらのソースコードの改変・利用は個人の責任の下利用することができます。

プログラムの利用，デバイスの作成によって生じたいかなる事故などにおいても責任を取りません。
