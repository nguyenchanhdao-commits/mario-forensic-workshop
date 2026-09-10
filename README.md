# 🍄 Mario Forensic Lab: ロジックファーストのゲームデザイン

**Mario Forensic Lab**へようこそ！このワークショップでは、単にコードの書き方を学ぶだけでなく、**ソフトウェアアーキテクト**としての思考法を身につけます。

初日からグラフィックを構築したり、コードを1行ずつ写経したりするのではなく、「ロジックファースト & コードフォレンジック（コード解析）」のアプローチを採用します。紙の上でゲームメカニクスを設計し、生成AIにコア「エンジン」を構築させ、リバースエンジニアリングによってC言語のロジックがどう動作しているかを監査・理解・説明します。コンソール上でエンジンのロジックが検証できたら、**Raylib** ライブラリを使ってグラフィックUIを「スキン（被せ物）」として実装します。

---

## 🎮 完成ゲームのプレビュー

以下は、ワークショップの終わりまでに設計・ロジック検証・RaylibでのUI実装を行う最終アプリケーションのプレビューです：
![Mario Game](https://media.giphy.com/media/p0KEKXBzvuwtv8JYVb/giphy.gif)

---

## 🧠 習得できるスキル・知識

この実践的なワークショップを通じて、大学の講義で学んだ理論知識を実践的なソフトウェアエンジニアリングに直接結びつけます：

- **構造化C言語プログラミング:** エンティティデータ管理のための構造体（`struct`）、空間ワールド行列のための2次元配列、イテレータ、モジュール化されたコードアーキテクチャをマスターします。
- **応用数学 & 物理:** 座標幾何学、ユークリッド距離の公式（$a^2 + b^2 = c^2$）、ブール論理ゲートを、リアルタイムの当たり判定（コリジョン検出）やNPCの視界判定に落とし込みます。
- **有限状態機械（FSM）:** 決定論的なAIの行動モデル（クリボーの巡回や追跡状態など）を設計します。
- **AIコラボレーション & コードフォレンジック:** ペアプログラマーとしてAIを導くプロフェッショナルなプロンプトエンジニアリングを学び、既存コードを読み解き、トレースし、リファクタリングするためのコード監査スキルを養います。
- **デジタルにおける「ものづくり」:** 設計仕様の作成から最終納品まで、完全に動作するオリジナルのアプリケーションをゼロから構築する達成感を体験します。

---

## 🛠️ セットアップ手順（ステップバイステップ）

**セッション1が始まる前に**、ご使用のOSに合わせた手順に従って必要な開発環境をインストールしてください。

### 🪟 Windowsでのセットアップ（MSYS2 + MinGW-w64）

1. **MSYS2のインストール:** [msys2.org](https://www.msys2.org/) からインストーラーをダウンロードし、デフォルトのパス（`C:\msys64`）にインストールします。
2. **GCC、Make、Raylibのインストール:**
   スタートメニューから **MSYS2 UCRT64** を開いて以下を実行します:

```bash
pacman -Syu
pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-make mingw-w64-ucrt-x86_64-raylib

```

3. **GCCをWindowsの環境変数（PATH）に追加:**

- `Win + R` を押し、`sysdm.cpl` と入力して **Enter** を押します。
- **詳細設定** タブ > **環境変数** を開きます。
- **システム環境変数** の欄にある `Path` を選択して **編集** をクリックし、`C:\msys64\ucrt64\bin` を追加します。
- 設定を保存し、開いているコマンドプロンプト（`cmd`）をすべて再起動します。`gcc --version` と入力して正しく認識されるか確認してください。

4. **コンパイルコマンド:**

```cmd
gcc main.c -o game.exe -lraylib -lopengl32 -lgdi32 -lwinmm

```

### 🍎 macOSでのセットアップ（Homebrew + Apple Clang）

1. **Xcode Command Line Toolsのインストール:**
   ターミナルを開いて以下を実行します:

```bash
xcode-select --install

```

2. **Homebrewのインストール（未インストールの環境のみ）:**

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

```

3. **Raylibのインストール:**

```bash
brew install raylib

```

4. **コンパイルコマンド:**

```bash
gcc main.c -o game -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

```

### 🐧 Linuxでのセットアップ（Ubuntu / Debian）

1. **ビルドツールとRaylibのインストール:**
   ターミナルを開いて以下を実行します:

```bash
sudo apt update
sudo apt install -y build-essential git libraylib-dev libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev

```

2. **コンパイルコマンド:**

```bash
gcc main.c -o game -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

```

---

### 🧰 その他必要なツール

- **Git CLI:** [git-scm.com](https://git-scm.com/) からダウンロードしてインストール。
- **Visual Studio Code:** [code.visualstudio.com](https://code.visualstudio.com/) からダウンロード。
- 推奨拡張機能: **C/C++**（Microsoft製）、**C/C++ Compile Run** または **CMake Tools**。
- **Claude Desktop / AIアシスタント:** [claude.ai/download](https://claude.ai/download) からダウンロード、または指定されたプラットフォームにアクセス。

---

### 🧪 動作確認（`test_raylib.c`）

`test_raylib.c` というテスト用ファイルを作成し、コンパイルして環境構築が成功したか確認します：

```c
#include "raylib.h"

int main(void) {
    InitWindow(800, 450, "Mario Forensic Lab - Environment Test");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Raylib environment successfully installed!", 150, 200, 20, DARKGRAY);
            DrawRectangle(375, 250, 50, 50, RED);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

```

お使いのOSに対応した上記のコンパイルコマンドを実行してください。赤い四角形が表示されたウィンドウが立ち上がれば、環境構築は完了です！

---

## 🚀 はじめに：リポジトリのクローン手順

1. ターミナルまたはコマンドプロンプトを開き、作業用フォルダに移動します:

```bash
cd path/to/your/projects-folder

```

2. リポジトリをクローンします:

```bash
git clone https://github.com/your-organization/mario-forensic-lab.git

```

3. リポジトリのディレクトリに移動します:

```bash
cd mario-forensic-lab

```

---

## 📅 ワークショップの概要一覧

| セッション       | フォーカスエリア        | 主な目標                                                                                 |
| ---------------- | ----------------------- | ---------------------------------------------------------------------------------------- |
| **セッション 1** | マトリックス & ヒーロー | C言語での10x10グリッド生成、WASDでのプレイヤー移動、境界線判定ロジックを構築。           |
| **セッション 2** | プレデター & 鍵         | クリボーのFSM追跡ロジックと、鍵とゲートの解除メカニクスを実装。                          |
| **セッション 3** | Raylib UI統合           | バックエンドのコンソールロジックを、Raylibのグラフィックウィンドウにマッピング。         |
| **セッション 4** | 独立したアーキテクト    | AIを活用し、オリジナルの10x10 UIアプリケーションを設計・構築。                           |
| **セッション 5** | プロレベルの仕上げ      | コードのリファクタリング、効果音の追加、相互バグ報奨金（Bug Bounty）テスト、成果物発表。 |

---

# 🍄 Mario Forensic Lab: Logic-First Game Design (Thiết kế Game đặt Logic lên hàng đầu)

Chào mừng bạn đến với **Mario Forensic Lab**! Trong workshop (buổi thực hành) này, bạn sẽ không chỉ học cách viết code, bạn sẽ học cách trở thành một **Software Architect** (Kiến trúc sư Phần mềm).

Thay vì xây dựng đồ họa ngay từ ngày đầu tiên hoặc gõ từng dòng code, chúng ta sử dụng phương pháp tiếp cận **Logic-First & Code Forensics** (Ưu tiên Logic & Phân tích/Điều tra Mã nguồn). Bạn sẽ thiết kế cơ chế trò chơi, hướng dẫn Generative AI (Trí tuệ nhân tạo tạo sinh) xây dựng cơ chế hoạt động cơ bản, và sau đó thực hiện dịch ngược để đánh giá, hiểu và giải thích cách thức hoạt động của logic ngôn ngữ C bên dưới. Khi logic được kiểm duyệt trong giao diện dòng lệnh, bạn sẽ tạo giao diện cho nó bằng một giao diện đồ họa sử dụng thư viện **Raylib**.

---

## 🎮 Final Game Preview (Bản xem trước Game hoàn chỉnh)

Dưới đây là bản xem trước của ứng dụng hoàn chỉnh mà bạn sẽ thiết kế, xác minh logic và tạo giao diện bằng Raylib vào cuối workshop:
![Mario Game](https://media.giphy.com/media/p0KEKXBzvuwtv8JYVb/giphy.gif)

---

## 🧠 What You Will Learn (Những gì bạn sẽ học)

Thông qua workshop thực hành này, bạn sẽ kết nối kiến thức lý thuyết từ các khóa học đại học trực tiếp vào practical software engineering (kỹ thuật phần mềm thực tế):

- **Structural C Programming (Lập trình C cấu trúc):** Thành thạo `structs` (cấu trúc) để quản lý dữ liệu entity (thực thể), 2D arrays (mảng 2 chiều) cho ma trận không gian thế giới, iterators (con trỏ vòng lặp) và modular code architecture (kiến trúc mã nguồn theo mô-đun).
- **Applied Mathematics & Physics (Toán học & Vật lý ứng dụng):** Chuyển đổi hình học tọa độ, công thức khoảng cách Euclid ($a^2 + b^2 = c^2$), và boolean logic gates (cổng logic đúng/sai) thành real-time collision detection (phát hiện va chạm theo thời gian thực) và tầm nhìn của NPC (nhân vật máy).
- **Finite State Machines (FSM - Máy trạng thái hữu hạn):** Thiết kế deterministic AI behavior models (các mô hình hành vi AI mang tính quyết định) (ví dụ như trạng thái tuần tra và truy đuổi của Goomba).
- **AI Collaboration & Code Forensics (Cộng tác với AI & Điều tra Mã nguồn):** Học cách prompt engineering (kỹ thuật đặt câu lệnh) chuyên nghiệp để hướng dẫn AI hoạt động như một pair-programmer (lập trình viên đồng hành), và phát triển các kỹ năng audit (kiểm tra) cần thiết để đọc, trace (theo dõi luồng chạy) và refactor (tái cấu trúc/làm sạch) mã nguồn có sẵn.
- **Digital Craftsmanship (Nghệ nhân kỹ thuật số - _Monozukuri_ / ものづくり):** Trải nghiệm niềm tự hào khi xây dựng một ứng dụng nguyên bản, fully functional (đầy đủ chức năng) từ design specification (đặc tả thiết kế) cho đến final delivery (sản phẩm cuối cùng).

---

## 🛠️ Step-by-Step Installation Guide (Hướng dẫn Cài đặt Từng bước)

Hãy cài đặt development environment (môi trường phát triển) bắt buộc **trước Buổi 1**, làm theo chính xác các bước dành cho operating system (hệ điều hành) của bạn.

### 🪟 Cài đặt trên Windows (MSYS2 + MinGW-w64)

1. **Cài đặt MSYS2:** Tải xuống installer (trình cài đặt) từ [msys2.org](https://www.msys2.org/) và cài đặt nó bằng default path (đường dẫn mặc định) (`C:\msys64`).
2. **Cài đặt GCC, Make, và Raylib:**
   Mở **MSYS2 UCRT64** từ Start Menu của bạn và chạy lệnh sau:

```bash
pacman -Syu
pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-make mingw-w64-ucrt-x86_64-raylib


```

3. **Thêm GCC vào Windows PATH (Biến môi trường Windows):**

- Nhấn `Win + R`, gõ `sysdm.cpl`, và nhấn **Enter**.
- Điều hướng đến **Advanced** (Nâng cao) > **Environment Variables** (Biến môi trường).
- Dưới mục **System variables** (Biến hệ thống), chọn `Path`, nhấp **Edit** (Chỉnh sửa), và thêm `C:\msys64\ucrt64\bin`.
- Lưu và khởi động lại bất kỳ cửa sổ Command Prompt (`cmd` - Dòng lệnh) nào đang mở. Xác minh bằng cách gõ `gcc --version`.

4. **Compilation Command (Lệnh biên dịch):**

```cmd
gcc main.c -o game.exe -lraylib -lopengl32 -lgdi32 -lwinmm


```

### 🍎 Cài đặt trên macOS (Homebrew + Apple Clang)

1. **Cài đặt Xcode Command Line Tools (Công cụ Dòng lệnh Xcode):**
   Mở Terminal và chạy lệnh sau:

```bash
xcode-select --install


```

2. **Cài đặt Homebrew (nếu chưa cài đặt):**

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"


```

3. **Cài đặt Raylib:**

```bash
brew install raylib


```

4. **Compilation Command (Lệnh biên dịch):**

```bash
gcc main.c -o game -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo


```

### 🐧 Cài đặt trên Linux (Ubuntu / Debian)

1. **Cài đặt Build Tools (Công cụ xây dựng) & Raylib:**
   Mở Terminal và chạy lệnh sau:

```bash
sudo apt update
sudo apt install -y build-essential git libraylib-dev libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev


```

2. **Compilation Command (Lệnh biên dịch):**

```bash
gcc main.c -o game -lraylib -lGL -lm -lpthread -ldl -lrt -lX11


```

---

### 🧰 Additional Required Tools (Các Công cụ Bắt buộc Bổ sung)

- **Git CLI (Giao diện dòng lệnh Git):** Tải xuống và cài đặt từ [git-scm.com](https://git-scm.com/).
- **Visual Studio Code:** Tải xuống từ [code.visualstudio.com](https://code.visualstudio.com/).
- Extensions (Tiện ích mở rộng) được đề xuất: **C/C++** (bởi Microsoft) và **C/C++ Compile Run** hoặc **CMake Tools**.
- **Claude Desktop / AI Assistant (Trợ lý AI):** Tải xuống từ [claude.ai/download](https://claude.ai/download) hoặc truy cập vào nền tảng được chỉ định của bạn.

---

### 🧪 Environment Verification (Xác minh Môi trường) (`test_raylib.c`)

Tạo một test file (tệp kiểm tra) có tên `test_raylib.c` và compile (biên dịch) nó để xác minh quá trình cài đặt của bạn:

```c
#include "raylib.h"

int main(void) {
    InitWindow(800, 450, "Mario Forensic Lab - Environment Test");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Raylib environment successfully installed!", 150, 200, 20, DARKGRAY);
            DrawRectangle(375, 250, 50, 50, RED);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}


```

Compile (Biên dịch) bằng cách sử dụng lệnh cụ thể cho OS (hệ điều hành) của bạn được liệt kê ở trên. Nếu một graphical window (cửa sổ đồ họa) hiển thị một hình vuông màu đỏ mở ra, môi trường của bạn đã sẵn sàng 100%!

---

## 🚀 Getting Started: How to Clone the Repository (Bắt đầu: Cách Clone/Tải Mã nguồn về máy)

1. Mở Terminal hoặc Command Prompt (Dòng lệnh) và navigate (điều hướng) đến workspace folder (thư mục làm việc) của bạn:

```bash
cd path/to/your/projects-folder


```

2. Clone (Sao chép/Tải về) repository (kho lưu trữ) này:

```bash
git clone https://github.com/your-organization/mario-forensic-lab.git


```

3. Truy cập vào repository directory (thư mục kho lưu trữ):

```bash
cd mario-forensic-lab


```

---

## 📅 Workshop Overview at a Glance (Tổng quan Nhanh về Khóa học)

| Session (Buổi) | Focus Area (Lĩnh vực Trọng tâm)               | Core Objective (Mục tiêu Cốt lõi)                                                                                                                                  |
| -------------- | --------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| **Session 1**  | Matrix & Hero (Ma trận & Nhân vật chính)      | Xây dựng grid (lưới) C 10x10, di chuyển người chơi bằng phím WASD, và boundary logic (logic giới hạn biên).                                                        |
| **Session 2**  | Predator & Key (Kẻ săn mồi & Chìa khóa)       | Implement (triển khai) logic truy đuổi theo FSM của Goomba và mechanics (cơ chế) mở khóa Cổng-Chìa khóa.                                                           |
| **Session 3**  | Raylib UI Integration (Tích hợp UI Raylib)    | Map (Ánh xạ/Kết nối) backend console logic (logic xử lý chìm trên dòng lệnh) sang một cửa sổ đồ họa Raylib.                                                        |
| **Session 4**  | Independent Architect (Kiến trúc sư Độc lập)  | Thiết kế và assemble (lắp ráp) một ứng dụng UI 10x10 nguyên bản của riêng bạn sử dụng AI.                                                                          |
| **Session 5**  | Pro-Dev Finish (Hoàn thiện cấp Chuyên nghiệp) | Refactor code (tái cấu trúc mã), thêm sound FX (hiệu ứng âm thanh), chạy "Bug Bounties" (săn lỗi nhận thưởng) cùng bạn bè, và showcase (trình diễn) dự án của bạn. |

---
