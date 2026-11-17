# L03：表达式、类型转换与可靠计算

当前课件已在原44页基础上扩充。新增算例和本机观察见 [expansion/README.md](expansion/README.md)，由 `validation/verify_l03_expansion.py` 单独验证；下列原六个程序及其既有证据保持原样。当前课件核验见 [扩充交付记录](../../validation/L03_expanded_delivery_checks_2026-09-20.md)。

2026-09-21继续补充的常用运算符例见 [operators/README.md](operators/README.md)，由 `validation/verify_l03_operators.py` 单独核验。五种复合赋值、左右对照均独立设置初值；故意错误的展开在`operators/broken/`。当前课件见 [运算符交付记录](../../validation/L03_operators_delivery_checks_2026-09-21.md)，不将旧代码运行冒称为本轮重跑。

本目录中的 `.c` 文件是课件与讲稿引用的唯一完整源码。面向学生的核心编译方式为：

```sh
gcc -std=c17 -Wall -Wextra -Wpedantic measurement_report.c -lm -o measurement_report
./measurement_report
```

本课程环境的 GCC/Clang、严格验证命令与真实输出见[代码验证记录](../../validation/L03_code_checks.md)和[逐项机器证据](../../validation/L03_code_evidence.json)。`-lm` 是本课程 Linux 工具链的链接用法，不是 C17 规定的命令行参数。

## 程序与用途

| 文件 | 用途 | 代码摘录段标记 |
|---|---|---|
| [measurement_report.c](measurement_report.c) | 三次位置测量的平均值、绝对误差；输入、计算、报告分开 | `input`、`calculate`、`report` |
| [expression_steps.c](expression_steps.c) | 常用算术、负整数余数、括号、复合赋值、单独自增语句 | `arithmetic`、`grouping`、`compound`、`increment` |
| [division_conversion.c](division_conversion.c) | 整数/浮点除法、转换发生的位置、变量原值不变、mm 转 m | `division`、`cast`、`unit` |
| [floating_observation.c](floating_observation.c) | 本机浮点长尾；按练习事先规定的 0.05 mm 容差比较 | `observation`、`tolerance` |
| [practice_fixed.c](practice_fixed.c) | 课堂读数 10、11、13 的整数除法与括号两题的正确参考 | `mean`、`grouping` |
| [denominator_guard.c](denominator_guard.c) | 6 m 路程除以正耗时；输入失败、零耗时、负耗时在除法前停止 | `input`、`guard`、`calculate` |

段标记写作 `// [calculate]` 与 `// [/calculate]`。片段可能依赖该文件中之前的声明；需要独立编译时使用完整源文件。`floating_observation.c` 开头的环境宏和 `volatile` 是教师观察装置，不要求学生在 L03 掌握。

## 主例的数据约定与计算

把同一位置相对于选定参考点的三次读数记为 `first_mm`、`second_mm`、`third_mm`，把比较基准记为 `reference_mm`，单位都是 mm。负值可表示参考点另一侧的位置，不把负数说成实际长度。读数采用整数，是为了在本课清楚比较整数运算与浮点运算。

课堂输入约定：四个十进制整数用空白分开，每个至多四个字符，正负号也计入字符数。示例输入为 `17 18 20 20`：

```text
Enter three measurements and one reference (mm):
sum = 55 mm
mean = 18.333 mm
absolute error = 1.667 mm
```

真实运行输出见[主例输出](outputs/measurement_report_normal.txt)。纸面结果为总和 55 mm，平均值 `55/3` mm，绝对误差 `|55/3 − 20| = 5/3` mm。本课按数值计算语境，将“绝对误差”明确用于相对给定参考值的差的绝对值；参考值并不自动等于未知真值，平均也不保证消除系统偏差。三位小数只是报告格式，不代表误差恰好是 1.667 mm，也不表示仪器因此获得三位小数的精度。参考值为零时仍计算绝对误差；本例没有除以参考值。

这里用 `%4d` 将**每次转换**最多消费的字符数限制为四个。在本程序启动时的默认 C locale 中，每次成功转换的值在 `[-999, 9999]` 内。两项部分和在 `[-1998, 19998]` 内，三项和在 `[-2997, 29997]` 内，符合 C17 对 `int` 至少覆盖 `[-32767, 32767]` 的要求。符号占一位，因此可接受的负值幅度比正值小。这些界限是教学输入设计，不能当作 `int` 的完整取值范围。

