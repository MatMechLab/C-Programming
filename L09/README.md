# L09 地址、指针与安全使用：代码

本课用普通对象练习地址、指针读写与生命周期。`reading` 可以看作一个机器人距离传感器的虚构读数，单位为毫米；`a`、`b` 可以看作两个传感器的读数。所有程序均为离线教学小例。把48写成51、对选中读数加2等只是题目约定，不代表真实设备的标定公式。

每个文件都有自己的 `main`，应当分别编译。以第一个指针例为例，在课程根目录执行：

```sh
gcc -std=c17 -Wall -Wextra -Wpedantic code/L09/pointer_basics.c -o /tmp/l09_basics
/tmp/l09_basics
```

| 文件 | 观察重点 |
|---|---|
| [value_copy.c](value_copy.c) | 函数修改普通 `int` 形参，调用者的对象不随之改变 |
| [pointer_basics.c](pointer_basics.c) | `&reading`、`p` 与 `*p`；通过指针把48改为51 |
| [pointer_alias.c](pointer_alias.c) | 两个指针先访问同一对象；改变 `p` 的指向不会同时改变 `q` |
| [pointer_target.c](pointer_target.c) | 目标尚未初始化时，可以先通过有效指针写入，再读取 |
| [pointer_optional.c](pointer_optional.c) | 用 `NULL` 表示本题尚未选择目标，再根据选择读取或更新 |
| [pointer_lifetime.c](pointer_lifetime.c) | 将值复制到寿命较长的对象；临时借用的指针在对象寿命结束前清空 |
| [pointer_const.c](pointer_const.c) | 通过 `const int *` 读取；它不让原本可修改的对象自动变成常量 |
| [pointer_addresses.c](pointer_addresses.c) | 用 `%p` 和 `void *` 实参观察一次运行中的地址 |
| [practice.c](practice.c) | 可编译的练习起始文件，三处任务尚未完成 |
| [practice_solution.c](practice_solution.c) | 完成练习后再对照的答案 |

继续用短程序区分容易混淆的操作：

| 文件 | 观察重点 |
|---|---|
| [pointer_snapshot.c](pointer_snapshot.c) | `copy=*p` 保存当时的整数值；后来修改目标不会同时修改 `copy` |
| [pointer_copy_modes.c](pointer_copy_modes.c) | 比较 `*p=*q` 复制目标值与 `p=q` 复制地址值；输出中的 `same` 表示 `p==q` |
| [pointer_null_zero.c](pointer_null_zero.c) | 指向值为0的对象仍是有效指针；清空一个指针不会清空它的副本 |
| [pointer_guard.c](pointer_guard.c) | 用 `&&` 的短路规则先判断已知指针是否为空，再读取目标；比较空、零、正、负四种情况 |
| [pointer_clear_aliases.c](pointer_clear_aliases.c) | 清空 `p` 以后 `q` 仍可访问活着的目标；两者都在目标结束寿命前清空 |
| [pointer_swap_values.c](pointer_swap_values.c) | 用已经学过的三步交换，通过两个指针交换目标值，指向不变 |
| [pointer_identity.c](pointer_identity.c) | 两个对象即使都保存50，也仍是不同对象；值相等和地址相等是不同问题 |

`pointer_guard.c` 的 `p` 只可能是 `NULL` 或活着的 `x` 的地址，才可以这样使用非空判断。`&&` 不会修复未初始化或悬空指针。`pointer_clear_aliases.c` 的清空赋值只是修改指针变量，不销毁目标，也不改变其他指针。

以下三个短例供课后选读：

| 文件 | 观察重点 |
|---|---|
| [pointer_element.c](pointer_element.c) | 对已经学过的数组元素使用 `&a[1]`，通过指针修改这一项；没有数组形参 |
| [pointer_scope.c](pointer_scope.c) | 内层指针对象结束寿命以后，外层目标对象仍然存在 |
| [pointer_const_fixed.c](pointer_const_fixed.c) | `int * const p` 固定指针保存的地址，但仍可通过它修改可写的 `int` 对象 |

`const int *view` 限制通过 `view` 修改目标；`int * const p` 限制修改指针 `p` 本身。后者初始化之后不能再写 `p = &另一个对象`，例中只执行合法的 `*p = 51`。这些选读例不使用指针算术、数组形参或动态内存。

## 输入与输出

除 `pointer_optional.c` 外，正确示例均不需要输入。`pointer_optional.c` 读取一个受控十进制整数：0表示不选，1选择 `a`，2选择 `b`；选中后将对应读数增加2。数字文本至多2个字符（包括可能的正负号），前后可有空白。示例：

```sh
gcc -std=c17 -Wall -Wextra -Wpedantic code/L09/pointer_optional.c -o /tmp/l09_optional
printf '2\n' | /tmp/l09_optional
```

读取失败或结果不在0～2内时，程序输出错误说明并以状态1结束。成功时退出状态为0。`%2d` 限制一次转换读取的字符数，不能保证读完一个完整数字文本或一整行；例如 `1x` 仍可能读到1。任意文本的完整解析不属于这个例子的功能。

实际运行输出在 [outputs/](outputs/)。`pointer_addresses__fixed.txt` 只记录一次运行；地址的打印形式由实现规定，数值可能随运行变化。不要由这些文本推断对象固定地址、固定间距或所有平台的指针大小。

`pointer_optional.c` 中的非空判断能用于本题，是因为 `p` 的取值始终限于 `NULL`、`&a`、`&b`，且两个目标在整个使用期间都存在、类型匹配并允许写入。一般情况下，`p != NULL` 不能单独证明指针有效。

## 故意错误例

`broken/` 中的程序只用于阅读源码和观察编译诊断，**不要运行**：

| 文件 | 错误原因 |
|---|---|
| [uninitialized_pointer.c](broken/uninitialized_pointer.c) | 自动指针对象未初始化，就读取它的值并解引用 |
| [null_pointer.c](broken/null_pointer.c) | 空指针没有指向可访问对象，不能解引用 |
| [dangling_pointer.c](broken/dangling_pointer.c) | 局部对象已经结束寿命，不能再用原来的指针值访问它 |
| [incompatible_pointer.c](broken/incompatible_pointer.c) | 用 `double` 对象的地址初始化 `int *`，类型不兼容 |
| [const_write.c](broken/const_write.c) | 通过 `const int *` 写入，其解引用表达式不允许赋值 |

编译器可能发现其中一些问题；没有诊断不能证明行为正确。生命周期结束后，旧指针值也不能靠一次 `p != NULL` 比较来“验证”有效性。应从创建目标、获得地址、使用和结束目标寿命的完整过程判断。
