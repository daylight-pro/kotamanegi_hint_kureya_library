# ICPC_notebook

- CSS 組版で、ファイルを置くだけで PDF が簡単に作れる、ICPC 用ライブラリのすごいテンプレート
- かつ、みんなでつくる最強の ICPC 用ライブラリ (予定)

## 内容を変更するには

1. [src/\*/\*](src/) の中身を変更する
2. [build/build.js](build/build.js) の設定項目を変更する
3. commit & push

## 手元で動かすには

### 事前にインストールするもの

- node.js (v18 以上)
- npm
    - `brew install node` / <https://learn.microsoft.com/ja-jp/windows/dev-environment/javascript/nodejs-on-wsl>
- clang-format
    - `brew install clang-format` / `sudo apt install clang-format`
- vivliostyle
    - `npm install -g @vivliostyle/cli`
- その他依存関係
    - `npm install`
- (使うなら) oj-verify
    - `pip3 install online-judge-verify-helper`

### PDF を生成する

1. `make build`

### oj-verify で verify

1. `make verify`

### oj-verify ページを生成

1. `make serve`

