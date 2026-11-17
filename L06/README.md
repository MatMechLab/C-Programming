# L06：函数、参数、返回值与作用域

本目录顶层保存8个独立的完整程序，另有[函数的进一步使用](expansion/README.md)中的6个程序，涵盖类型转换、函数组合、循环调用与六项温度统计。**每次选择一个 `.c` 文件编译、运行**；每个文件都有自己的 `main`，不要把所有 `.c` 文件放进同一次链接命令。课件中的代码节选来自这些源文件。

| 文件 | 观察什么 | 是否需要键盘输入 |
|---|---|---|
| [convert_temperature.c](convert_temperature.c) | 原型、定义和调用；18 ℃换算为64.40 ℉ | 不需要 |
| [value_copy.c](value_copy.c) | 修改形参后，调用者仍为18；接收返回值并赋值后为20 | 不需要 |
| [void_report.c](void_report.c) | 无参函数、有参void函数及提前返回；报告80无效后main继续执行 | 不需要 |
| [scope_demo.c](scope_demo.c) | 外层的total与内层的valid各自在哪里可用 | 不需要 |
| [repeat_local.c](repeat_local.c) | 两次调用分别初始化局部变量，得到1和1 | 不需要 |
| [file_scope.c](file_scope.c) | 全局上限改变后，同样的allowed(40)得到不同结果 | 不需要 |
| [temperature_functions.c](temperature_functions.c) | 读入、判断有效、换算、分类、显示 | 一个整数温度 |
| [practice_functions.c](practice_functions.c) | 平均值17.40 ℃；闭区间判断0、1、1、0 | 不需要 |

## 单独编译与运行

在课程根目录执行下面两行，先编译换算短例，再运行它：

```bash
gcc -std=c17 -Wall -Wextra -Wpedantic -Werror code/L06/convert_temperature.c -o /tmp/l06_convert
/tmp/l06_convert
```

运行综合温度程序时，单独编译它；出现提示后输入一个整数并按回车：

```bash
gcc -std=c17 -Wall -Wextra -Wpedantic -Werror code/L06/temperature_functions.c -o /tmp/l06_temperature
/tmp/l06_temperature
```

其他程序采用同样方法，更换源文件名和输出程序名即可。已安装Clang时，也可将编译命令中的`gcc`改为`clang`。`-std=c17`选择C17；三个`-W...`选项启用常用警告，`-Werror`把警告作为编译失败处理。

## 输入约定与函数前提

综合程序只读取一个十进制整数，最多4个字符，包含可选的正负号。有效范围`[-20,50] ℃`是课堂练习约定，包含两端，不代表真实设备的安全范围。可先输入18，再分别试−20、50、51和字母x。

`scanf("%4d", &temp_c)`未成功赋值时，程序打印“输入错误”并返回1；成功读到整数但超出课堂范围时，打印“温度无效”并返回0。这里返回0表示完成了本次处理，不能解释为温度有效。只按回车通常还会等待输入，与输入流结束不同。

`%4d`只限制本次转换的字符数，**不检查整行是否恰好为一个整数**。例如`18x`和`18.5`都可能先读出18；`000018`会先读出0并留下18。因此应遵守输入约定，不把本例当作通用文本解析器。

| 函数 | 使用条件与结果 |
|---|---|
| `to_fahrenheit(c)` | 本课传入−20～50 ℃的有限温度，返回对应的华氏温度；计算和显示分开 |
| `add_two(value)` | 本例使用小整数；加2的结果必须仍可由int表示 |
| `print_temperature(temp_c)` | 接收一个int；在课堂有效范围内则打印温度，否则打印无效并结束这次函数调用 |
| `is_valid_temperature(temp_c)` | 接收一个int；在[-20,50]内返回1，否则返回0 |
| `temperature_band(temp_c)` | **先确认温度有效**；小于10返回0，10～30含两端返回1，大于30返回2；只是课堂分类代码 |
| `mean_temperature(sum_c, count)` | count为1～6；sum_c来自这些有效温度。零个有效值由调用者处理，不调用本函数 |
| `in_closed_range(value, low, high)` | low≤high；闭区间包含两端，在区间内返回1，否则返回0 |
| `allowed(c)` | 只判断c是否不大于当前upper_c，不是完整的温度有效性判断；专门观察对共享状态的依赖 |

两份完整程序都含有`to_fahrenheit`，是为了让它们能够各自单独编译。把程序拆成多个源文件是后续内容，这里不要将它们合并链接。

## 输出与错误对照

[outputs/](outputs/)保存实际标准输出。无键盘输入的程序使用`程序名__fixed.txt`；综合程序还提供`normal18`、`lower`、`upper`、`invalid`、`input_error`和`eof`等用例，名称位于双下划线之后。文本只保存程序输出，不含键盘回显。

[broken/](broken/README.md)中的5个程序是故意错误对照，**只编译看诊断，不运行**。不要把它们当作练习参考解答，也不要与正确程序一起编译链接。
