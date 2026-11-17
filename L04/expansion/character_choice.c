#include <stdio.h>

/* 只演示文字选择；不操作真实设备。读取第一个非空白字符，非整行校验。 */
int main(void)
{
    // [input]
    char choice = '\0';
    if (scanf(" %c", &choice) != 1) {
        puts("输入错误");
        return 1;
    }
    // [/input]
    // [choice]
    switch (choice) {
    case 'R':
        puts("选择重新记录");
        break;
    case 'Q':
        puts("结束演示");
        return 0;
    default:
        puts("未知选项");
        break;
    }
    puts("本次选择处理结束");
    // [/choice]
    return 0;
}
