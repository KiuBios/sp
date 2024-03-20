# Machine Code

```
1: #include <stdio.h>
2:
3: int power (int a, int n){
4:     int r;
5:     r = a;
    ENT  1
    LLA  -1
    PSH
    LLA  3
    LI
    SI
6:     if (n == 0) return 1;
    LLA  2
    LI
    PSH
    IMM  0
    EQ
    BZ   0
    IMM  1
    LEV
7:     while (n-1>0) {
    LLA  2
    LI
    PSH
    IMM  1
    SUB
    PSH
    IMM  0
    GT
    BZ   0
8:         a = a*r;
    LLA  3
    PSH
    LLA  3
    LI
    PSH
    LLA  -1
    LI
    MUL
    SI
9:         n = n-1;
    LLA  2
    PSH
    LLA  2
    LI
    PSH
    IMM  1
    SUB
    SI
10:     }
11:     return a;
    JMP  -1861226304
    LLA  3
    LI
    LEV
12: }
    LEV
13:
14: int main() {
15:     printf("power(2, 5)=%d\n", power(2, 5));
    ENT  0
    IMM  -1861492720
    PSH
    IMM  2
    PSH
    IMM  5
    PSH
    JSR  -1861226472
    ADJ  2
    PSH
    PRTF
    ADJ  2
```
