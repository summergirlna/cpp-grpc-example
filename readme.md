## 雑多なめも

### コマンドの類

- `cmake -S . -B build`
  - ビルド用ファイル生成
- `cmake --build build`
  - ビルド実行
- 毎回パスを通す
  - export PATH=/Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin:${PATH}

### 文法の類

- 値渡し
  - コピーして受け取る
  - 呼び出し元に影響しない
  - コピーコストがある
- 参照渡し
  - コピーしない
  - 呼び出し元に影響する
- const参照渡し
  - コピーしない
  - 呼び出し元に影響しない
