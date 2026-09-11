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

## 🛠️ 開発ツールのインストール

お使いのOSの手順に従い、**セッション1の開始前**に以下のツールをインストールしてください。

### 1. コンパイラとRaylibグラフィック環境のセットアップ

#### 🪟 Windows (MSYS2 + MinGW-w64)

1. [msys2.org](https://www.msys2.org/) からインストーラーをダウンロードして実行します（デフォルトのパス `C:\msys64` の使用を推奨）。
2. スタートメニューから **MSYS2 UCRT64** を開き、GCC、Make、Raylibをインストールします:

```bash
pacman -Syu
pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-make mingw-w64-ucrt-x86_64-raylib

```

3. GCCをシステムの環境変数（PATH）に追加します:

- `Win + R` を押し、`sysdm.cpl` と入力して **Enter** を押します。
- **「詳細設定」** タブ > **「環境変数」** を開き、システム環境変数の `Path` をダブルクリックします。
- **「新規」** をクリックして `C:\msys64\ucrt64\bin` を追加し、**OK** をクリックします。
- 開いているターミナルをすべて再起動し、`gcc --version` で動作確認を行います。

#### 🍎 macOS (Homebrew + Apple Clang)

1. ターミナルで Xcode Command Line Tools をインストールします:

```bash
xcode-select --install

```

2. Homebrew をインストールします（未インストールのブラウザ/環境の場合）:

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

```

3. Raylib をインストールします:

```bash
brew install raylib

```

#### 🐧 Linux (Ubuntu / Debian)

GCC、Make、Git、および開発用ヘッダー付きの Raylib をインストールします:

```bash
sudo apt update
sudo apt install -y build-essential git libraylib-dev libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev

```

---

### 2. 共通ツールのセットアップ

- **Git CLI:** [git-scm.com](https://git-scm.com/) からダウンロードしてインストールします。
- **Visual Studio Code:** [code.visualstudio.com](https://code.visualstudio.com/) からダウンロードします。
- 推奨拡張機能: **C/C++** (Microsoft製) および **C/C++ Compile Run** または **CMake Tools**

- **Claude Desktop / AI アシスタント:** [claude.ai/download](https://claude.ai/download) からダウンロードするか、指定されたプラットフォームにアクセスします。

---

## 🚀 ステップ 3: リポジトリのクローンとセットアップの検証

ツールのインストールが完了したら、このリポジトリをクローンし、含まれている `test_raylib.c` ファイルを使用してコンパイル環境をテストします。

1. ターミナルまたはコマンドプロンプトを開き、作業用フォルダに移動します:

```bash
cd path/to/your/projects-folder

```

2. 本リポジトリをクローンします:

```bash
git clone https://github.com/your-organization/mario-forensic-lab.git

```

3. クローンしたリポジトリのディレクトリに移動します:

```bash
cd mario-forensic-lab

```

### 🧪 動作確認（環境検証）

お使いのOSに応じたコマンドを実行し、同梱されている `test_raylib.c` ファイルをコンパイルして実行します:

- **Windows (コマンドプロンプト / PowerShell):**

```cmd
gcc test_raylib.c -o test_raylib.exe -lraylib -lopengl32 -lgdi32 -lwinmm
.\test_raylib.exe

```

- **macOS (ターミナル):**

```bash
gcc test_raylib.c -o test_raylib -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
./test_raylib

```

- **Linux (ターミナル):**

```bash
gcc test_raylib.c -o test_raylib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./test_raylib

```

赤い四角形と成功メッセージが表示されたグラフィックウィンドウがポップアップすれば、セッション1の準備は完了です！

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

Chào mừng bạn đến với **Mario Forensic Lab**! Trong workshop này, bạn sẽ không chỉ học cách viết code, bạn sẽ học cách trở thành một **Software Architect** (Kiến trúc sư Phần mềm).

Thay vì xây dựng đồ họa ngay từ ngày đầu tiên hoặc gõ từng dòng code, chúng ta sử dụng phương pháp tiếp cận **Logic-First & Code Forensics** (Ưu tiên Logic & Phân tích/Điều tra Mã nguồn). Bạn sẽ thiết kế cơ chế trò chơi, hướng dẫn Generative AI xây dựng cơ chế hoạt động cơ bản, và sau đó thực hiện dịch ngược để hiểu và giải thích cách thức hoạt động của logic ngôn ngữ C bên dưới. Khi logic đã ổn trong giao diện dòng lệnh, bạn sẽ tạo giao diện cho nó bằng một giao diện đồ họa sử dụng thư viện **Raylib**.

---

## 🎮 Final Game Preview

Dưới đây là bản xem trước của ứng dụng hoàn chỉnh mà bạn sẽ thiết kế, xác minh logic và tạo giao diện bằng Raylib trong workshop:

![Mario Game](https://media.giphy.com/media/p0KEKXBzvuwtv8JYVb/giphy.gif)

---

## 🧠 What You Will Learn (Những gì bạn sẽ học)

Thông qua workshop thực hành này, bạn sẽ kết nối kiến thức lý thuyết từ các khóa học đại học trực tiếp vào (kỹ thuật phần mềm thực tế:

- **Structural C Programming (Lập trình C cấu trúc):** Thành thạo `structs` (cấu trúc) để quản lý dữ liệu entity (thực thể), mảng 2 chiều cho ma trận không gian thế giới, vòng lặp và kiến trúc mã nguồn theo mô-đun.
- **Applied Mathematics & Physics (Toán học & Vật lý ứng dụng):** Chuyển đổi hình học tọa độ, công thức khoảng cách Euclid hay Manhattan, và boolean logic gates (cổng logic đúng/sai) thành phát hiện va chạm theo thời gian thực và tầm nhìn của NPC (nhân vật máy).
- **Finite State Machines (FSM - Máy trạng thái hữu hạn):** Thiết kế các mô hình hành vi AI (ví dụ như trạng thái tuần tra và truy đuổi của Bowser).
- **AI Collaboration & Code Forensics (Cộng tác với AI & Điều tra Mã nguồn):** Học kỹ thuật đặt câu lệnh để hướng dẫn AI hoạt động như một lập trình viên đồng hành, và phát triển các kỹ năng audit (kiểm tra) cần thiết để đọc, trace (theo dõi luồng chạy) và refactor (tái cấu trúc/làm sạch) mã nguồn có sẵn.
- **Digital Craftsmanship (Nghệ nhân kỹ thuật số):** Trải nghiệm niềm vui khi xây dựng một ứng dụng nguyên bản, đầy đủ chức năng từ thiết kế đặc tả thiết kế cho đến sản phẩm cuối cùng.

---

## 🛠️ Development Tools Installation (Cài đặt công cụ phát triển)

Vui lòng cài đặt các công cụ dưới đây **trước Buổi 1 (Session 1)** theo hướng dẫn dành cho hệ điều hành của bạn.

### 1. Thiết lập trình biên dịch (Compiler) & Thư viện đồ họa Raylib

#### 🪟 Windows (MSYS2 + MinGW-w64)

1. Tải về và chạy bộ cài đặt từ [msys2.org](https://www.msys2.org/) (sử dụng đường dẫn mặc định `C:\msys64`).
2. Mở **MSYS2 UCRT64** từ Start Menu và cài đặt GCC, Make, cùng Raylib:

```bash
pacman -Syu
pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-make mingw-w64-ucrt-x86_64-raylib

```

3. Thêm GCC vào biến môi trường PATH hệ thống (system PATH):

- Nhấn `Win + R`, nhập `sysdm.cpl`, rồi nhấn **Enter**.
- Vào mục **Advanced (Nâng cao)** > **Environment Variables (Biến môi trường)** > nhấp đúp vào `Path` bên dưới mục System variables (Biến hệ thống).
- Nhấp vào **New**, thêm `C:\msys64\ucrt64\bin`, và nhấn **OK**.
- Khởi động lại các cửa sổ terminal đang mở và kiểm tra lại bằng lệnh: `gcc --version`

#### 🍎 macOS (Homebrew + Apple Clang)

1. Cài đặt Xcode Command Line Tools trong Terminal:

```bash
xcode-select --install

```

2. Cài đặt Homebrew (nếu chưa cài đặt):

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

```

3. Cài đặt Raylib:

```bash
brew install raylib

```

#### 🐧 Linux (Ubuntu / Debian)

Cài đặt GCC, Make, Git và Raylib kèm theo các header file phát triển (development headers):

```bash
sudo apt update
sudo apt install -y build-essential git libraylib-dev libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev

```

---

### 2. Thiết lập các công cụ chung

- **Git CLI:** Tải về và cài đặt từ [git-scm.com](https://git-scm.com/).
- **Visual Studio Code:** Tải về từ [code.visualstudio.com](https://code.visualstudio.com/).
  - Extension (tiện ích mở rộng) đề xuất: **C/C++** (do Microsoft phát triển) và **C/C++ Compile Run** hoặc **CMake Tools**.
- **Claude Desktop / AI Assistant (Trợ lý AI):** Tải về từ [claude.ai/download](https://claude.ai/download) hoặc truy cập nền tảng được phân công.

---

## 🚀 Bước 3: Clone Repository & Xác nhận thiết lập

Sau khi đã cài đặt xong các công cụ, hãy clone repository này và kiểm tra môi trường biên dịch của bạn bằng tệp `test_raylib.c` đi kèm.

1. Mở Terminal hoặc Command Prompt và di chuyển đến thư mục làm việc (workspace):

```bash
cd path/to/your/projects-folder

```

2. Clone kho lưu trữ này:

```bash
git clone https://github.com/geu-pit/mario-forensic-workshop.git

```

3. Truy cập vào thư mục của repository:

```bash
cd mario-forensic-workshop

```

### 🧪 Environment Verification (Kiểm tra môi trường)

Biên dịch (compile) và chạy tệp `test_raylib.c` đi kèm bằng lệnh tương ứng với hệ điều hành của bạn:

- **Windows (Command Prompt / PowerShell):**

```cmd
gcc test_raylib.c -o test_raylib.exe -lraylib -lopengl32 -lgdi32 -lwinmm
.\test_raylib.exe

```

- **macOS (Terminal):**

```bash
gcc test_raylib.c -o test_raylib -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
./test_raylib

```

- **Linux (Terminal):**

```bash
gcc test_raylib.c -o test_raylib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./test_raylib

```

Nếu một cửa sổ đồ họa hiện lên hiển thị một hình vuông màu đỏ cùng thông báo thành công, môi trường của bạn đã sẵn sàng 100% cho Buổi 1!

---

## 📅 Workshop Overview at a Glance (Tổng quan Nhanh về Khóa học)

| Session (Buổi) | Focus Area (Nội dung Trọng tâm)               | Core Objective (Mục tiêu Cốt lõi)                                                                                                                                  |
| -------------- | --------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| **Session 1**  | Matrix & Hero (Ma trận & Nhân vật chính)      | Xây dựng grid (lưới) C 10x10, di chuyển người chơi bằng phím WASD, và boundary logic (logic giới hạn biên).                                                        |
| **Session 2**  | Predator & Key (Kẻ săn mồi & Chìa khóa)       | Implement (triển khai) logic truy đuổi theo FSM của Goomba và mechanics (cơ chế) mở khóa Cổng-Chìa khóa.                                                           |
| **Session 3**  | Raylib UI Integration (Tích hợp UI Raylib)    | Map (Ánh xạ/Kết nối) backend console logic (logic xử lý chìm trên dòng lệnh) sang một cửa sổ đồ họa Raylib.                                                        |
| **Session 4**  | Independent Architect (Kiến trúc sư Độc lập)  | Thiết kế và assemble (lắp ráp) một ứng dụng UI 10x10 nguyên bản của riêng bạn sử dụng AI.                                                                          |
| **Session 5**  | Pro-Dev Finish (Hoàn thiện cấp Chuyên nghiệp) | Refactor code (tái cấu trúc mã), thêm sound FX (hiệu ứng âm thanh), chạy "Bug Bounties" (săn lỗi nhận thưởng) cùng bạn bè, và showcase (trình diễn) dự án của bạn. |

---