`scanf` 返回 4 只说明四次转换赋值成功。它**不是整行或完整 token 校验**：

- `17 18 20 20x` 中的 `x` 不会由本程序检查。
- `12345 1 1 1` 会依次转换为 `1234、5、1、1`，后面的文本没有完全处理。
- 一个非常长的数字串也可能被分成四段，每次最多四字符；不会因此被可靠拒绝。

这些输入在验证证据中列为 `limitation_observation`（局限观测），不是“正确处理任意大数/错误输入”的成功案例。`%4d` 的作用是给单次整数转换提供小范围保障；它不替代 L11 的整行读取与可靠解析。`denominator_guard.c` 有相同的 token 边界局限。

## 结果与风险的读法

- 有定义的整数除法向零截断。`-17 / 5` 为 `-3`，`-17 % 5` 为 `-2`；不使用 Python 的负数 `//` 作为 C 商的参考。
- 赋值前先完成右侧表达式。`double late = 5 / 2;` 得到 2.0；转换整个整数除法结果也不能恢复已丢掉的小数部分。
- `(int)2.9` 和 `(int)-2.9` 是在可表示范围内的有限值示例。不要把“去掉小数部分”的结论无条件推广到非有限值或截断后仍超出 `int` 范围的值。
- `count++;` 与 `++count;` 在本例都是独立语句，各把 `count` 加 1。本课不通过含多次更新的复杂表达式考查求值顺序。
- 浮点长尾文件明示本机参数。C17 不保证所有实现都使用这里观察到的二进制 53 位 `double`，也不保证所有实现的 `0.1 + 0.2 == 0.3` 都返回同一值。
- 0.05 mm 是练习在看结果前规定的容差。数学上 `|10.03 − 10.0| = 0.03 < 0.05`；本例离判断边界有余量。容差要由问题含义决定，不使用“万能 epsilon”，也不把浮点近似差异全部解释成测量误差。
- 三个 UB 反例只编译检查；见 [broken/README.md](broken/README.md)。本机诊断显示的溢出数值不是 C17 规定的可靠结果。

## 可复现验证

从课程根目录运行：

```sh
python3 -B validation/verify_l03_code.py
```

该脚本把二进制与教师类型探针写到 `/tmp`，把逐项证据写入 `validation/L03_code_evidence.json`。全部本轮检查通过后，才刷新本目录 `tests/` 中的输入与 `outputs/` 中的真实输出。验证包括两编译器严格 C17、独立分数/十进制手算、输入错误与边界、适用的 ASan/UBSan 和 UB 只编译检查；运行通过不等于所有输入或所有平台都已证明正确。技术条款、规范版本边界及在线来源见[独立标准审阅](../../research/L03_standards_online_review_2026-09-20.md)；课件视觉验收由本课课件验证记录单独覆盖。

[classroom_calculations.txt](outputs/classroom_calculations.txt) 是验证器在 `/tmp` 中生成的安全课堂小探针的真实输出，覆盖页面短算式、自增、短测与显示格式。探针源码、类型断言与独立分数参考保存在本轮证据中；它是教师验证装置，不是新增学生必学的完整程序。

## 课后练习

预计 50 分钟：完成三次位置测量的平均值及与给定参考值的绝对差程序。采用本课四项整数输入约定，保留输入失败处理、总和、平均值、绝对差及单位；提交源文件、两组独立手算和测试记录。至少覆盖参考值 0、负读数、约定内的最大/最小值、不能被 3 整除的和以及输入失败。

“大数测试”在本例中指约定内的端点，如 9999 与 -999；额外尝试超宽数字时只能记录其被截段或残留文本的现象，不能声称程序已经可靠拒绝它。除零防护使用单独的耗时练习核对，不能把参考值为 0 误当成主程序必须拒绝的情况；该练习的路程除以时间得到平均速率。

可选约 15 分钟：用两组测试解释整数除法错误为何可能被一组数据掩盖、又被另一组暴露。评价看公式解释、已讲知识的综合应用、代码清楚程度和测试证据，不要求引入数组、循环或复杂输入解析。
