# L01 代码说明

## 正确示例

`hello_analyzer.c` 是 L01 课堂展示的唯一完整正确程序，也是 PPT 中代码片段的来源。

严格编译：

```bash
gcc -std=c17 -Wall -Wextra -Wpedantic -pedantic-errors hello_analyzer.c -o hello_analyzer
/home/by/Programs/toolkits/clang/clang/bin/clang -std=c17 -Wall -Wextra -Wpedantic -pedantic-errors hello_analyzer.c -o hello_analyzer_clang
```

运行后应与 `expected_output.txt` 逐字节一致，退出状态应为 0。

## 教师演示的构建阶段

```bash
gcc -std=c17 -E hello_analyzer.c -o hello_analyzer.i
gcc -std=c17 -S hello_analyzer.c -o hello_analyzer.s
gcc -std=c17 -c hello_analyzer.c -o hello_analyzer.o
gcc hello_analyzer.o -o hello_analyzer
```

`.i`、`.s`、`.o` 和可执行文件只在临时验证目录生成，不纳入课程源码。

## `broken/` 目录

- `missing_semicolon.c`：预期在编译阶段失败。
- `wrong_function_name.c`：预期在严格 C17 编译阶段因未声明函数失败。
- `logic_wrong_order.c`：预期编译、链接和运行均成功，但输出顺序不符合需求，是逻辑错误。
- `link_error/`：两个源文件分别可编译；故意只链接 `link_main.o` 时失败，加入 `report_ready.o` 后成功。函数声明的语法只作阶段观察，正式讲解安排在 L06。

错误示例只用于诊断教学，不纳入“所有程序均应成功编译”的常规门禁。
