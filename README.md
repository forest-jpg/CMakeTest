# CMakeTest

このワークスペースは、**CMake の使い方を学習するためのサンプルプロジェクト**です。  
C++アプリとライブラリを分離し、依存ライブラリ管理・ビルド設定・ターゲットリンクの流れを実践できます。

---

## 学習目的

- `add_library` / `add_executable` の基本
- `target_include_directories` / `target_link_libraries` の使い方
- `FetchContent` による依存ライブラリ取得
- Git submodule の組み込み
- CMake での構成分割（`app/`, `src/`, `external/`）

---

## プロジェクト構成（要点）

- ルート設定: `CMakeLists.txt`
- アプリ: `app/main.cpp`
- ライブラリ: `src/my_lib/`（`src/my_lib/CMakeLists.txt`）
- 外部依存:
  - FetchContent: `fmt`, `spdlog`, `cxxopts`, `Catch2`
  - submodule: `external/json`（`nlohmann/json`）
- 補助:
  - `CMakePresets.json`
  - `makefile`（依存グラフ生成など）

---

## 依存関係の学習ポイント

ルート `CMakeLists.txt` では `FetchContent` を使って依存を取得し、  
ライブラリ側 `src/my_lib/CMakeLists.txt` で `target_link_libraries` により次をリンクしています。

- `nlohmann_json::nlohmann_json`
- `fmt::fmt`
- `spdlog::spdlog`
- `cxxopts::cxxopts`

この構成により、**モダンCMakeの「ターゲットベース」設計**を学べます。

---

## 環境構築（Windows）

このプロジェクトは Windows + MinGW を前提にしています（`mingw-debug` プリセット）。

### 1) 必要ツール

- `CMake`（3.25 以上推奨）
- `Git`
- `MinGW-w64`（`g++`, `gcc`, `mingw32-make`）
- `make`（`MSYS2` 環境で`MSYS`makeをインストール）
- （任意）`Graphviz`（依存グラフ可視化用）

### 2) PATH 設定

少なくとも以下のコマンドがターミナルで実行できるように PATH を設定します。

- `cmake --version`
- `git --version`
- `g++ --version`
- `make --version`

> `make` はUnixコマンドを使用する想定なので、MinGWのものではダメです。MSYS2の `MSYS`make をインストールして PATH に追加してください。（例：C:\msys64\usr\bin\make.exe）

### 3) VS Code 拡張（推奨）

- `CMake Tools`
- `C/C++`

### 4) 初期セットアップ手順

```sh
make --prepare
cmake --preset mingw-debug
cmake --build build/mingw-debug
```

- `make --prepare` でbuildフォルダが生成できるか確認します。
- `cmake --preset mingw-debug` で MinGW 向けの構成を生成します。

---

## ビルド方法

### 1) 標準的な CMake 手順

```sh
make --prepare
cmake --preset mingw-debug
cd build/mingw-debug
cmake --build .
```

- `make --prepare` は `makefile` の `prepare` ターゲットを実行し、依存グラフの生成やサブモジュールの初期化を行います。
- `cmake --preset` でビルド構成を選択します（例: `mingw-debug`）。
- `cmake --build` で実際のビルドを行います。
- ビルドおよび実行は画面下のボタンを押すだけでも実行できます。

### 2) 実行

`COMPILE_EXECUTABLE` が `ON` の場合、`app` がビルド対象になります。  
生成物名はルート `CMakeLists.txt` の `EXECUTABLE_NAME` 設定に従います。

### 3) オプション切り替え例

```sh
cmake --preset mingw-debug -DCOMPILE_EXECUTABLE=OFF
cd build/mingw-debug
cmake --build .
```

- コマンドパレットで `CMake: Edit Cache (UI)` を選択しても同様の操作が可能です。

### 4) 依存グラフの生成

```sh
make dependency
```

- `makefile` の `dependency` ターゲットを実行すると、依存グラフが `dependency.dot` として生成されます。
- 生成された `dependency.dot` を Graphviz などのツールで可視化できます。
- 依存関係の全体像を把握するのに役立ちます。

---

## 学習の進め方（推奨）

1. まずルートの [CMakeLists.txt](CMakeLists.txt) を読む  
2. 次に [src/CMakeLists.txt](src/CMakeLists.txt) と [src/my_lib/CMakeLists.txt](src/my_lib/CMakeLists.txt) を読む  
3. [app/main.cpp](app/main.cpp) で実際の利用コードを確認  
4. 依存グラフを [makefile](makefile) の `dependency` ターゲットで可視化して理解を固める

---

## Git submodule/FetchContent の学習ポイント

- `FetchContent` は外部プロジェクトがGitリポジトリでかつCMakeプロジェクトであれば、ビルド時に自動で取得・ビルドできます。
- Git submodule は外部プロジェクトがCMakeプロジェクトでないときに活用を検討します。

## メモ

- `external/json` はサブモジュールとしても配置されています。
- 学習用として、同じ依存を「FetchContent」と「submodule」の両方で扱う構成を読むと理解が深まります。
- 実運用時は依存取得方式を一つに統一するのが一般的です。

---

## 参考ファイル

- [CMakeLists.txt](CMakeLists.txt)
- [CMakePresets.json](CMakePresets.json)
- [makefile](makefile)
- [src/CMakeLists.txt](src/CMakeLists.txt)
- [src/my_lib/CMakeLists.txt](src/my_lib/CMakeLists.txt)
- [app/main.cpp](app/main.cpp)
- [external/json](external/json)