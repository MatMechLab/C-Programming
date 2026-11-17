# 数组错误对照：只编译，不运行

这3个文件用于讨论错误原因。不要执行它们，也不要与正确示例一起编译链接。

| 文件 | 错误原因 | 修改方向 |
|---|---|---|
| [out_of_bounds.c](out_of_bounds.c) | 容量为4，`i <= 4` 仍会让 `i == 4` 进入循环；`reading[4]` 不存在 | 本例循环条件应为 `i < 4` |
| [uninitialized.c](uninitialized.c) | 自动局部数组未初始化，就读取 `reading[0]` | 读取某个元素之前，先给它确定的值 |
| [whole_assignment.c](whole_assignment.c) | `copied = original` 试图给整个数组赋值 | 用循环逐项复制，见 [copy_array.c](../copy_array.c) |

在课程根目录使用下面的命令，只生成目标文件，不运行程序：

```bash
gcc -std=c17 -Wall -Wextra -Wpedantic -Werror -O2 -c code/L07/broken/out_of_bounds.c -o /tmp/l07_broken.o
```

GCC 15.2.0对此例给出的关键诊断是：

```text
error: iteration 4 invokes undefined behavior
```

它指出循环执行到 `i == 4` 时会引发未定义行为。容量4的数组只有下标0、1、2、3。

另外两个程序的实际GCC诊断分别包含：

```text
error: 'reading' is used uninitialized
error: assignment to expression with array type
```

前一句表示使用了未初始化的数组；后一句表示赋值左侧是数组类型，不能这样整体赋值。`-Werror` 会把编译器发出的警告按错误处理。

是否发出警告会受编译器和选项影响。对越界及未初始化读取，即使没有警告，也不能据此认为程序正确；需要根据下标范围和每条执行路径判断。数组整体赋值则违反语言约束，编译器应给出诊断。
