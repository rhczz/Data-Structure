# 表、栈和队列

## 1.1 抽象数据类型

程序设计的基本法则：例程不应超过一页。这可以通过把程序分割成一些模块来实现。每个模块是一个逻辑单位并执行某些特定的任务，它通过调用其他模块而使本身保持很小。

优点：
1. 调试小程序比调试大程序要容易的多。
2. 多个人同时对一个模块化程序编程要更容易。
3. 一个写得好的模块化程序把某些依赖关系局限在一个例程中，这样使修改更加容易。

抽象数据类型是一些操作的集合。

## 1.2 表（list）

如果表的大小N。我们称大小为0的表为空表（empty list）。

对于除空表外的任何表，我们说A~i+1~后继A~i~(或者继A~i~之后)并称A~i-1~(i<N)前驱A~i~(i>1).

### 1.2.1 表的简单数组实现

对表的所有实现都可以通过数组来实现。虽然数组是动态指定的，但是还是需要对表的大小的最大值进行预估。通常需要估计的稍微大一点，而这会浪费大量的空间。这是严重的局限，特别是在对表存在许多未知情况的表。

对于使用数组实现的表，如果进行要查询某个特定位置的元素则花费的是常数时间。但是如果要对表中的元素进行新增或者删除，则需要花费线性时间。比如要删除第一个元素，则需要后边的每个元素都往前移一个位置，如果要在第一个位置新增一个元素，则需要将后边的元素都往后移动一个位置，才能给这个元素腾出地方。

### 1.2.2 链表

为了避免插入和删除的线性开销，我们允许表可以不连续存储。

链表由一系列不必在内存中相连的结构组成。每个结构都含有表元素和指向该元素的后继元素的结构的指针，称为Next指针。最后一个单元的指针指向NULL。