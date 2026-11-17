# L03 扩充示例

本目录只保存本轮新增材料，原 L03 六个正确程序不变。`.c` 是课件引用的唯一完整源码；各段以 `// [名称]` 和 `// [/名称]` 标记。输出文件是本轮工具实际捕获，不是手写终端截图。

| 完整源码 | 摘录段标记 | 实际输出 |
|---|---|---|
| [formula_steps.c](formula_steps.c) | `grouping`、`unary`、`geometry`、`compound`、`unit`、`mixed`、`rearrange`、`cast`、`absolute_error` | [formula_steps.txt](outputs/formula_steps.txt) |
| [interval_rate.c](interval_rate.c) | `input`、`denominator`、`zero_guard`、`negative_guard`、`calculation` | [正常输入](outputs/interval_rate_normal.txt)；其余见 `outputs/interval_rate_*.txt` |
| [mixed_types.c](mixed_types.c) | `expressions` | [mixed_types.txt](outputs/mixed_types.txt) |
| [rounding_observation.c](rounding_observation.c) | `environment`、`conversion`、`grouping` | [rounding_observation.txt](outputs/rounding_observation.txt) |
| [broken/measurement_truncated.c](broken/measurement_truncated.c) | `calculate`、`report` | [measurement_truncated.txt](outputs/measurement_truncated.txt) |

从课程根目录复现：

```sh
python3 -B validation/verify_l03_expansion.py
```

编译器、命令、输入、退出状态、数值期望、实际输出及 SHA-256 见[代码核验报告](../../../validation/L03_expansion_code_checks_2026-09-20.md)和[机器证据](../../../validation/L03_expansion_code_evidence.json)。二进制与教师类型探针写入 `/tmp`；不会覆盖或重跑旧六个程序。

本轮仅补充公式程序的短式后，以 `python3 -B validation/verify_l03_expansion.py --only-formula` 做范围内复验。该模式须先确认其他源文件、输出、期望与编译器身份均未变，再复用原有结果；证据分别记录本次实际执行和保留的历史覆盖。

## 固定小算式

`formula_steps.c` 没有输入路径，使用的全部数值在源码中固定，分母非零，中间整数结果在标准至少保证的范围内。验证的是这些算式，不声称测试了任意输入。

- `(8.0+4.0)/(3.0+1.0)` 数学结果为 3；省略括号写成 `8.0+4.0/3.0+1.0` 后数学结果为 `31/3`，程序显示其近似值 10.333333。
- 同一组 a、b 中，`-(a-b)` 表示对整个差取负，得到 -4.0；不能漏掉负号所作用的范围。
- `int count=9; count/=2.0;` 先做浮点除法得到 4.5，再存回 `int` 得到 4；复合赋值没有自动改变对象类型。
- 单位换算时，整数 `1250/1000` 先得到 1；`1250/1000.0` 得到 1.25。若原量为 mm，后者对应 1.250 m。
- `2.0+9/4` 中的 `9/4` 独立进行整数除法，得到整个式子的 4.0；`(2.0+9)/4` 得到 2.75。
- `7/2*2.0` 与 `7*2.0/2` 分别为 6.0 和 7.0，提醒学生数学代数改写不能直接忽略 C 的类型与中间计算。
- 本例 `(int)2.75` 与 `(int)-2.75` 是在可表示范围内的向零截断，分别得到 2、-2；后者数学上的向下取整是 -3。数学比较只用于手算，没有通过危险转换或负值技巧制造运行现象。
- `fabs(18.5-20.0)` 与 `fabs(21.5-20.0)` 都为 1.5，显示本例对参考值两侧的偏差均取非负大小；完整程序已包含 `<math.h>`。

## 从两个时刻得到分母

`interval_rate.c` 固定路程为 18.0 mm，输入开始/结束时刻，先计算 `elapsed_s=end_s-start_s`，再检查实际分母是否为 0、是否为负。只有正耗时才计算平均速率，单位 mm/s。`2 8` 得到 6 s 和 3.000 mm/s；`2 2` 与 `8 2` 分别走零值、负值分支。

课堂约定两项均为十进制整数，每项至多四个字符，符号计入，项间用空白分开。`%4d` 的单次成功转换值在 `[-999,9999]`，所以差值在 `[-10998,10998]`，可由 C17 最低要求的 `int` 范围表示。负的时刻可理解为选定零时刻之前，是否可用于该例由两个时刻的相对先后决定。

这仍不是完整输入行解析：`2 8x` 和 `2 8 99` 的尾部未检查；`22223333` 会被读成两项 2222、3333。相应测试明确标成“局限观测”，不会因程序返回 0 就宣称这些文本满足完整课堂输入约定。输入不可完成两项赋值时，程序在使用时刻值前停止。

## 表达式类型与调用时提升

`mixed_types.c` 使用 `float f=1.5F`、`int n=2`、`double d=0.25`。`f+f` 的表达式类型为 `float`，`f+n` 也为 `float`，`f+d` 为 `double`；数值依次是 3、3.5、1.75。这些特意选择的小值在本课二进制浮点环境中可以精确表示，便于把注意力放在类型上。

`printf` 的可变实参有另一条规则：传入其中的 `float` 值会默认提升为 `double`，与这里使用的 `%f` 配合。这不意味着之前的 `f+f` 已经变成 `double` 表达式。教师验证器在 `/tmp` 用 `_Generic`/`_Static_assert` 核对表达式类型；这些验证语法不是本课学生必学内容，打印出的数字本身也不能证明表达式类型。

## 教师浮点查阅例

`rounding_observation.c` 首行明确标注本机观察，随后输出基数、`double` 有效位数、求值模式及 `FLT_ROUNDS`。本轮为 `2 / 53 / 0 / 1`；没有启用 `-ffast-math`。

整数 `9007199254740993LL` 在 C17 保证的 `long long` 范围内。它转存到本机 `double` 后显示 `9007199254740992`；这不说明原来的 `long long` 对象改变了，也不说明所有 C17 实现必然选择这个邻近值。C 核心标准对不能精确表示但仍在范围内的整数转实浮点允许实现选择邻近值；本轮的最近偶数结果由实际工具和独立分数算法核对。

另一个固定例通过 `volatile` 中间对象明确保留存储步骤。本机先算 `1e16+(-1e16)` 再加 1，得到 1.0；先存储 `-1e16+1` 的舍入结果再加 `1e16`，得到 0.0。GCC/Clang 的 `-O0` 与 `-O2` 实测相同。这里展示具体分组与中间舍入；不能推广为“任意表达式总按从左到右求值”。`volatile` 仅是教师观察装置，不扩充本课核心语法。

## 可安全运行的错误对照

`broken/measurement_truncated.c` 使用固定的 17、18、20 mm 和参考 20 mm。错误在 `double mean_mm = sum_mm / 3;`：整数除法先把 55/3 截成 18，再存进 `double`，因此报告的绝对差变成 2.000 mm。所有运算均有定义，可以运行对照，但不能作为正确解答。

正确结果仍引用旧 [measurement_report.c](../measurement_report.c)及其[已核验实际输出](../outputs/measurement_report_normal.txt)：总和 55，平均显示 18.333，绝对差显示 1.667。扩充验证只核对旧文件与既有证据的哈希并复用记录，没有再创建正确主程序副本，也没有重跑未改动程序。
