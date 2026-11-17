# L04：if、switch 与边界条件

本目录是课件完整程序的唯一源码位置；PPT中的节选直接从对应标记段读取。

| 文件 | 用途 |
|---|---|
| [range_quality.c](range_quality.c) | 教师演示：根据一个整数毫米读数分类 |
| [measurement_quality.c](measurement_quality.c) | 学生增量练习参考解答：增加记录完成标记 |
| [branch_examples.c](branch_examples.c) | 单分支、双分支、else if、花括号配对及逻辑值 |
| [short_circuit.c](short_circuit.c) | 正秒数检查保护整数除法 |
| [status_switch.c](status_switch.c) | 0/1状态码说明、default与break |
| [grouped_cases.c](grouped_cases.c) | 新增2“待重新测量”，展示0和2共用处理 |
| [broken/](broken/README.md) | 已明确标注的错误对照，和正确例分开 |
| [expansion/](expansion/README.md) | 本轮新增8个正确例及1个隔离错误例：独立/嵌套判断、条件调试、等价分类、字符选项、分段计算 |

## 输入与规则

分类器采用课堂虚构阈值，不能作为真实设备质量标准：40～60 mm为可用范围，其中48～52 mm有效；40～47、53～60 mm需复查，其余整数读数无效。这里只处理整数毫米。

`measurement_quality.c`输入顺序是“读数 标记”；0为记录未完成、1为完成。未完成记录始终分类为无效。标记不是0或1时先报错停止，不能仅把任意非零标记解释为完成。转换失败或非法标记返回1；正常完成分类返回0，即使业务分类是“无效”。这不等于程序对任意外部输入都已正确处理。

所有键盘示例使用受控十进制整数，每项最多四字符（含符号），两项用空白分隔。`%4d`控制一次转换的最大宽度，正值至多9999、负值不小于-999，处于C17最低保证的int范围内；它**不验证完整数字文本、分隔符或整行**。例如双输入`00501`会被读成50和1；`10000 1`会被读成1000和0；`50 1xyz`成功读入两项后仍有尾随文本。配套测试把这些记为输入局限观察，不标作“成功拒绝”。空输入测试指输入流已结束，不是键盘上只按一次回车。

`short_circuit.c`只在秒数为正时求`12 / seconds`。分子固定12，因而还保证商可表示；短路检查不能被推广为任意整数除法的全部安全条件。

## 构建与验证

```bash
gcc -std=c17 -Wall -Wextra -Wpedantic code/L04/range_quality.c -o /tmp/l04_range
/tmp/l04_range
clang -std=c17 -Wall -Wextra -Wpedantic code/L04/range_quality.c -o /tmp/l04_range_clang
python3 -B validation/verify_l04_code.py --clang /path/to/clang
```

验证器依赖GCC、Clang及其UBSan运行时；可用`--work`指定临时构建目录。独立期望值按整数集合枚举生成，不照抄C分支顺序。`tests/cases.json`保存预期、输入和用例用途；`outputs/`保存实际GCC标准输出，PPT读取其中指定记录。测试覆盖普通值、四个阈值及相邻整数、标记优先级、格式失败、输入约定端点及已说明的解析局限。

本轮工具版本、完整命令、退出状态、预期/实际输出和源码哈希见[代码证据](../../validation/L04_code_evidence.json)；独立审查见[规范与代码复核](../../research/L04_standards_review_2026-09-28.md)。测试和工具一致不替代标准语义论证，也不证明所有环境或任意输入均正确。

上段代码证据绑定原6例的既有版本；本次未改这些源码，并逐一核对哈希。61页扩充版新增代码的当前GCC/Clang结果见[扩充验证](../../validation/L04_expansion_code_checks_2026-09-28.md)与[规范增量复核](../../research/L04_expansion_standards_review_2026-09-28.md)。不同版本的编译器诊断不一定相同，旧日志不能冒充当前运行。
