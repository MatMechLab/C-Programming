# L04 扩充示例

本目录供课堂新页及课后补充使用；完整程序以这里的 `.c` 文件为准，PPT节选由标记段自动读取。课后补充不改变90分钟课堂和40分钟实践安排。

| 程序 | 用途与输入 |
|---|---|
| [independent_checks.c](independent_checks.c) | 输入读数、0/1标记；满足的两项提醒分别显示，例如 `53 0` 显示两条 |
| [nested_checks.c](nested_checks.c) | 同样输入；先检查是否记录，再判断是否达到48毫米下限，不作完整质量分类 |
| [condition_tools.c](condition_tools.c) | 输入读数与任意受控整数标记；显示中间真假结果、区间取反和标记是否合法 |
| [retained_state.c](retained_state.c) | 输入读数；用初始化及条件赋值展示“不进入分支就保留原值”，只提醒是否超出[48,52] |
| [range_ascending.c](range_ascending.c) | 输入读数；沿数轴升序判断，与原 `range_quality.c` 的虚构分类规则相同 |
| [character_choice.c](character_choice.c) | 读取第一个非空白字符；`R` 显示选择说明后继续，`Q` 从main返回，其他字符显示未知选项 |
| [no_default.c](no_default.c) | 输入整数状态；刻意省略default，观察无匹配时仍执行switch之后的语句 |
| [print_fee.c](print_fee.c) | 输入0～1000页；虚构计费：前10页每页2角，超出部分每页1角 |
| [broken/missing_parentheses.c](broken/missing_parentheses.c) | 有定义的错误对照：漏括号让偏高读数绕过记录完成检查，不是正确示例 |

数字输入沿用受控十进制整数约定：每项至多四字符，含正负号；两项用空白分隔。`%4d`不验证完整数字文本、分隔符或整行；超过约定的输入可能被拆分而非拒绝。字符例的`scanf(" %c", &choice)`先跳过空白，再读一个字符；`Rextra`只读R，不能称为已验证整行。输入流结束与只按一次回车不同。

记录标记用于嵌套和独立提醒时先验证为0/1；`condition_tools.c`特意接受其他受控整数，以展示合法性判断。逻辑非不改变原变量；保存下来的条件结果不会随输入对象以后改变而自动重算。所有阈值和收费规则均为课堂虚构。

```bash
gcc -std=c17 -Wall -Wextra -Wpedantic code/L04/expansion/print_fee.c -o /tmp/l04_print_fee
clang -std=c17 -Wall -Wextra -Wpedantic code/L04/expansion/print_fee.c -o /tmp/l04_print_fee_clang
python3 -B validation/verify_l04_expansion.py --clang /path/to/clang --work /tmp/l04_expansion_tests
```

[验证说明](../../../validation/L04_expansion_code_checks_2026-09-28.md)和[完整证据](../../../validation/L04_expansion_code_evidence.json)保存当前命令、版本、正常/边界/错误路径、UBSan与独立预期。费用预期按逐页累加求得；分类预期按整数集合生成；原分类与升序版还作实际输出对照。四个等号错误只在临时副本中制造，不改正式源码。

`tests/cases.json`记录输入与预期；`outputs/`保存选定真实输出，全部执行结果在机器证据中。故意错误例的预期输出只是为了说明错误机制，不代表满足业务要求。
