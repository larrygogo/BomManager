# BOM管理系统(BOM System)

## 介绍

这是一个基于C语言的BOM管理系统，可以实现对BOM的增删改查，以及对BOM的导入导出。

### 1.目录结构

```

├─core      -------------核心代码
│  ├─BOMPart.c      //** 物料操作
│  ├─BOMFormula.c   //** 生产计划操作
│  ├─BOMPartCount.c //** 生产计划明细
│  ├─BOMUtils.c     //** 工具函数
│  ├─BOMMenu.c      //** 系统菜单
├─data      -------------数据文件
│  ├─Formula.csv    //** 生产计划数据
│  └─Part.csv       //** 物料数据
├─include   -------------头文件
│  ├─BOMPart.h      //** 物料操作头文件
│  ├─BOMFormula.h   //** 生产计划头文件
│  ├─BOMPartCount.h //** 生产计划明细头文件
│  ├─BOMUtils.h     //** 工具函数头文件
│  ├─BOMMenu.h      //** 系统菜单头文件
│  └─BOMTypes.h     //** 数据类型头文件
├─main.c            //** 头文件
└─README.md         //** 说明文档

```

### 2.系统功能(菜单介绍)

打开运行程序后，会出现如下菜单：

```
┌─────────────── BOM System ───────────────┐
│ 1. Part manage                           │  # 物料管理   
│ 2. Formula manage                        │  # 生产计划管理
│ 0. Exit                                  │  # 退出系统
└─────────────── BOM System ───────────────┘
Please input your choice:
```
依次分别为物料管理、生产计划管理、退出系统，输入对应的数字按回车即可进入对应的菜单。

#### 2.1 物料管理 (Part manage)

进入物料管理菜单后，会出现如下菜单：

```
┌─────────────── Part manage ───────────────┐
│ 1. Show all parts                         │  # 物料信息展示
│ 2. Create part                            │  # 物料信息录入
│ 3. Delete part                            │  # 物料信息删除
│ 4. Update part                            │  # 物料信息修改
│ 0. Back                                   │  # 返回上一级菜单
│ -1. Exit                                  │  # 退出系统
└─────────────── BOM System ────────────────┘
Please input your choice:
```


##### 2.1.1 物料信息录入

```
─────────────── Create Part ───────────────
Please enter the part id: 0001   # 输入物料编号
Please enter the part name: egg  # 输入物料名称，不支持空格和中文
Please enter the part total: 10  # 输入物料总数
```
依次输入物料的编号、名称、总数，按回车即可录入。


##### 2.1.2 物料信息删除
```
─────────────── Delete Part ───────────────
Please enter the part id: 0001  # 输入要删除的物料编号
```
输入要删除的物料编号，按回车即可删除。
```
Delete part success! # 删除成功
Delete part failed!  # 删除失败
```

##### 2.1.3 物料信息修改
```
─────────────── Update Part ───────────────
Please enter the part id: 0001          # 输入要修改的物料编号
Please enter the new part id: 1001      # 输入新的物料编号
Please enter the new part name: egg     # 输入新的物料名称
Please enter the new part total: 100    # 输入新的物料总数
Please enter the new part used: 12      # 输入新的物料已用数
```
输入要修改的物料编号，系统会查找该物料，如果存在则会显示该物料的信息，然后依次输入新的物料编号、名称、总数，按回车即可修改。如果不存在则会提示修改失败。

##### 2.1.4 物料信息展示
```
┌─────────────────────────────────────── Part List ─────────────────────────────────────────┐
│ID                  	Part Name           	Total               	Used                │
├───────────────────────────────────────────────────────────────────────────────────────────┤
│0001                	tomato              	10                  	1                   │
│0002                	egg                 	100                 	1                   │
│00003               	Test                	10                  	0                   │
│0004                	Test2               	10                  	0                   │
└───────────────────────────────────────────────────────────────────────────────────────────┘
```

#### 2.2 生产计划管理

进入生产计划管理菜单后，会出现如下菜单：

```
┌─────────────── Formula manage ───────────────┐
│ 1. Show all formulas                         │  # 生产计划信息展示
│ 2. Create formula                            │  # 生产计划信息录入
│ 3. Delete formula                            │  # 生产计划信息删除
│ 4. Update formula                            │  # 生产计划信息修改
│ 5. Show formulas details                     │  # 生产计划明细展示
│ 6. Execute formula                           │  # 执行生产计划
│ 0. Back                                      │  # 返回上一级菜单
│ -1. Exit                                     │  # 退出系统
└─────────────── BOM System ───────────────────┘
Please input your choice:
```

