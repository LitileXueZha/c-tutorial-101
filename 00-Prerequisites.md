# 前提条件

工欲善其事，必先利其器。配置完善的 IDE 以及掌握调试技巧，几乎是工程师的必备。

学习一门编程语言的基础，大部分人一般都是背熟它的语法，和一些简单的命令行用法，而往往忽视环境的重要性。

## IDE 集成开发环境

编程语言都需要一个运行环境，因此搭建好运行环境是基础的第一步。C 语言只需要编译后便可以运行了，因此不需要额外的操作。

> 很多高级编程语言大都要安装额外的软件才能运行，比如 Java 要下载的 JRE，PHP 需要的 Zend 解释器，运行 JavaScript 的 Chrome 浏览器则内置了 V8 引擎。

C 语言需要一个编译器，当下比较通用的是 [gcc](https://gcc.gnu.org/) 和 clang。

GCC 较为简单，适合入门。由于它是一个类 Unix 系统的编译器，在 Windows 上需要通过 [MSYS2](https://www.msys2.org/) 来安装，mac/linux 上只需要安装包即可。

```shell
$ gcc --version
gcc.exe (Rev1, Built by MSYS2 project) 12.2.0
...
$ # 验证安装
```

接着选择一个编辑器，是“利其器”的第一步，使得编写 C 语言事半功倍。

> 编辑器视平台各异，推荐首选适用平台的。例如，Windows 桌面开发的 Visual Studio，苹果系列开发的 Xcode，Java 开发的 Eclipse，Web 开发可选新近崛起的 VS Code。

纯文本编辑器不可取，缺少太多的功能，诸如代码提示、智能纠错补全、批量替换、查找引用和定义等等等。有时候看到网上所谓的“大神”记事本敲代码，一笑了之，真正地参与大型项目，动辄几十万行代码上千文件，即便是最资深的工程师也需要现代编辑器协助。

对于使用 VS Code 的同学而言，可以参考 [GCC on Windows](https://code.visualstudio.com/docs/cpp/config-mingw) 配置好环境。

## Debug 调试技巧

“利其器”的第二步，掌握基本的调试技巧。很多时候，编写的代码运行后不符合预期结果，但翻阅源码毫无头绪，这就需要进行 debug 了，观察程序执行的每一步状态以定位问题。

调试并不是什么高深的操作，其实就是熟练地使用 debugger 而已，一开始可能会觉得很陌生，但熟能生巧，不会就多用几遍就对了。一般来说，运行引擎或编译器都会自带一个 debugger，进行调试就是和 debugger 交互。

Debugger 分为命令行式和 GUI 界面。命令行式的 debugger 只需了解一下即可，平时调试使用最多的还是现代 IDE 提供的 GUI 界面。

+ 以最便捷的在浏览器里运行的 JavaScript 举例，<kbd>F12</kbd> 开发者工具里提供了一个调试面板，js 引擎在执行代码时遇到断点时会暂停，届时我们就可使用此 GUI 面板进行调试。

+ 对于 Node.js 而言，调试有两种方式：一种是 Node.js 自带的简易命令行式的 debugger，一种是基于 V8 引擎可用 devtools 的 GUI 界面。

  通过 `node inspect xxx.js` 可启用自带的简易 debugger（不推荐）。

  通过 `node --inspect xxx.js` 可启用 V8 集成的 inspector，接着在 Chrome 的 devtools 界面调试。同时亦可使用 node `inspector` 模块，eg: `inspector.post("Profiler.start")`，具体可查看 [Chrome DevTools Protocol](https://chromedevtools.github.io/devtools-protocol/)。

+ 使用 VS Code 的话，它集成的调试面板是我们最常用的，直接在编辑器里对源文件调试。*参考官网指南配置*

C 语言编译器 gcc 也附带了一个 debugger GDB，通过命令行参数 `--debug` 或简写 `-g` 编译后用 `gdb a.exe` 运行，就可以用交互式的命令进行调试。但这种方式较为复杂且不够直观，还是建议利用现代编辑器集成的 GUI 调试面板。

调试最重要的两个概念是 Breakpoint 断点和 Step 操作。

**打断点**，就是在源代码里写 debugger 关键字或点击文件行号，接着以调试模式运行程序。断点通常分为几种：

+ 普通断点。遇到时暂停执行
+ 条件断点。遇到时且条件为 `true`才暂停
+ 日志断点。遇到时打印日志，不会暂停

Step 操作就是指明该如何继续执行下一步，GUI 界面一般会提供一整排按钮，对应了一系列 Step 操作。
