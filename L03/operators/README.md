# L03 常用运算符示例

[operator_examples.c](operator_examples.c) 是本轮新增正确示例的唯一完整源码。它没有键盘输入，按固定的小 `int` 数据输出结果。课件可以用段标记提取代码；完整运行输出见 [operator_examples.txt](outputs/operator_examples.txt)。没有创建或改写旧 L03 六个程序及 `expansion/` 中的源码。

| 段标记 | 说明 | 本例结果 |
|---|---|---|
| `unary` | 一元正负号与二元减法；x 从 -6 开始 | +x 为 -6，-x 为 6，x-2 为 -8；x 仍为 -6 |
| `value_and_update` | 求出一个值与存回原对象 | plain 仍为 8，result 为 11；updated 从 8 变为 11 |
| `compound` | 五个独立变量都从 17 开始，再各自与 5 计算 | += 为 22，-= 为 12，*= 为 85，/= 为 3，%= 为 2 |
| `compound_grouping` | 两个普通变量独立从 4 开始，a=2、b=3 | 复合赋值和正确展开均为 20 |
| `remainder` | 非负整数的十进制末位、去掉末位后的整数及除 2 余数 | 247%10 为 7，247/10 为 24，247%2 为 1 |
| `decrement` | 两个变量独立从 5 开始；先存表达式值，再输出 | 前置提供 4，后置提供 5；语句后两变量均为 4 |
| `assign_compare` | 赋值改变对象；比较给出真假结果 | assigned 变为 5；same 为 0，compared 仍为 3 |
| `comparison` | n=5、limit=8；按 <、<=、>、>=、==、!= 检查 | 依次为 int 的 1、1、0、0、0、1 |
| `logical` | ready=2、fault=0；只作逻辑运算查阅 | !ready=0，!fault=1，两个方向的 && 均为 0，ready\|\|fault=1，ready&&!fault=1；2&&1 为 1 |

标记形式为 `// [unary]` 与 `// [/unary]`。各个“独立开始”的对象使用不同变量名，避免把表中结果误当成同一变量连续执行多条更新后的结果。输出标签也没有写成给常量赋值的伪代码。

## 正确展开与错误对照分开

对于这里的普通变量，`grouped_n *= a + b` 按相应算术与赋值可展开为 `expanded_n = expanded_n * (a + b)`。两例都独立从 4 开始；右侧的和是 `2+3`，所以各得 20。

有定义的错误改写单独存放在 [broken/compound_grouping_wrong.c](broken/compound_grouping_wrong.c)。它把右侧写成 `n * a + b`，计算成 `4*2+3=11`，不能说与原复合赋值等价。该文件可安全运行作对照，真实输出是 [compound_grouping_wrong.txt](outputs/compound_grouping_wrong.txt)。不要把这个错误版本当作正确解答。

一般的复合赋值左操作数只求值一次；本课只用普通变量解释，不把这种代数展开机械套到复杂左侧表达式。

## 余数、比较和逻辑的范围

末位练习限定**非负整数**。教师探针检查了 0、1、8、9、10、19、247、250、32767：十进制字符串分解、数学二进制末位与 C 结果一致。对于负奇数，不能直接照搬“除 2 余数为 1”；独立核对的 `-3 % 2` 为 -1。这里的十进制末位计算操作的是整数值，不是在删除或处理字符串中的字符。

比较的补充数据包含小于、等于和大于：5/8、5/5、9/8，以及 0/0、-1/0、0/-1。六种比较结果都是 `int` 的 0 或 1。不会因为比较为真就改变被比较的对象。

逻辑运算按“0 为假、非 0 为真”解释；输入值 2 和 -2 也可为真。逻辑结果仍为 `int` 的 0 或 1，`2 && 1` 得到 1，不会把操作数 2 原样传出来。此段是可跳过的衔接查阅，不提前展开 L04 的复杂条件与分支设计。

`fault && ready` 中 fault 为 0，按标准短路规则右边不求值；`ready || fault` 中 ready 为非 0，右边也不求值。但仅看到输出 0 或 1 不能单独证明求值顺序，本轮没有为观察顺序加入副作用或危险除法。规则由[独立语义复核](../../../research/L03_operators_review_2026-09-21.md)对应的规范条款支持。

## 只编译的约束错误

| 文件 | 问题 | 处理 |
|---|---|---|
| [floating_remainder.c](broken/floating_remainder.c) | `5.0 % 2.0` 的两个操作数是 double，违反 `%` 的整数操作数要求 | 仅用 `-fsyntax-only` 保存实际诊断，禁止执行 |
| [decrement_constant.c](broken/decrement_constant.c) | 常量 5 不是可修改对象，不能写 `5--` | 仅编译诊断，禁止执行 |

它们属于源程序约束错误，不提供可猜测的运行答案。GCC/Clang 四份诊断在 `outputs/`；中文解释与当前代码版本见[核验报告](../../../validation/L03_operators_code_checks_2026-09-21.md)。不要对 `broken/` 中的全部文件进行批量执行。

## 验证与复现

从课程根目录运行：

```sh
python3 -B validation/verify_l03_operators.py
```

临时边界与 `_Generic` 类型探针只写到 `/tmp/l03_ops_20260921/code/`，不是新增学生必学语法。其实际输出为 [operator_boundary_probe.txt](outputs/operator_boundary_probe.txt)，独立数学/状态参照为 [independent_references.json](tests/independent_references.json)。

将错误改写移入 `broken/` 后，最后一次用 `--only-changed` 只重验受影响主例及新错误文件；未变的探针和约束诊断按源码、期望、编译器身份与输出哈希复用。完整细节见 [L03_operators_code_evidence.json](../../../validation/L03_operators_code_evidence.json)。原有 146 个 L03 文件的大小、mtime 和 SHA-256 还与本任务开始清单逐项核对，记录于 [previous_code_preservation.json](tests/previous_code_preservation.json)。

本例不读取输入，不能把固定值演示说成“任意输入/错误输入已全部验证”。所有正常示例的整型值与中间结果均在 C17 最低保证的 `int` 范围内；除数为已知非零小值，自减不接近整数下界。真实课堂理解效果与课件视觉另行验收。