##### 2.2.1 生产计划信息录入
```
─────────────── Create Formula ───────────────
Please enter the formula id: F0001           # 输入生产计划编号
Please enter the formula name: TomatoEggs    # 输入生产计划名称，不支持空格和中文
```
依次输入生产计划的编号、名称，按回车即可录入。

##### 2.2.2 生产计划信息删除
```
─────────────── Delete Formula ───────────────
Please enter the formula id: F0001  # 输入要删除的生产计划编号
```

输入要删除的生产计划编号，按回车即可删除。
```
Delete formula success! # 删除成功
Delete formula failed!  # 删除失败
```

##### 2.2.3 生产计划信息修改
```
─────────────── Update Formula ───────────────
Please enter the formula id: F0001            # 输入要修改的生产计划编号
Please enter the new formula id: F1001        # 输入新的生产计划编号
Please enter the new formula name: TomatoEggs # 输入新的生产计划名称
```

输入要修改的生产计划编号，系统会查找该生产计划，如果存在则会显示该生产计划的信息，然后依次输入新的生产计划编号、名称，按回车即可修改。如果不存在则会提示修改失败。

##### 2.2.4 生产计划信息展示
```
┌────────────────────────── Formula List ───────────────────────────┐
│ID                  	Formula Name        	Execute Count       │
├───────────────────────────────────────────────────────────────────┤
│F0001               	MakeTomato          	1                   │
│F0002               	MakeEgg             	2                   │
│F0003               	TomatoEgg           	0                   │
│F0004               	Test                	0                   │
└───────────────────────────────────────────────────────────────────┘
```

##### 2.2.5 生产计划明细展示
```
─────────────── Show Formula Details ───────────────
Please enter the formula id: F0001  # 输入要查看的生产计划编号
```

输入要查看的生产计划编号，系统会查找该生产计划，如果存在则会显示该生产计划的信息，然后会显示该生产计划的明细，如下所示：
```
Formula id: F0003	Formula name: TomatoEgg 
┌───────────────────────── Formula Details ─────────────────────────┐
│ID                  	Part Name           	Count               │
├───────────────────────────────────────────────────────────────────┤
│0001                	tomato              	1                   │
│0002                	egg                 	1                   │
└───────────────────────────────────────────────────────────────────┘

┌────────── Formula details manage ──────────┐
│ 1. Add formula details                     │  # 添加生产计划明细
│ 2. Delete formula details                  │  # 删除生产计划明细
│ 3. Update formula details                  │  # 修改生产计划明细
│ 0. Back                                    │  # 返回上一级菜单
│ -1. Exit                                   │  # 退出系统
└─────────────── BOM System ─────────────────┘
Please input your choice:
```

##### 2.2.6 添加生产计划明细
```
─────────────── Add Formula Details ───────────────
Please enter the formula id: F0001  # 输入要添加明细的生产计划编号
Please enter the part id: 0001      # 输入要添加的物料编号
Please enter the part count: 1      # 输入要添加的物料数量
```

将某个物料添加到某个生产计划中，输入要添加明细的生产计划编号、物料编号、物料数量，按回车即可添加。
在执行生产计划时，系统会根据生产计划明细中的物料数量，从仓库中取出相应的物料，如果物料数量不足则会提示生产计划执行失败。

##### 2.2.7 删除生产计划明细
```
─────────────── Delete Formula Details ───────────────
Please enter the formula id: F0001  # 输入要删除明细的生产计划编号
Please enter the part id: 0001      # 输入要删除的物料编号
```

将某个物料从某个生产计划中删除，输入要删除明细的生产计划编号、物料编号，按回车即可删除。

##### 2.2.8 修改生产计划明细
```
─────────────── Update Formula Details ───────────────
Please enter the formula id: F0001  # 输入要修改明细的生产计划编号
Please enter the part id: 0001      # 输入要修改的物料编号
Please enter the new part count: 2  # 输入新的物料数量
```

将某个生产计划中的某个物料的数量修改，输入要修改明细的生产计划编号、物料编号、新的物料数量，按回车即可修改。
