# L04 错误对照

这里的文件不属于正确示例，不应复制为作业答案。所有程序与正常例隔离。

| 文件 | 分类和错误机制 | 检查方式 |
|---|---|---|
| independent_if.c | 有定义的逻辑错误：两个if分别成立，输出两个分类 | 实际运行对照 |
| empty_if.c | 有定义的逻辑错误：空语句被if控制，后续块独立执行 | 实际警告及运行 |
| dangling_else.c | 有定义的语法误读：else归属内层if，缩进不改变配对 | 实际警告及运行 |
| chained_comparison.c | 有定义的错误区间表达式：先得0/1，再比较52 | GCC警告及运行；当前Clang诊断为错误，未运行其版本 |
| broad_first.c | 有定义的逻辑错误：宽范围抢先，内部有效分支不可达 | 50等输入揭露错误 |
| switch_no_break.c | 有定义的逻辑错误：从case0顺序落入case1 | 实际诊断和输出 |
| assignment_condition.c | 有定义的逻辑错误：=把status改为0，条件为假 | 实际警告和输出 |
| switch_float.c | 约束违反：switch控制表达式不是整数类型 | **只编译，不运行** |
| case_variable.c | 约束违反：C17 const int对象不是整数常量表达式 | **只编译，不运行** |
| duplicate_case.c | 约束违反：同一switch标签值重复 | **只编译，不运行** |

所有构建使用`-std=c17 -Wall -Wextra -Wpedantic`；三个约束反例另加`-fsyntax-only -pedantic-errors -Werror`。在不加`-Werror`时，当前Clang可对`case_variable.c`发GNU扩展警告后接受，GCC会拒绝，详见独立复核记录。不能用“某编译器接受”证明标准允许。

诊断须读具体原因：empty body表示if控制了空语句；dangling else提示配对不清；assignment as condition提醒条件里用了赋值；fall through说明可能继续进入后一标签下的语句。编译器不同版本和选项的诊断可能不同，没有警告不证明符合题目要求。
