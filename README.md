# Algorithm

算法竞赛题解留档，用于赛后复盘与长期积累。

## 目录结构

```
.
├── AtCoder/                  # AtCoder 比赛
│   └── ABC<场次>/
│       └── <题号>.cpp
├── XCPC/                     # 其他 XCPC 系列赛事
│   └── <省赛/赛事><年份>/
│       └── <题号>.cpp
└── test*.cpp                 # 日常练习、模板验证
```

命名约定：

- AtCoder：`AtCoder/ABC481/D.cpp`
- 省赛/邀请赛：`XCPC/jiangsu2026/B.cpp`
- 一场比赛一个目录，题号用大写字母，便于按场次回看

## 编译

```bash
g++ -O2 -std=c++20 -Wall -Wextra xxx.cpp -o /tmp/x
```

建议输出到 `/tmp`（或 `a.out`，已在 `.gitignore` 中忽略），避免每次编译都在仓库里产生二进制文件。

## 复盘习惯

- 按场次提交，一次比赛一个 commit，信息写场次号，例如 `ABC483`
- 没做出来的题也留下代码，方便日后重做对比
- 错题可在提交信息或代码头部注释里标注思路与坑点

## 状态

- 已归档：`AtCoder/ABC481`、`AtCoder/ABC482`、`XCPC/jiangsu2026`
- 进行中：`XCPC/shandong2026`
