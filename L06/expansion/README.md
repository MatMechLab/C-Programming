# L06：函数的进一步使用

本目录补充6个独立程序。每次选择一个 `.c` 文件单独编译运行；每个文件都有自己的 `main`，不要把全部源文件一起链接。课件中的节选来自这些完整源文件。

| 程序 | 主要内容 | 输入 |
|---|---|---|
| [argument_values.c](argument_values.c) | 实参表达式；返回值参与表达式；原型、定义与调用中的名字 | 无 |
| [numeric_interfaces.c](numeric_interfaces.c) | 形参类型转换；返回类型转换；接口是否保留小数 | 无 |
| [call_chain.c](call_chain.c) | 函数调用另一个函数；分步调用与嵌套调用 | 无 |
| [scope_and_dependency.c](scope_and_dependency.c) | 内层同名变量；把上限作为形参传入 | 无 |
| [loop_calls.c](loop_calls.c) | 在循环中反复调用换算函数 | 无 |
| [six_temperature_functions.c](six_temperature_functions.c) | 将L05的六项温度统计拆分为判断、平均与换算函数 | 6个整数温度 |

## 编译与运行

在课程根目录执行：

```bash
gcc -std=c17 -Wall -Wextra -Wpedantic -Werror code/L06/expansion/argument_values.c -o /tmp/l06_arguments
/tmp/l06_arguments
```

其他程序更换源文件名和输出程序名即可。已安装Clang时，也可以把`gcc`改为`clang`。

六项温度程序可单独编译运行：

```bash
gcc -std=c17 -Wall -Wextra -Wpedantic -Werror code/L06/expansion/six_temperature_functions.c -o /tmp/l06_six
/tmp/l06_six
```

出现提示后输入`18 -25 21 50 18 -20`并按回车。预期有效5项、无效1项、有效总和87 ℃、最低−20 ℃、最高50 ℃、平均17.40 ℃、华氏平均63.32 ℉。程序的实际输出在[样例输出](outputs/six_temperature_functions__sample.txt)中；文件不包含键盘回显。

## 看代码时注意

- `to_fahrenheit(temp_c + 2.0)`将表达式的值传给函数。`temp_c`仍为18.0；换算20.0 ℃的结果是68.00 ℉。
- 原型中写`input_c`、定义中写`c`、调用者使用`temp_c`，三处名字不必相同。声明和定义的函数类型必须相容。
- 有可见原型时，实参值按照对应形参的类型转换。`18`传给`double`形参得到18.0；`18.75`传给`int`形参时丢弃小数部分，得到18。原来的`precise_c`仍是18.75。
- `whole_degrees`的返回类型是`int`。本例传入有限且有界的温度，转换得到18和−18；这是向零截断，不是四舍五入。若计算需要保留小数，应选择合适的参数及返回类型。
- `mean_fahrenheit`先求摄氏平均值，再换算成华氏温度。嵌套表达式中，内层调用的结果成为外层调用的实参；这里没有函数调用自身。
- 内层另声明的`temp_c`与外层`temp_c`是两个对象。内层名称在其作用域内遮蔽外层同名变量；退出内层后，外层变量仍是18。
- `allowed_with_limit(c, upper)`只判断是否不高于上限，不高于时返回1。它没有检查温度下限，不能代替完整的有效性判断；上限直接从实参传入，不再读取可变的全局上限。

## 输入约定与函数前提

有效温度范围`[-20,50] ℃`是课堂练习约定，包含两端，不是设备安全阈值。`to_fahrenheit`只在这个范围内接收有限温度。`mean_temperature`与`mean_fahrenheit`要求`count`在1～6之间，`sum_c`是同一批有效整数温度的总和；没有有效温度时，调用者直接报告说明，不调用平均函数。

`numeric_interfaces`中的`remaining_to_upper`按整数摄氏度计算，参数在−20～50之间；`whole_degrees`也只处理此范围内的有限值，因此丢弃小数后的整数可由`int`表示。本例不演示范围外转换。

六项程序要求每个十进制整数最多4个字符，包含可选的正负号，并以空白分隔。成功读取但不在有效范围内的数只增加无效数，随后继续读取。读取失败时立即打印输入错误并返回1，不输出部分统计。正常读完6项后返回0；这表示处理完成，不表示每个温度都有效。

`scanf("%4d", &temp_c)`的字段宽度只限制本次转换读取的字符数，不能验证整行或完整数字文本。例如`000018`可能被相邻两次转换读作0和18；`18x`先读到18，但下一次转换遇到`x`会失败。六次转换之后的额外内容也不会被本程序检查。请遵守本例的输入约定。

可以继续尝试[全部无效](outputs/six_temperature_functions__none.txt)、[全部为下界](outputs/six_temperature_functions__all_minimum.txt)、[全部为上界](outputs/six_temperature_functions__all_maximum.txt)、[有效值全为负数](outputs/six_temperature_functions__all_negative.txt)等情况。零个有效值时输出数量、总和0和说明，不计算平均值或极值。

其他实际输出保存在[outputs/](outputs/)中。无输入短例的文件名为`程序名__fixed.txt`；综合程序的文件名中，双下划线后为用例名称。
